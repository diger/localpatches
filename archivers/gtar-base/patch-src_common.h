$NetBSD$

--- src/common.h.orig	2019-01-02 18:07:47.043515904 +0000
+++ src/common.h
@@ -197,6 +197,8 @@ GLOBAL enum old_files old_files_option;
 
 GLOBAL bool keep_directory_symlink_option;
 
+GLOBAL bool simulate_hardlinks_option;
+
 /* Specified file name for incremental list.  */
 GLOBAL const char *listed_incremental_option;
 /* Incremental dump level */
