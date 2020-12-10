$NetBSD$

--- lib/rpc/clnt_generic.c.orig	2020-12-10 09:11:20.638582784 +0000
+++ lib/rpc/clnt_generic.c
@@ -40,7 +40,11 @@ static char sccsid[] = "@(#)clnt_generic
 #include <string.h>
 #include <gssrpc/rpc.h>
 #include <sys/socket.h>
+#ifdef __HAIKU__
+#include <errno.h>
+#else
 #include <sys/errno.h>
+#endif
 #include <netdb.h>
 
 /*
