$NetBSD$

--- programs/platform.h.orig	2019-08-15 11:59:59.620232704 +0000
+++ programs/platform.h
@@ -81,7 +81,8 @@ extern "C" {
 #if !defined(_WIN32) && (defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__)) /* UNIX-like OS */ \
    || defined(__midipix__) || defined(__VMS))
 #  if (defined(__APPLE__) && defined(__MACH__)) || defined(__SVR4) || defined(_AIX) || defined(__hpux) /* POSIX.1–2001 (SUSv3) conformant */ \
-     || defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)  || defined(__MidnightBSD__) /* BSD distros */
+     || defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)  || defined(__MidnightBSD__) /* BSD distros */ \
+     || defined(__HAIKU__)
 #    define PLATFORM_POSIX_VERSION 200112L
 #  else
 #    if defined(__linux__) || defined(__linux)
