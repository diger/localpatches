$NetBSD$

--- login-utils/logindefs.c.orig	2018-06-04 07:57:02.788004864 +0000
+++ login-utils/logindefs.c
@@ -26,7 +26,11 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#include <sys/syslog.h>
+#ifndef __HAIKU__
+ #include <sys/syslog.h>
+#else
+ #include <posix/syslog.h>
+#endif
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <pwd.h>
