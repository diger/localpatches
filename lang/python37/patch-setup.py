--- setup.py.orig	2020-11-24 10:05:42.222298112 +0000
+++ setup.py	2020-11-24 11:35:24.457179136 +0000
@@ -665,6 +665,11 @@
 
         srcdir = sysconfig.get_config_var('srcdir')
 
+        # Haiku-specific library locations
+        if host_platform == 'haiku1':
+            inc_dirs += ['/boot/develop/headers/posix',
+                         '/boot/system/develop/headers']
+            lib_dirs += ['/boot/system/develop/lib']
         # OSF/1 and Unixware have some stuff in /usr/ccs/lib (like -ldb)
         if host_platform in ['osf1', 'unixware7', 'openunix8']:
             lib_dirs += ['/usr/ccs/lib']
@@ -707,12 +712,12 @@
         exts.append( Extension('cmath', ['cmathmodule.c'],
                                extra_objects=[shared_math],
                                depends=['_math.h', shared_math],
-                               libraries=['m']) )
+                               libraries=[]) )
         # math library functions, e.g. sin()
         exts.append( Extension('math',  ['mathmodule.c'],
                                extra_objects=[shared_math],
                                depends=['_math.h', shared_math],
-                               libraries=['m']) )
+                               libraries=[]) )
 
         # time libraries: librt may be needed for clock_gettime()
         time_libs = []
@@ -726,7 +731,7 @@
         # libm is needed by delta_new() that uses round() and by accum() that
         # uses modf().
         exts.append( Extension('_datetime', ['_datetimemodule.c'],
-                               libraries=['m']) )
+                               libraries=[]) )
         # random number generator implemented in C
         exts.append( Extension("_random", ["_randommodule.c"]) )
         # bisect
@@ -817,7 +822,7 @@
         #
         # audioop needs libm for floor() in multiple functions.
         exts.append( Extension('audioop', ['audioop.c'],
-                               libraries=['m']) )
+                               libraries=[]) )
 
         # readline
         do_readline = self.compiler.find_library_file(lib_dirs, 'readline')
@@ -2039,7 +2044,7 @@
         # function my_sqrt() needs libm for sqrt()
         ext_test = Extension('_ctypes_test',
                      sources=['_ctypes/_ctypes_test.c'],
-                     libraries=['m'])
+                     libraries=[])
         self.extensions.extend([ext, ext_test])
 
         if host_platform == 'darwin':
@@ -2084,7 +2089,7 @@
         else:
             srcdir = sysconfig.get_config_var('srcdir')
             include_dirs = ['Modules/_decimal/libmpdec']
-            libraries = ['m']
+            libraries = []
             sources = [
               '_decimal/_decimal.c',
               '_decimal/libmpdec/basearith.c',
@@ -2247,7 +2252,7 @@
         return ssl_ext, hashlib_ext
 
     def _detect_nis(self, inc_dirs, lib_dirs):
-        if host_platform in {'win32', 'cygwin', 'qnx6'}:
+        if host_platform in {'win32', 'cygwin', 'qnx6', 'haiku1'}:
             return None
 
         libs = []
