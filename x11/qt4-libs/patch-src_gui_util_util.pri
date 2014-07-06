$NetBSD$

--- src/gui/util/util.pri.orig	2013-06-07 05:16:59.033816576 +0000
+++ src/gui/util/util.pri
@@ -59,3 +59,10 @@ symbian {
 
     LIBS += -ldirectorylocalizer
 }
+
+haiku {
+		HEADERS += \
+				util/qsystemtrayicon_haiku.h
+		SOURCES += \
+				util/qsystemtrayicon_haiku.cpp
+    }
