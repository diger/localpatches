$NetBSD$

--- tools/build/v2/engine/fileunix.c.orig	2014-06-02 10:38:01.466616320 +0000
+++ tools/build/v2/engine/fileunix.c
@@ -80,7 +80,7 @@ struct ar_hdr  /* archive file member he
 };
 #endif
 
-#if defined( OS_QNX ) || defined( OS_BEOS ) || defined( OS_MPEIX )
+#if defined( OS_QNX ) || defined( OS_BEOS ) || defined( OS_HAIKU ) || defined( OS_MPEIX )
 # define NO_AR
 # define HAVE_AR
 #endif
