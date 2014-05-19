$NetBSD$

--- Modules/Platform/Haiku.cmake.orig	2014-01-16 17:15:08.000000000 +0000
+++ Modules/Platform/Haiku.cmake
@@ -1,24 +1,14 @@
-set(BEOS 1)
+set(HAIKU 1)
+set(UNIX 1)
 
 set(CMAKE_DL_LIBS root be)
 set(CMAKE_C_COMPILE_OPTIONS_PIC "-fPIC")
 set(CMAKE_C_COMPILE_OPTIONS_PIE "-fPIE")
 set(CMAKE_SHARED_LIBRARY_C_FLAGS "-fPIC")
-set(CMAKE_SHARED_LIBRARY_CREATE_C_FLAGS "-nostart")
+set(CMAKE_SHARED_LIBRARY_CREATE_C_FLAGS "--shared")
 set(CMAKE_SHARED_LIBRARY_RUNTIME_C_FLAG "-Wl,-rpath,")
 set(CMAKE_SHARED_LIBRARY_RUNTIME_C_FLAG_SEP ":")
 set(CMAKE_SHARED_LIBRARY_SONAME_C_FLAG "-Wl,-soname,")
+set(CMAKE_EXE_EXPORTS_C_FLAG "-Wl,--export-dynamic")
 
 include(Platform/UnixPaths)
-list(APPEND CMAKE_SYSTEM_PREFIX_PATH /boot/common)
-list(APPEND CMAKE_SYSTEM_INCLUDE_PATH /boot/common/include)
-list(APPEND CMAKE_SYSTEM_LIBRARY_PATH /boot/common/lib)
-list(APPEND CMAKE_SYSTEM_PROGRAM_PATH /boot/common/bin)
-list(APPEND CMAKE_PLATFORM_IMPLICIT_LINK_DIRECTORIES /boot/common/lib)
-list(APPEND CMAKE_SYSTEM_INCLUDE_PATH /boot/develop/headers/3rdparty)
-list(APPEND CMAKE_SYSTEM_LIBRARY_PATH /boot/develop/lib/x86)
-
-if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
-  set(CMAKE_INSTALL_PREFIX "/boot/common" CACHE PATH
-    "Install path prefix, prepended onto install directories." FORCE)
-endif()
