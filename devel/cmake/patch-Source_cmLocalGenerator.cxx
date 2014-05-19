$NetBSD$

--- Source/cmLocalGenerator.cxx.orig	2013-11-21 09:12:38.913833984 +0000
+++ Source/cmLocalGenerator.cxx
@@ -36,9 +36,6 @@
 
 #include <assert.h>
 
-#if defined(__HAIKU__)
-#include <StorageKit.h>
-#endif
 
 cmLocalGenerator::cmLocalGenerator()
 {
@@ -347,19 +344,6 @@ void cmLocalGenerator::GenerateInstallRu
       }
     prefix = prefix_win32.c_str();
     }
-#elif defined(__HAIKU__)
-  if (!prefix)
-    {
-    BPath dir;
-    if (find_directory(B_COMMON_DIRECTORY, &dir) == B_OK)
-      {
-      prefix = dir.Path();
-      }
-    else
-      {
-      prefix = "/boot/common";
-      }
-    }
 #else
   if (!prefix)
     {
