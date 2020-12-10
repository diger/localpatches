$NetBSD$

--- lib/rpc/bindresvport.c.orig	2020-12-10 09:08:47.421527552 +0000
+++ lib/rpc/bindresvport.c
@@ -37,7 +37,11 @@
 #include <stdint.h>
 #include <unistd.h>
 #include <sys/types.h>
+#ifdef __HAIKU__
+#include <errno.h>
+#else
 #include <sys/errno.h>
+#endif
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <gssrpc/rpc.h>
