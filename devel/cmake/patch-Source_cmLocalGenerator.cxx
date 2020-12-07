$NetBSD$

--- Source/cmLocalGenerator.cxx.orig	2020-10-06 12:28:17.918028288 +0000
+++ Source/cmLocalGenerator.cxx
@@ -54,11 +54,6 @@
 #  include "cmCryptoHash.h"
 #endif
 
-#if defined(__HAIKU__)
-#  include <FindDirectory.h>
-#  include <StorageDefs.h>
-#endif
-
 // List of variables that are replaced when
 // rules are expanced.  These variables are
 // replaced in the form <var> with GetSafeDefinition(var).
@@ -441,16 +436,6 @@ void cmLocalGenerator::GenerateInstallRu
     }
     prefix = prefix_win32.c_str();
   }
-#elif defined(__HAIKU__)
-  char dir[B_PATH_NAME_LENGTH];
-  if (!prefix) {
-    if (find_directory(B_SYSTEM_DIRECTORY, -1, false, dir, sizeof(dir)) ==
-        B_OK) {
-      prefix = dir;
-    } else {
-      prefix = "/boot/system";
-    }
-  }
 #else
   if (!prefix) {
     prefix = "/usr/local";
