$NetBSD$

--- lib/rpc/pmap_rmt.c.orig	2020-12-10 09:14:03.855900160 +0000
+++ lib/rpc/pmap_rmt.c
@@ -48,7 +48,7 @@ static char sccsid[] = "@(#)pmap_rmt.c 1
 #include <gssrpc/pmap_clnt.h>
 #include <gssrpc/pmap_rmt.h>
 #include <sys/socket.h>
-#ifdef sun
+#if defined(sun) || defined(__HAIKU__)
 #include <sys/sockio.h>
 #endif
 #ifdef OSF1
