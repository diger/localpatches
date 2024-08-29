$NetBSD$

--- glib/tests/mapping.c.orig	2024-03-07 21:35:05.009961472 +0000
+++ glib/tests/mapping.c
@@ -191,6 +191,10 @@ test_private (void)
   g_remove ("maptest");
 }
 
+#ifdef __HAIKU__
+#include <SupportDefs.h>
+#endif
+
 static void
 test_child_private (void)
 {
@@ -223,7 +227,12 @@ test_child_private (void)
   signal (SIGUSR1, handle_usr1);
 #endif
 
+#ifdef __HAIKU__
+  g_snprintf (pid, sizeof(pid), B_PRId32, getpid ());
+#else
   g_snprintf (pid, sizeof(pid), "%d", getpid ());
+#endif
+
   child_argv[0] = local_argv[0];
   child_argv[1] = "mapchild";
   child_argv[2] = pid;
