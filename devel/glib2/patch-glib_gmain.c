$NetBSD$

--- glib/gmain.c.orig	2014-06-02 04:58:59.603979776 +0000
+++ glib/gmain.c
@@ -73,10 +73,10 @@
 #include <windows.h>
 #endif /* G_OS_WIN32 */
 
-#ifdef G_OS_BEOS
+#if defined(G_OS_BEOS) || defined(G_PLATFORM_HAIKU)
 #include <sys/socket.h>
 #include <sys/wait.h>
-#endif /* G_OS_BEOS */
+#endif /* G_OS_BEOS & G_PLATFORM_HAIKU */
 
 #include "gmain.h"
 
