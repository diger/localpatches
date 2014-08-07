$NetBSD$

--- src/3rdparty/webkit/Source/JavaScriptCore/jit/JITStubs.cpp.orig	2014-07-31 20:22:51.008388608 +0000
+++ src/3rdparty/webkit/Source/JavaScriptCore/jit/JITStubs.cpp
@@ -79,7 +79,7 @@ namespace JSC {
 #define THUMB_FUNC_PARAM(name)
 #endif
 
-#if (OS(LINUX) || OS(FREEBSD) || OS(NETBSD) || OS(SOLARIS)) && CPU(X86_64) || (OS(SOLARIS) && CPU(X86))
+#if (OS(LINUX) || OS(FREEBSD) || OS(NETBSD)|| OS(HAIKU) || OS(SOLARIS)) && CPU(X86_64) || (OS(SOLARIS) && CPU(X86))
 #define SYMBOL_STRING_RELOCATION(name) #name "@plt"
 #elif OS(DARWIN) || (CPU(X86_64) && COMPILER(MINGW) && !GCC_VERSION_AT_LEAST(4, 5, 0))
 #define SYMBOL_STRING_RELOCATION(name) "_" #name
