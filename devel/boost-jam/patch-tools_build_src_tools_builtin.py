$NetBSD$

--- tools/build/src/tools/builtin.py.orig	2020-12-09 09:39:14.460062720 +0000
+++ tools/build/src/tools/builtin.py
@@ -82,7 +82,7 @@ def variant (name, parents_or_properties
     feature.compose ("<variant>" + name, explicit_properties.all())
 
 __os_names = """
-    amiga aix appletv bsd cygwin darwin dos emx freebsd hpux iphone linux netbsd
+    amiga aix appletv bsd cygwin darwin dos emx freebsd haiku hpux iphone linux netbsd
     openbsd osf qnx qnxnto sgi solaris sun sunos svr4 sysv ultrix unix unixware
     vms windows
 """.split()
