$NetBSD$

--- tools/build/v2/engine/jam.h.orig	2014-06-02 10:26:03.000000000 +0000
+++ tools/build/v2/engine/jam.h
@@ -125,6 +125,11 @@
     #define OS_BEOS
     #define NO_VFORK
 #endif
+#ifdef __HAIKU__
+    #define unix
+    #define OSMINOR "OS=HAIKU"
+    #define OS_HAIKU
+#endif
 #ifdef __bsdi__
     #define OSMINOR "OS=BSDI"
     #define OS_BSDI
