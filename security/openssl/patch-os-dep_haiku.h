$NetBSD$

--- os-dep/haiku.h.orig	2020-09-22 12:55:07.788004864 +0000
+++ os-dep/haiku.h
@@ -1,2 +1,4 @@
 #include <sys/select.h>
 #include <sys/time.h>
+
+#define OPENSSL_NO_SECURE_MEMORY
