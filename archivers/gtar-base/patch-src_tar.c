$NetBSD$

--- src/tar.c.orig	2019-01-02 18:07:48.042991616 +0000
+++ src/tar.c
@@ -449,6 +449,8 @@ static struct argp_option options[] = {
   {"check-device", CHECK_DEVICE_OPTION, NULL, 0,
    N_("check device numbers when creating incremental archives (default)"),
    GRID+1 },
+  {"replace-hardlinks", 'Q', 0, 0,
+   N_("replace hardlinks with corresponding symlink when extracting"), GRID+1 },
 #undef GRID
 
 #define GRID 30
@@ -1728,6 +1730,10 @@ parse_opt (int key, char *arg, struct ar
       set_archive_format (arg);
       break;
 
+    case 'Q':
+      simulate_hardlinks_option = true;
+      break;
+
     case INDEX_FILE_OPTION:
       index_file_name = arg;
       break;
@@ -2245,6 +2251,7 @@ decode_options (int argc, char **argv)
   unquote_option = true;
   tar_sparse_major = 1;
   tar_sparse_minor = 0;
+  simulate_hardlinks_option = false;
 
   savedir_sort_order = SAVEDIR_SORT_NONE;
 
