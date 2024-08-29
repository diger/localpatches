$NetBSD$

--- gio/kqueue/gkqueuefilemonitor.c.orig	2024-07-08 04:54:12.908591104 +0000
+++ gio/kqueue/gkqueuefilemonitor.c
@@ -36,6 +36,16 @@
 #define O_CLOEXEC 0
 #endif
 
+#ifdef __HAIKU__
+#define NOTE_DELETE  NOTE_EXIT
+#define NOTE_WRITE   NOTE_EXIT
+#define NOTE_EXTEND  NOTE_EXIT
+#define EVFILT_VNODE EVFILT_READ
+#define	NOTE_ATTRIB	 0x80000000
+#define	NOTE_RENAME	 0x80000000
+#define	NOTE_REVOKE	 0x80000000
+#endif
+
 #include <glib-object.h>
 #include <glib/gfileutils.h>
 #include <gio/gfilemonitor.h>
