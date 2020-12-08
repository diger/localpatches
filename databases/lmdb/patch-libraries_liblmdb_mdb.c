$NetBSD$

--- libraries/liblmdb/mdb.c.orig	2020-12-05 00:53:11.876871680 +0000
+++ libraries/liblmdb/mdb.c
@@ -127,7 +127,7 @@ typedef SSIZE_T	ssize_t;
 #if defined(__FreeBSD__) && defined(__FreeBSD_version) && __FreeBSD_version >= 1100110
 # define MDB_USE_POSIX_MUTEX	1
 # define MDB_USE_ROBUST	1
-#elif defined(__APPLE__) || defined (BSD) || defined(__FreeBSD_kernel__)
+#elif defined(__APPLE__) || defined (BSD) || defined(__FreeBSD_kernel__) || defined(__HAIKU__)
 # define MDB_USE_POSIX_SEM	1
 # define MDB_FDATASYNC		fsync
 #elif defined(ANDROID)
