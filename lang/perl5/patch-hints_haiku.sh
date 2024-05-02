--- hints/haiku.sh.orig	2024-05-02 15:02:26.265289728 +0500
+++ hints/haiku.sh	2024-05-02 15:02:39.139460608 +0500
@@ -31,7 +31,7 @@
 cc="gcc"
 ld='gcc'
 
-ccflags="$ccflags -fno-stack-protector"
+ccflags="$ccflags -fno-stack-protector -DNO_POSIX_2008_LOCALE"
 
 # The runtime loader library path variable is LIBRARY_PATH.
 case "$ldlibpthname" in
