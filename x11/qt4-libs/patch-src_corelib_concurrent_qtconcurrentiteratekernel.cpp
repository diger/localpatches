$NetBSD$

--- src/corelib/concurrent/qtconcurrentiteratekernel.cpp.orig	2014-07-03 11:22:01.000000000 +0000
+++ src/corelib/concurrent/qtconcurrentiteratekernel.cpp
@@ -67,7 +67,13 @@ enum {
     MedianSize = 7
 };
 
-#if defined(Q_OS_MAC) || defined(__APPLE__)
+#if defined(Q_OS_HAIKU)
+#include <os/kernel/OS.h>
+static qint64 getticks()
+{
+    return system_time();
+}
+#elif defined(Q_OS_MAC) || defined(__APPLE__)
 
 static qint64 getticks()
 {
