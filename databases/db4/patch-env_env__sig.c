$NetBSD$

--- env/env_sig.c.orig	2014-07-31 19:05:56.013631488 +0000
+++ env/env_sig.c
@@ -5,5 +5,5 @@
  */
 
-#if !defined(u_int64_t)
+#if !defined(u_int64_t) && !defined(__HAIKU__)
 typedef unsigned long long u_int64_t;
 #endif
