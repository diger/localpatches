$NetBSD: patch-lib_randutils.c,v 1.5 2017/12/08 08:03:35 adam Exp $

O_CLOEXEC is not available on every platform (e.g. MacOS X < 10.7). It
was introduced in POSIX 2008.

--- lib/randutils.c.orig	2020-11-23 09:03:25.788004864 +0000
+++ lib/randutils.c
@@ -13,7 +13,9 @@
 #include <string.h>
 #include <sys/time.h>
 
-#include <sys/syscall.h>
+#ifndef __HAIKU__
+ #include <sys/syscall.h>
+#endif
 
 #include "c.h"
 #include "randutils.h"
