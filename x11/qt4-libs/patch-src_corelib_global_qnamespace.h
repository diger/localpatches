$NetBSD$

--- src/corelib/global/qnamespace.h.orig	2013-06-07 05:16:52.000000000 +0000
+++ src/corelib/global/qnamespace.h
@@ -1677,6 +1677,8 @@ public:
     typedef void * HANDLE;
 #elif defined(Q_OS_SYMBIAN)
     typedef unsigned long int HANDLE; // equivalent to TUint32
+#elif defined(Q_OS_HAIKU)
+    typedef unsigned long HANDLE; // equivalent to TUint32
 #endif
     typedef WindowFlags WFlags;
 
