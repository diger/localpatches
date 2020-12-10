$NetBSD$

--- lib/rpc/auth_gssapi.c.orig	2020-12-10 09:06:15.060293120 +0000
+++ lib/rpc/auth_gssapi.c
@@ -5,7 +5,11 @@
 
 #include <stdio.h>
 #include <string.h>
+#ifdef __HAIKU__
+#include <errno.h>
+#else
 #include <sys/errno.h>
+#endif
 
 #include <gssapi/gssapi.h>
 #include <gssapi/gssapi_generic.h>
