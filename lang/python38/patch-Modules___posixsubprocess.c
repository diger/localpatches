$NetBSD$

--- Modules/_posixsubprocess.c.orig	2020-09-23 12:36:32.051642368 +0000
+++ Modules/_posixsubprocess.c
@@ -534,6 +534,10 @@ error:
         char *cur;
         _Py_write_noraise(errpipe_write, "OSError:", 8);
         cur = hex_errno + sizeof(hex_errno);
+#ifdef __HAIKU__
+        if (saved_errno < 0)
+            saved_errno = -saved_errno;
+#endif
         while (saved_errno != 0 && cur != hex_errno) {
             *--cur = Py_hexdigits[saved_errno % 16];
             saved_errno /= 16;
