$NetBSD$

--- gio/gdbusmessage.c.orig	2020-09-10 10:42:41.492568576 +0000
+++ gio/gdbusmessage.c
@@ -35,8 +35,12 @@
 #elif MAJOR_IN_TYPES
 #include <sys/types.h>
 #else
+#ifdef __HAIKU__
+#include <SupportDefs.h>
+#else
 #define MAJOR_MINOR_NOT_FOUND 1
 #endif
+#endif
 
 #include "gdbusutils.h"
 #include "gdbusmessage.h"
@@ -3560,8 +3564,14 @@ g_dbus_message_print (GDBusMessage *mess
               if (fstat (fds[n], &statbuf) == 0)
                 {
 #ifndef MAJOR_MINOR_NOT_FOUND                       
+#ifdef __HAIKU__
+                  g_string_append_printf (fs, "%s" "dev=%" B_PRIiDEV, fs->len > 0 ? "," : "",
+                                          statbuf.st_dev);
+#else
+
                   g_string_append_printf (fs, "%s" "dev=%d:%d", fs->len > 0 ? "," : "",
                                           (gint) major (statbuf.st_dev), (gint) minor (statbuf.st_dev));
+#endif
 #endif                  
                   g_string_append_printf (fs, "%s" "mode=0%o", fs->len > 0 ? "," : "",
                                           (guint) statbuf.st_mode);
@@ -3572,9 +3582,14 @@ g_dbus_message_print (GDBusMessage *mess
                   g_string_append_printf (fs, "%s" "gid=%u", fs->len > 0 ? "," : "",
                                           (guint) statbuf.st_gid);
 #ifndef MAJOR_MINOR_NOT_FOUND                     
+#ifdef __HAIKU__
+                  g_string_append_printf (fs, "%s" "rdev=%" B_PRIiDEV, fs->len > 0 ? "," : "",
+                                          statbuf.st_rdev);
+#else
                   g_string_append_printf (fs, "%s" "rdev=%d:%d", fs->len > 0 ? "," : "",
                                           (gint) major (statbuf.st_rdev), (gint) minor (statbuf.st_rdev));
 #endif                  
+#endif
                   g_string_append_printf (fs, "%s" "size=%" G_GUINT64_FORMAT, fs->len > 0 ? "," : "",
                                           (guint64) statbuf.st_size);
                   g_string_append_printf (fs, "%s" "atime=%" G_GUINT64_FORMAT, fs->len > 0 ? "," : "",
