$NetBSD: patch-gio_gunixmounts.c,v 1.5 2019/06/06 11:05:12 adam Exp $

SunOS has sys/mntent.h but no mnt_opts.
XXX who else uses the sys/mntent.h case?
https://gitlab.gnome.org/GNOME/glib/merge_requests/890

--- gio/gunixmounts.c.orig	2020-11-24 14:09:34.990380032 +0000
+++ gio/gunixmounts.c
@@ -955,7 +955,18 @@ _g_get_unix_mounts (void)
 
   return return_list;
 }
+#elif defined(__HAIKU__)
+static char *
+get_mtab_monitor_file (void)
+{
+  return NULL;
+}
 
+static GList *
+_g_get_unix_mounts (void)
+{
+  return NULL;
+}
 /* Common code {{{2 */
 #else
 #error No _g_get_unix_mounts() implementation for system
@@ -1471,8 +1482,8 @@ _g_get_unix_mount_points (void)
   
   return g_list_reverse (return_list);
 }
-/* Interix {{{2 */
-#elif defined(__INTERIX)
+/* Interix, Haiku {{{2 */
+#elif defined(__INTERIX) || defined(__HAIKU__)
 static GList *
 _g_get_unix_mount_points (void)
 {
