$NetBSD$

--- src/gui/util/qsystemtrayicon_haiku.cpp.orig	2014-07-03 10:34:03.306184192 +0000
+++ src/gui/util/qsystemtrayicon_haiku.cpp
@@ -0,0 +1,503 @@
+/****************************************************************************
+**
+** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
+** All rights reserved.
+** Contact: Nokia Corporation (qt-info@nokia.com)
+**
+** This file is part of the QtGui module of the Qt Toolkit.
+**
+** $QT_BEGIN_LICENSE:LGPL$
+** No Commercial Usage
+** This file contains pre-release code and may not be distributed.
+** You may use this file in accordance with the terms and conditions
+** contained in the Technology Preview License Agreement accompanying
+** this package.
+**
+** GNU Lesser General Public License Usage
+** Alternatively, this file may be used under the terms of the GNU Lesser
+** General Public License version 2.1 as published by the Free Software
+** Foundation and appearing in the file LICENSE.LGPL included in the
+** packaging of this file.  Please review the following information to
+** ensure the GNU Lesser General Public License version 2.1 requirements
+** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
+**
+** In addition, as a special exception, Nokia gives you certain additional
+** rights.  These rights are described in the Nokia Qt LGPL Exception
+** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
+**
+** If you have questions regarding the use of this file, please contact
+** Nokia at qt-info@nokia.com.
+**
+**
+**
+**
+**
+**
+**
+**
+** $QT_END_LICENSE$
+**
+****************************************************************************/
+
+#include "qsystemtrayicon_p.h"
+
+#ifndef QT_NO_SYSTEMTRAYICON
+
+QT_BEGIN_NAMESPACE
+
+#include "qapplication.h"
+#include "qsystemtrayicon.h"
+#include "qdebug.h"
+#include "qcolor.h"
+#include "qfileinfo.h"
+
+#include <OS.h>
+#include <Application.h>
+#include <Window.h>
+#include <Message.h>
+#include <Deskbar.h>
+#include <View.h>
+#include <String.h>
+#include <Roster.h>
+#include <Screen.h>
+#include <Resources.h>
+#include <Bitmap.h>
+#include <Looper.h>
+#include <Notification.h>
+
+#include <stdlib.h>
+#include <string.h>
+#include <stdio.h>
+
+enum notify_mode {
+		NM_NONE,
+		NM_QT,
+		NM_NATIVE
+};
+
+#define maxTipLength 	128
+
+#define REPL_NAME		"QtTrayItem"
+#define DBAR_SIGNATURE 	"application/x-vnd.Be-TSKB"
+
+static 	notify_mode notifyMode = NM_NATIVE;
+
+DeskbarView::DeskbarView(team_id tid) : BView(BRect(0,0,15,15), REPL_NAME,B_FOLLOW_NONE,B_WILL_DRAW)
+{
+	id = -1;
+	team = tid;
+	ticks = 0;
+	icon = NULL;
+	traysysobject = NULL;
+	lastButtons = 0;
+}
+
+DeskbarView::DeskbarView(BMessage *message) : BView(message)
+{
+	const void* data;
+	ssize_t numBytes;
+	message->FindData("color",B_ANY_TYPE,&data,&numBytes);	
+	color = *((rgb_color*)data);
+	message->FindData("team",B_ANY_TYPE,&data,&numBytes);
+	team = *((team_id*)data);
+	id = -1;
+	ticks = 0;
+	icon = NULL;
+	traysysobject = NULL;	
+	lastButtons = 0;
+}
+
+DeskbarView *DeskbarView::Instantiate(BMessage *data) {
+	if (!validate_instantiation(data, REPL_NAME)) return NULL;
+	return new DeskbarView(data);
+}
+
+status_t DeskbarView::Archive(BMessage *data, bool deep) const {
+	BView::Archive(data, deep);
+	data->AddString("add_on", DBAR_SIGNATURE);
+	data->AddString("class", REPL_NAME);
+	
+	data->AddData("color",B_ANY_TYPE,&color,sizeof(rgb_color));
+	data->AddData("team",B_ANY_TYPE,&team,sizeof(team_id));
+	return B_OK;
+}		
+
+void DeskbarView::AttachedToWindow()
+{
+	ticks = 0;	
+	BMessage* tickMsg = new BMessage('LIVE');
+	BMessageRunner *runner = new BMessageRunner( this, tickMsg, 1000000 );
+	color = Parent()->ViewColor();	
+	BView::AttachedToWindow();
+}
+
+void DeskbarView::Draw(BRect r)
+{
+	SetDrawingMode(B_OP_COPY);
+	SetHighColor(Parent()->ViewColor());
+	FillRect(Bounds());
+	if(ticks>3 && !icon) {
+		SetHighColor(32,32,32,100);			
+		SetDrawingMode(B_OP_ALPHA);
+		DrawChar('?',BPoint(4,12));
+	}
+	if(icon) {
+		float dx = (Bounds().Width() - icon->Bounds().Width())/2;
+		float dy = (Bounds().Height() - icon->Bounds().Height())/2;
+		SetDrawingMode(B_OP_ALPHA);		
+		DrawBitmap(icon,BPoint(dx,dy));
+	}
+}
+
+void DeskbarView::MouseMoved(BPoint point, uint32 transit,const BMessage *message)
+{
+}
+
+void DeskbarView::MouseUp(BPoint point)
+{
+   uint32 buttons = lastButtons;
+   
+   BMessage *mes = new BMessage('TRAY');
+   mes->AddInt32("event",TRAY_MOUSEUP);
+   mes->AddPoint("point",ConvertToScreen(point));
+   mes->AddInt32("buttons",buttons);
+   mes->AddInt32("clicks",1);
+   mes->AddData("qtrayobject",B_ANY_TYPE,&traysysobject,sizeof(void*));
+   ReplyMessenger.SendMessage(mes);
+   
+}
+
+void DeskbarView::MouseDown(BPoint point)
+{
+   uint32 buttons = Window()->CurrentMessage()->FindInt32("buttons");
+   int32 clicks = Window()->CurrentMessage()->FindInt32("clicks");
+   lastButtons = buttons;
+   
+   BMessage *mes = new BMessage('TRAY');
+   mes->AddInt32("event",TRAY_MOUSEDOWN);
+   mes->AddPoint("point",ConvertToScreen(point));
+   mes->AddInt32("buttons",buttons);
+   mes->AddInt32("clicks",clicks);
+   mes->AddData("qtrayobject",B_ANY_TYPE,&traysysobject,sizeof(void*));
+   ReplyMessenger.SendMessage(mes);
+   
+}
+
+void DeskbarView::MessageReceived(BMessage *message) {
+//	message->PrintToStream();
+	switch (message->what)
+	{
+		case 'LIVE':
+			{
+				ticks++;				
+				Invalidate();
+				team_info teamInfo;
+				status_t error = get_team_info(team, &teamInfo);
+				if (error != B_OK && id>0) {
+					BDeskbar deskbar;
+					deskbar.RemoveItem(id);
+				} else {
+					BMessage *mes=new BMessage(*message);
+					mes->AddRect("rect",ConvertToScreen(Bounds()));
+					ReplyMessenger.SendMessage(mes);
+				}
+				break;
+			}
+		case B_SET_PROPERTY:
+			{
+				switch( message->FindInt32("what2") ) {
+					case 'TTIP':
+						{							
+							const char *tip=NULL;
+							status_t res = message->FindString("tooltip",&tip);
+							
+							if(!tip || res!=B_OK)
+								tip = applicationName.String();
+							if(strlen(tip)==0)
+								tip = applicationName.String();													
+							if(strlen(tip)!=0)		
+								SetToolTip(tip);
+								
+							break;
+						}					
+					case 'BITS':
+						{
+							BBitmap *oldicon=icon;
+							icon=NULL;
+							delete oldicon;
+							BMessage bits;
+							message->FindMessage("icon", &bits);
+							icon = new BBitmap(&bits);
+							bits.MakeEmpty();
+							Invalidate();
+							break;
+						}
+					case '_ID_':
+						{
+							message->FindInt32("ReplicantID",&id);
+							break;
+						}
+					case 'MSGR':
+						{
+							ssize_t numBytes;
+							const char *name=NULL;
+							message->FindMessenger("messenger", &ReplyMessenger);
+							message->FindData("qtrayobject",B_ANY_TYPE,&traysysobject,&numBytes);
+							if(message->FindString("application_name",&name)==B_OK)
+								applicationName.SetTo(name);
+							break;
+						}
+				}
+			}
+			break;		
+		default:
+			BView::MessageReceived(message);
+			break;
+	}
+}
+
+DeskbarView::~DeskbarView()
+{
+ 
+}
+
+void QSystemTrayIconSys::UpdateTooltip()
+{   	
+    QString tip = q->toolTip();
+
+    BString tipStr("");
+    
+    if (!tip.isNull()) {
+    	tip = tip.left(maxTipLength - 1) + QChar();        
+    	const char *str = (const char *)(tip.toUtf8());
+    	tipStr.SetTo(str);
+    }
+	
+	BMessage *mes = new BMessage('TTIP');		
+	mes->AddString("tooltip",tipStr.String());	
+	SendMessageToReplicant(mes);
+}
+
+void QSystemTrayIconSys::UpdateIcon()
+{    
+    QIcon qicon = q->icon();
+    if (qicon.isNull())
+        return;
+
+    QSize size = qicon.actualSize(QSize(16, 16));
+    QPixmap pm = qicon.pixmap(size);
+    if (pm.isNull())
+        return;
+	
+	BBitmap *icon = pm.toHaikuBitmap();
+	if(icon) {
+		BMessage	bits(B_ARCHIVED_OBJECT);
+		icon->Archive(&bits);	
+		BMessage *mes = new BMessage('BITS');
+		mes->AddMessage("icon",&bits);
+		bits.MakeEmpty();
+		SendMessageToReplicant(mes);
+		delete icon;
+	}	
+	UpdateTooltip();
+}
+
+BMessenger GetMessenger(void)
+{
+	BMessenger aResult;
+	status_t aErr = B_OK;
+	BMessenger aDeskbar(DBAR_SIGNATURE, -1, &aErr);
+	if (aErr != B_OK)return aResult;
+
+	BMessage aMessage(B_GET_PROPERTY);
+	
+	aMessage.AddSpecifier("Messenger");
+	aMessage.AddSpecifier("Shelf");
+	aMessage.AddSpecifier("View", "Status");
+	aMessage.AddSpecifier("Window", "Deskbar");
+	
+	BMessage aReply;
+
+	if (aDeskbar.SendMessage(&aMessage, &aReply, 1000000, 1000000) == B_OK)
+		aReply.FindMessenger("result", &aResult);
+	return aResult;
+}
+
+status_t SendMessageToReplicant(int32 index, BMessage *msg)
+{
+	BMessage aReply;
+	status_t aErr = B_OK;
+	
+	msg->AddInt32( "what2", msg->what );
+	msg->what = B_SET_PROPERTY;
+
+	BMessage	uid_specifier(B_ID_SPECIFIER);
+	
+	msg->AddSpecifier("View");
+	uid_specifier.AddInt32("id", index);
+	uid_specifier.AddString("property", "Replicant");
+	msg->AddSpecifier(&uid_specifier);
+		
+	aErr = GetMessenger().SendMessage( msg, (BHandler*)NULL, 1000000 );
+	return aErr;
+}
+
+int32	
+QSystemTrayIconSys::ExecuteCommand(char *command)
+{
+   FILE *fpipe;
+   char line[256];
+   if ( !(fpipe = (FILE*)popen(command,"r")) )
+   		return -1;
+
+   fgets( line, sizeof line, fpipe);
+   pclose(fpipe);
+   
+   int res = atoi(line);
+   return res;
+}
+
+int32 LoadIcon(team_id tid)
+{
+	BDeskbar deskbar;
+	int32 id=-1;
+
+	deskbar.AddItem(new DeskbarView(tid),&id);
+	
+	if(id>0) {
+		BMessage msg('_ID_');
+		msg.AddInt32("ReplicantID",id);
+		SendMessageToReplicant(id,&msg);
+	}
+	
+	return id;	
+}
+
+int32 LoadIcon(void)
+{
+	thread_info threadInfo;
+	status_t error = get_thread_info(find_thread(NULL), &threadInfo);
+	if (error != B_OK) {
+		return 0;
+	}
+	team_id sTeam = threadInfo.team;
+	
+	return LoadIcon(sTeam);
+}
+
+void RemoveIcon(int32 id)
+{
+	BDeskbar deskbar;
+	deskbar.RemoveItem(id);
+}
+
+void QSystemTrayIconPrivate::install_sys()
+{
+    Q_Q(QSystemTrayIcon);
+    if (!sys) {
+        sys = new QSystemTrayIconSys(q);		
+        sys->UpdateIcon();
+    }
+    supportsMessages_sys();    
+}
+
+void QSystemTrayIconPrivate::showMessage_sys(const QString &title,  const QString &message, QSystemTrayIcon::MessageIcon type, int timeOut)
+{
+	if(notifyMode == NM_QT) {
+		QPoint point(sys->shelfRect.x(),sys->shelfRect.y());
+				
+		BDeskbar deskbar;
+		BRect deskRect = deskbar.Frame();
+		BScreen  screen(B_MAIN_SCREEN_ID);
+		
+		switch(deskbar.Location())
+		{
+			case B_DESKBAR_TOP:
+				point.setX(screen.Frame().Width()-8);
+				point.setY(deskRect.Height()+8);
+				break;
+			case B_DESKBAR_RIGHT_TOP:		
+				point.setX(screen.Frame().Width()-deskRect.Width()-8);
+				point.setY(8);
+				break;
+			case B_DESKBAR_BOTTOM:
+				point.setX(screen.Frame().Width()-8);
+				point.setY(screen.Frame().Height()-deskRect.Height()-8);
+				break;	
+			case B_DESKBAR_LEFT_BOTTOM:
+				point.setX(deskRect.Width()+8);
+				point.setY(screen.Frame().Height()-8);
+				break;				
+			case B_DESKBAR_RIGHT_BOTTOM:		
+				point.setX(deskRect.Width()-deskRect.Width()-8);
+				point.setY(screen.Frame().Height()-8);
+				break;				
+			case B_DESKBAR_LEFT_TOP:
+				point.setX(deskRect.Width()+8);
+				point.setY(8);
+				break;				
+		}
+	    QBalloonTip::showBalloon(type, title, message, sys->q, point, timeOut, false);
+	}
+	if(notifyMode == NM_NATIVE) {	
+		BString stitle((const char *)(title.toUtf8()));
+		BString smessage((const char *)(message.toUtf8()));
+		BString smessageId((const char *)(QFileInfo(QApplication::applicationFilePath()).fileName().toUtf8()));
+		
+		notification_type ntype = type==QSystemTrayIcon::Warning?B_IMPORTANT_NOTIFICATION:
+								   type==QSystemTrayIcon::Critical?B_ERROR_NOTIFICATION:B_INFORMATION_NOTIFICATION;
+		BNotification notification(ntype);
+		//notification.SetGroup("");
+		notification.SetTitle(stitle);
+		notification.SetMessageID(smessageId);
+		notification.SetContent(smessage);
+		notification.Send(timeOut/1000);
+	}
+}
+
+QRect QSystemTrayIconPrivate::geometry_sys() const
+{
+	return sys->shelfRect;
+}
+
+void QSystemTrayIconPrivate::remove_sys()
+{
+	if(sys) {    
+    	delete sys;
+    	sys = NULL;
+	}
+}
+
+void QSystemTrayIconPrivate::updateIcon_sys()
+{
+    if (sys) {
+	    sys->UpdateIcon();
+    }
+}
+
+void QSystemTrayIconPrivate::updateMenu_sys()
+{
+	fprintf(stderr, "Unimplemented:  QSystemTrayIconPrivate::updateMenu_sys\n");	
+}
+
+void QSystemTrayIconPrivate::updateToolTip_sys()
+{
+	if (sys) {
+		sys->UpdateTooltip();
+	}
+}
+
+bool QSystemTrayIconPrivate::isSystemTrayAvailable_sys()
+{	
+	return true;
+}
+
+bool QSystemTrayIconPrivate::supportsMessages_sys()
+{
+	return notifyMode != NM_NONE;
+}
+
+QT_END_NAMESPACE
+
+#endif // QT_NO_SYSTEMTRAYICON
+
