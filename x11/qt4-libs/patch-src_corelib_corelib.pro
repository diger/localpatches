$NetBSD$

--- src/corelib/corelib.pro.orig	2013-06-07 05:16:52.066846720 +0000
+++ src/corelib/corelib.pro
@@ -29,6 +29,7 @@ qpa:mac {
 }
 mac:lib_bundle:DEFINES += QT_NO_DEBUG_PLUGIN_CHECK
 win32:DEFINES-=QT_NO_CAST_TO_ASCII
+haiku:DEFINES += QT_NO_SHAREDMEMORY
 
 QMAKE_LIBS += $$QMAKE_LIBS_CORE
 
@@ -47,3 +48,7 @@ symbian: {
     MMP_RULES += pagingBlock
     LIBS += -ltzclient
 }
+
+haiku: {
+	LIBS_PRIVATE += -lbe
+}
