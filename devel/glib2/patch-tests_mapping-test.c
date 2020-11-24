$NetBSD$

--- tests/mapping-test.c.orig	2020-09-10 10:42:41.767557632 +0000
+++ tests/mapping-test.c
@@ -182,6 +182,10 @@ test_private (void)
   g_message ("test_private: ok");
 }
 
+#ifdef __HAIKU__
+#include <SupportDefs.h>
+#endif
+
 static void
 test_child_private (gchar *argv0)
 {
@@ -208,7 +212,11 @@ test_child_private (gchar *argv0)
   signal (SIGUSR1, handle_usr1);
 #endif
 
+#ifdef __HAIKU__
+  g_snprintf (pid, sizeof(pid), B_PRId32, getpid ());
+#else
   g_snprintf (pid, sizeof(pid), "%d", getpid ());
+#endif
   child_argv[0] = argv0;
   child_argv[1] = "mapchild";
   child_argv[2] = pid;
