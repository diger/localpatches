$NetBSD$

--- qmake/generators/metamakefile.cpp.orig	2013-06-07 05:17:01.017039360 +0000
+++ qmake/generators/metamakefile.cpp
@@ -531,6 +531,9 @@ MetaMakefileGenerator::modesForGenerator
 #ifdef Q_OS_MAC
         *host_mode = Option::HOST_MACX_MODE;
         *target_mode = Option::TARG_MACX_MODE;
+#elif defined(Q_OS_HAIKU)
+        *host_mode = Option::HOST_HAIKU_MODE;
+        *target_mode = Option::TARG_HAIKU_MODE;
 #else
         *host_mode = Option::HOST_UNIX_MODE;
         *target_mode = Option::TARG_UNIX_MODE;
