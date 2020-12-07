$NetBSD$

--- Modules/FindThreads.cmake.orig	2020-10-06 12:28:17.918028288 +0000
+++ Modules/FindThreads.cmake
@@ -197,6 +197,11 @@ if(CMAKE_SYSTEM_NAME MATCHES "Windows")
   set(Threads_FOUND TRUE)
 endif()
 
+if(HAIKU)
+  SET (CMAKE_THREAD_LIBS_INIT "-lroot")
+  SET(Threads_FOUND TRUE)
+endif()
+
 if(CMAKE_USE_PTHREADS_INIT)
   if(CMAKE_SYSTEM_NAME MATCHES "HP-UX")
     # Use libcma if it exists and can be used.  It provides more
