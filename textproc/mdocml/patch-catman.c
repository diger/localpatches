$NetBSD$

--- catman.c.orig	2014-05-19 03:03:56.000000000 +0000
+++ catman.c
@@ -31,6 +31,10 @@
 #include <string.h>
 #include <unistd.h>
 
+#if defined(__HAIKU__)
+#include <stdint.h>
+#endif
+
 #if defined(__linux__) || defined(__sun)
 # include <db_185.h>
 #else
