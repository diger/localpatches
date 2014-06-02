$NetBSD$

--- setup.py.orig	2014-06-01 18:40:48.452722688 +0000
+++ setup.py
@@ -529,6 +529,13 @@ class PyBuildExt(build_ext):
             inc_dirs += ['/system/include', '/atheos/autolnk/include']
             inc_dirs += os.getenv('C_INCLUDE_PATH', '').split(os.pathsep)
 
+        # Check for Haiku which has libraries in non-standard locations
+        if host_platform == 'haiku1':
+            lib_dirs += ['/boot/system/libs']
+            lib_dirs += os.getenv('LIBRARY_PATH', '').split(os.pathsep)
+            inc_dirs += ['/boot/system/develop/headers/posix']
+            inc_dirs += os.getenv('C_INCLUDE_PATH', '').split(os.pathsep)
+        
         # OSF/1 and Unixware have some stuff in /usr/ccs/lib (like -ldb)
         if host_platform in ['osf1', 'unixware7', 'openunix8']:
             lib_dirs += ['/usr/ccs/lib']
