$NetBSD$

--- Modules/posixmodule.c.orig	2013-05-12 03:32:51.051642368 +0000
+++ Modules/posixmodule.c
@@ -350,6 +350,10 @@ extern int lstat(const char *, struct st
 #endif
 #endif
 
+#ifdef __HAIKU__
+#undef HAVE_WAIT3
+#undef HAVE_WAIT4
+#endif
 
 #ifndef MS_WINDOWS
 PyObject *
