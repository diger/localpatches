$NetBSD$

--- test-betoh64.c.orig	2013-12-30 19:27:50.040632320 +0000
+++ test-betoh64.c
@@ -1,6 +1,9 @@
 #include <sys/types.h>
 
-#if defined(__linux__)
+#if defined(__HAIKU__)
+#include <stdint.h>
+#endif
+#if defined(__linux__) || defined(__HAIKU__)
 # include <endian.h>
 #elif defined(__APPLE__)
 # include <libkern/OSByteOrder.h>
