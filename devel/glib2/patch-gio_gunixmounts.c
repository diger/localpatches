$NetBSD$

--- gio/gunixmounts.c.orig	2014-06-02 05:10:30.186908672 +0000
+++ gio/gunixmounts.c
@@ -733,6 +733,21 @@ _g_get_unix_mounts (void)
 
   return return_list;
 }
+#elif defined(G_PLATFORM_HAIKU)
+
+static char *
+get_mtab_monitor_file (void)
+{
+return NULL;
+}
+
+static GList *
+_g_get_unix_mounts (void)
+{
+/* TODO: implement me */
+  GList *return_list = NULL;
+  return return_list;
+}
 #else
 #error No _g_get_unix_mounts() implementation for system
 #endif
@@ -1129,6 +1144,14 @@ _g_get_unix_mount_points (void)
 {
   return _g_get_unix_mounts ();
 }
+#elif defined(G_PLATFORM_HAIKU)
+
+static GList *
+_g_get_unix_mount_points (void)
+{
+  GList *return_list = NULL;
+  return return_list;
+}
 #else
 #error No g_get_mount_table() implementation for system
 #endif
