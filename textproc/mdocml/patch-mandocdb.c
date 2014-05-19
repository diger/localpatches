$NetBSD$

--- mandocdb.c.orig	2014-05-19 02:56:59.000000000 +0000
+++ mandocdb.c
@@ -1765,7 +1765,7 @@ ofile_dirbuild(const char *dir, const ch
 		int p_src_form, struct of **of)
 {
 	char		 buf[PATH_MAX];
-#if defined(__sun)
+#if defined(__sun) || defined(__HAIKU__)
 	struct stat	 sb;
 #endif
 	size_t		 sz;
@@ -1790,7 +1790,7 @@ ofile_dirbuild(const char *dir, const ch
 
 		src_form = p_src_form;
 
-#if defined(__sun)
+#if defined(__sun) || defined(__HAIKU__)
 		stat(dp->d_name, &sb);
 		if (S_IFDIR & sb.st_mode) {
 #else
@@ -1852,7 +1852,7 @@ ofile_dirbuild(const char *dir, const ch
 			continue;
 		}
 
-#if defined(__sun)
+#if defined(__sun)  || defined(__HAIKU__)
 		if (0 == S_IFREG & sb.st_mode) {
 #else
 		if (DT_REG != dp->d_type) {
