$Haiku$

--- Modules/Platform/Haiku.cmake.orig	2024-08-02 13:57:10.066584576 +0000
+++ Modules/Platform/Haiku.cmake
@@ -59,7 +59,6 @@ list(APPEND CMAKE_SYSTEM_PREFIX_PATH
   )
 
 LIST(APPEND CMAKE_HAIKU_COMMON_INCLUDE_DIRECTORIES
-  /boot/system/non-packaged/develop/headers${CMAKE_HAIKU_SECONDARY_ARCH_SUBDIR}
   /boot/system/develop/headers/os
   /boot/system/develop/headers/os/app
   /boot/system/develop/headers/os/device
@@ -107,7 +106,6 @@ LIST(APPEND CMAKE_HAIKU_CXX_INCLUDE_DIRE
 LIST(APPEND CMAKE_SYSTEM_INCLUDE_PATH ${CMAKE_HAIKU_C_INCLUDE_DIRECTORIES})
 
 LIST(APPEND CMAKE_HAIKU_DEVELOP_LIB_DIRECTORIES
-  /boot/system/non-packaged/develop/lib${CMAKE_HAIKU_SECONDARY_ARCH_SUBDIR}
   /boot/system/develop/lib${CMAKE_HAIKU_SECONDARY_ARCH_SUBDIR}
   )
 
