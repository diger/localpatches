$NetBSD$

--- subversion/libsvn_subr/config_file.c.orig	2014-02-17 16:13:23.553910272 +0000
+++ subversion/libsvn_subr/config_file.c
@@ -397,19 +397,7 @@ svn_config__sys_config_path(const char *
                                    SVN_CONFIG__SUBDIRECTORY, fname, NULL);
   }
 
-#elif defined(__HAIKU__)
-  {
-    char folder[B_PATH_NAME_LENGTH];
-
-    status_t error = find_directory(B_COMMON_SETTINGS_DIRECTORY, -1, false,
-                                    folder, sizeof(folder));
-    if (error)
-      return SVN_NO_ERROR;
-
-    *path_p = svn_dirent_join_many(pool, folder,
-                                   SVN_CONFIG__SYS_DIRECTORY, fname, NULL);
-  }
-#else  /* ! WIN32 && !__HAIKU__ */
+#else  /* ! WIN32 */
 
   *path_p = svn_dirent_join_many(pool, SVN_CONFIG__SYS_DIRECTORY, fname, NULL);
 
