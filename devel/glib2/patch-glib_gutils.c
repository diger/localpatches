$NetBSD$

--- glib/gutils.c.orig	2020-09-10 10:42:41.624689152 +0000
+++ glib/gutils.c
@@ -75,6 +75,10 @@
 #include "gwin32.h"
 #endif
 
+#if defined(__HAIKU__)
+#include <FindDirectory.h>
+#include <fs_info.h>
+#endif
 
 /**
  * SECTION:misc_utils
@@ -994,7 +998,11 @@ g_get_host_name (void)
       gchar *tmp;
 
 #ifdef _SC_HOST_NAME_MAX
-      max = sysconf (_SC_HOST_NAME_MAX);
+      #ifdef __HAIKU__
+	    max = 0;
+      #else
+        max = sysconf (_SC_HOST_NAME_MAX);
+       #endif
       if (max > 0 && max <= G_MAXSIZE - 1)
         size = (gsize) max + 1;
       else
@@ -1943,6 +1951,35 @@ load_user_special_dirs (void)
   load_user_special_dirs_macos (g_user_special_dirs);
 }
 
+#elif defined(__HAIKU__)
+static void
+load_user_special_dirs (void)
+{
+  char path[B_PATH_NAME_LENGTH + B_FILE_NAME_LENGTH];
+
+  dev_t volume = dev_for_path("/boot");
+  if (find_directory(B_DESKTOP_DIRECTORY, volume, false, path, sizeof(path))
+      == B_OK) {
+    g_user_special_dirs[G_USER_DIRECTORY_DESKTOP] = g_strdup(path);
+    g_user_special_dirs[G_USER_DIRECTORY_DOWNLOAD] = g_strdup(path);
+  } else {
+    g_user_special_dirs[G_USER_DIRECTORY_DOCUMENTS] = NULL;
+    g_user_special_dirs[G_USER_DIRECTORY_DESKTOP] = NULL;
+  }
+
+  if (find_directory(B_USER_DIRECTORY, volume, false, path, sizeof(path))
+      == B_OK) {
+    g_user_special_dirs[G_USER_DIRECTORY_DOCUMENTS] = g_strdup(path);
+  } else
+    g_user_special_dirs[G_USER_DIRECTORY_DOWNLOAD] = NULL;
+
+  g_user_special_dirs[G_USER_DIRECTORY_MUSIC] = NULL;
+  g_user_special_dirs[G_USER_DIRECTORY_PICTURES] = NULL;
+  g_user_special_dirs[G_USER_DIRECTORY_PUBLIC_SHARE] = NULL;
+  g_user_special_dirs[G_USER_DIRECTORY_TEMPLATES] = NULL;
+  g_user_special_dirs[G_USER_DIRECTORY_VIDEOS] = NULL;
+}
+
 #elif defined(G_OS_WIN32)
 
 static void
