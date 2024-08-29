egrep: warning: egrep is obsolescent; using grep -E
$NetBSD$

--- src/os/unix/ngx_errno.c.orig	2023-04-11 01:45:34.012058624 +0000
+++ src/os/unix/ngx_errno.c
@@ -9,6 +9,7 @@
 #include <ngx_core.h>
 
 
+#if !(NGX_HAIKU)
 static ngx_str_t   ngx_unknown_error = ngx_string("Unknown error");
 
 
@@ -208,3 +209,5 @@ failed:
 }
 
 #endif
+
+#endif
