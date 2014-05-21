$NetBSD$

--- include/db.h.orig	2014-05-21 04:09:02.000000000 +0000
+++ include/db.h
@@ -40,6 +40,10 @@
 
 #include <sys/types.h>
 
+#ifdef __HAIKU__
+#include <stdint.h>
+#endif
+
 #define	RET_ERROR	-1		/* Return values. */
 #define	RET_SUCCESS	 0
 #define	RET_SPECIAL	 1
