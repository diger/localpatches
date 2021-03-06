$NetBSD$

--- src/common.h.orig	2020-12-04 16:39:10.414449664 +0000
+++ src/common.h
@@ -35,6 +35,28 @@
 #include <stdlib.h>
 #include <string.h>
 
+#ifdef __HAIKU__
+#include <os/support/Errors.h>
+#define ERR_NULL                1
+#define ERR_MEMORY              2
+#define ERR_NOT_ENOUGH_DATA     3
+#define ERR_ENCRYPT             4
+#define ERR_DECRYPT             5
+#define ERR_KEY_SIZE            6
+#define ERR_NONCE_SIZE          7
+#define ERR_NR_ROUNDS           8
+#define ERR_DIGEST_SIZE         9
+#define ERR_MAX_DATA            10
+#define ERR_MAX_OFFSET          11
+#define ERR_BLOCK_SIZE          12
+#define ERR_TAG_SIZE            13
+#define ERR_VALUE               14
+#define ERR_EC_POINT            15
+#define ERR_EC_CURVE            16
+#define ERR_MODULUS             17
+#define ERR_UNKNOWN             32
+#endif
+
 #include "errors.h"
 
 /*
