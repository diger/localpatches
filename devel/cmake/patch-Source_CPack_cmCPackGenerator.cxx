$NetBSD$

--- Source/CPack/cmCPackGenerator.cxx.orig	2014-01-16 17:15:08.000000000 +0000
+++ Source/CPack/cmCPackGenerator.cxx
@@ -1262,16 +1262,6 @@ const char* cmCPackGenerator::GetInstall
   this->InstallPath += this->GetOption("CPACK_PACKAGE_NAME");
   this->InstallPath += "-";
   this->InstallPath += this->GetOption("CPACK_PACKAGE_VERSION");
-#elif defined(__HAIKU__)
-  BPath dir;
-  if (find_directory(B_COMMON_DIRECTORY, &dir) == B_OK)
-    {
-    this->InstallPath = dir.Path();
-    }
-  else
-    {
-    this->InstallPath = "/boot/common";
-    }
 #else
   this->InstallPath = "/usr/local/";
 #endif
