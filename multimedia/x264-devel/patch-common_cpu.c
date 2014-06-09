$NetBSD$

--- common/cpu.c.orig	2014-06-08 17:00:19.050855936 +0000
+++ common/cpu.c
@@ -29,10 +29,10 @@
 #include "common.h"
 #include "cpu.h"
 
-#if HAVE_POSIXTHREAD && SYS_LINUX
+#if HAVE_POSIXTHREAD && SYS_LINUX || SYS_HAIKU
 #include <sched.h>
 #endif
-#if SYS_BEOS
+#if SYS_BEOS || SYS_HAIKU
 #include <kernel/OS.h>
 #endif
 #if SYS_MACOSX || SYS_FREEBSD
