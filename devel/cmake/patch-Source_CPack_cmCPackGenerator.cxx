$NetBSD$

--- Source/CPack/cmCPackGenerator.cxx.orig	2020-10-06 12:28:17.918028288 +0000
+++ Source/CPack/cmCPackGenerator.cxx
@@ -29,11 +29,6 @@
 #include "cmXMLSafe.h"
 #include "cmake.h"
 
-#if defined(__HAIKU__)
-#  include <FindDirectory.h>
-#  include <StorageDefs.h>
-#endif
-
 cmCPackGenerator::cmCPackGenerator()
 {
   this->GeneratorVerbose = cmSystemTools::OUTPUT_NONE;
@@ -1232,14 +1227,6 @@ const char* cmCPackGenerator::GetInstall
   this->InstallPath += this->GetOption("CPACK_PACKAGE_NAME");
   this->InstallPath += "-";
   this->InstallPath += this->GetOption("CPACK_PACKAGE_VERSION");
-#elif defined(__HAIKU__)
-  char dir[B_PATH_NAME_LENGTH];
-  if (find_directory(B_SYSTEM_DIRECTORY, -1, false, dir, sizeof(dir)) ==
-      B_OK) {
-    this->InstallPath = dir;
-  } else {
-    this->InstallPath = "/boot/system";
-  }
 #else
   this->InstallPath = "/usr/local/";
 #endif
