$NetBSD: patch-include_c.h,v 1.1 2018/01/02 10:24:06 jperkin Exp $

Add NAME_MAX compat.

--- include/c.h.orig	2020-11-23 09:03:22.788004864 +0000
+++ include/c.h
@@ -33,6 +33,10 @@
 # define NAME_MAX PATH_MAX
 #endif
 
+#ifndef _SC_HOST_NAME_MAX
+#define _SC_HOST_NAME_MAX 72
+#endif
+
 /*
  * Compiler-specific stuff
  */
