$NetBSD$

--- gio/xdgmime/xdgmime.c.orig	2024-05-16 05:38:06.679739392 +0000
+++ gio/xdgmime/xdgmime.c
@@ -29,6 +29,11 @@
 #include <unistd.h>
 #include <assert.h>
 
+#if defined(__HAIKU__)
+#include <FindDirectory.h>
+#include <fs_info.h>
+#endif
+
 #ifndef S_ISREG
 #define S_ISREG(m) (((m) & _S_IFMT) == _S_IFREG)
 #endif
@@ -223,6 +228,23 @@ xdg_init_dirs (void)
 
   assert (xdg_dirs == NULL);
 
+#ifdef __HAIKU__
+  current_dir = 0;
+  xdg_dirs = calloc (2, sizeof (char *));
+
+  char path[B_PATH_NAME_LENGTH + B_FILE_NAME_LENGTH];
+  dev_t volume = dev_for_path("/boot");
+  if (find_directory(B_SYSTEM_DATA_DIRECTORY, volume, false, path, sizeof(path)) == B_OK)
+    {
+      xdg_data_dirs = strdup(path);
+      strcat (xdg_data_dirs, "/mime/");
+    }
+  else
+    {
+      xdg_data_dirs = strdup("/system/data/mime/");
+    }
+  xdg_dirs[current_dir++] = xdg_data_dirs;
+#else
   xdg_data_home = getenv ("XDG_DATA_HOME");
   home = getenv ("HOME");
   xdg_data_dirs = getenv ("XDG_DATA_DIRS");
@@ -295,7 +317,7 @@ xdg_init_dirs (void)
 
       ptr = end_ptr;
     }
-
+#endif
   /* NULL terminator */
   xdg_dirs[current_dir] = NULL;
 
