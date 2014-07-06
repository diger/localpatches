$NetBSD$

--- src/gui/kernel/haiku.pri.orig	2014-07-03 10:34:03.214171648 +0000
+++ src/gui/kernel/haiku.pri
@@ -0,0 +1,2 @@
+DEFINES += QT_NO_FONTCONFIG
+LIBS_PRIVATE += -lbe
