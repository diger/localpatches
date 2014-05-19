$NetBSD$

--- cgi.c.orig	2013-12-30 19:27:50.000000000 +0000
+++ cgi.c
@@ -34,7 +34,7 @@
 #include <string.h>
 #include <unistd.h>
 
-#if defined(__sun)
+#if defined(__sun) || defined(__HAIKU__)
 /* for stat() */
 #include <fcntl.h>
 #include <sys/types.h>
@@ -1104,12 +1104,12 @@ static int
 pathstop(DIR *dir)
 {
 	struct dirent	*d;
-#if defined(__sun)
+#if defined(__sun) || defined(__HAIKU__)
 	struct stat	 sb;
 #endif
 
 	while (NULL != (d = readdir(dir))) {
-#if defined(__sun)
+#if defined(__sun) || defined(__HAIKU__)
 		stat(d->d_name, &sb);
 		if (S_IFREG & sb.st_mode)
 #else
@@ -1134,7 +1134,7 @@ pathgen(DIR *dir, char *path, struct req
 	DIR		*cd;
 	int		 rc;
 	size_t		 sz, ssz;
-#if defined(__sun)
+#if defined(__sun) || defined(__HAIKU__)
 	struct stat	 sb;
 #endif
 
@@ -1152,7 +1152,7 @@ pathgen(DIR *dir, char *path, struct req
 
 	rc = 0;
 	while (0 == rc && NULL != (d = readdir(dir))) {
-#if defined(__sun)
+#if defined(__sun) || defined(__HAIKU__)
 		stat(d->d_name, &sb);
 		if (!(S_IFDIR & sb.st_mode)
 #else
@@ -1207,7 +1207,7 @@ pathgen(DIR *dir, char *path, struct req
 
 	rewinddir(dir);
 	while (NULL != (d = readdir(dir))) {
-#if defined(__sun)
+#if defined(__sun) || defined(__HAIKU__)
 		stat(d->d_name, &sb);
 		if (!(S_IFDIR & sb.st_mode)
 #else
