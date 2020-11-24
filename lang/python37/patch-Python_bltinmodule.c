$NetBSD$

--- Python/bltinmodule.c.orig	2020-08-15 05:20:16.061341696 +0000
+++ Python/bltinmodule.c
@@ -17,7 +17,7 @@
    Don't forget to modify PyUnicode_DecodeFSDefault() if you touch any of the
    values for Py_FileSystemDefaultEncoding!
 */
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__HAIKU__)
 const char *Py_FileSystemDefaultEncoding = "utf-8";
 int Py_HasFileSystemDefaultEncoding = 1;
 #elif defined(MS_WINDOWS)
