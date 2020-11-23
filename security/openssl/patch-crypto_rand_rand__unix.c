--- crypto/rand/rand_unix.c.orig	2020-09-22 12:55:07.028835840 +0000
+++ crypto/rand/rand_unix.c	2020-11-23 01:29:52.590086144 +0000
@@ -217,7 +217,9 @@
 #   if !defined(DEVRANDOM)
 #    error "OS seeding requires DEVRANDOM to be configured"
 #   endif
+#ifndef __HAIKU__
 #   define OPENSSL_RAND_SEED_GETRANDOM
+#endif
 #   define OPENSSL_RAND_SEED_DEVRANDOM
 #  endif
 
@@ -366,7 +368,7 @@
      * - Linux since 3.17 with glibc 2.25
      * - FreeBSD since 12.0 (1200061)
      */
-#  if defined(__GNUC__) && __GNUC__>=2 && defined(__ELF__) && !defined(__hpux)
+#  if defined(__GNUC__) && __GNUC__>=2 && defined(__ELF__) && !defined(__hpux) && !defined(__HAIKU__)
     extern int getentropy(void *buffer, size_t length) __attribute__((weak));
 
     if (getentropy != NULL)
