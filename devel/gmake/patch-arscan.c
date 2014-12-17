$NetBSD$

--- arscan.c.orig	2010-07-13 01:20:32.000000000 +0000
+++ arscan.c
@@ -325,7 +325,7 @@
 #endif
 
 #ifndef WINDOWS32
-# if !defined (__ANDROID__) && !defined (__BEOS__)
+# if !defined (__ANDROID__) && !defined (__BEOS__) && !defined (__HAIKU__)
 #  include <ar.h>
 # else
    /* These platforms don't have <ar.h> but have archives in the same format
