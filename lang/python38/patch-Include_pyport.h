$NetBSD$

--- Include/pyport.h.orig	2020-09-23 12:36:32.051642368 +0000
+++ Include/pyport.h
@@ -828,7 +828,7 @@ extern _invalid_parameter_handler _Py_si
 #  define _Py_FORCE_UTF8_LOCALE
 #endif
 
-#if defined(_Py_FORCE_UTF8_LOCALE) || defined(__APPLE__)
+#if defined(_Py_FORCE_UTF8_LOCALE) || defined(__APPLE__) || defined(__HAIKU__)
    /* Use UTF-8 as filesystem encoding */
 #  define _Py_FORCE_UTF8_FS_ENCODING
 #endif
