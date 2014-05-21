$NetBSD$

--- lib/kadm5/logger.c.orig	2013-11-06 20:52:23.000000000 +0000
+++ lib/kadm5/logger.c
@@ -52,6 +52,9 @@
 #ifndef LOG_ERR
 #define LOG_ERR         0
 #endif  /* LOG_ERR */
+#ifndef LOG_PRIMASK
+#define LOG_PRIMASK 7
+#endif
 
 #define lspec_parse_err_1       _("%s: cannot parse <%s>\n")
 #define lspec_parse_err_2       _("%s: warning - logging entry syntax error\n")
