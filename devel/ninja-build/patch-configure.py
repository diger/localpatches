egrep: warning: egrep is obsolescent; using grep -E
$NetBSD$

--- configure.py.orig	2024-04-11 16:44:05.047185920 +0000
+++ configure.py
@@ -53,6 +53,8 @@ class Platform(object):
             self._platform = 'msvc'
         elif self._platform.startswith('bitrig'):
             self._platform = 'bitrig'
+        elif self._platform.startswith('haiku'):
+            self._platform = 'haiku'
         elif self._platform.startswith('netbsd'):
             self._platform = 'netbsd'
         elif self._platform.startswith('aix'):
@@ -66,7 +68,7 @@ class Platform(object):
     def known_platforms():
       return ['linux', 'darwin', 'freebsd', 'openbsd', 'solaris', 'sunos5',
               'mingw', 'msvc', 'gnukfreebsd', 'bitrig', 'netbsd', 'aix',
-              'dragonfly']
+              'dragonfly', 'haiku']
 
     def platform(self):
         return self._platform
@@ -93,6 +95,9 @@ class Platform(object):
     def is_solaris(self):
         return self._platform == 'solaris'
 
+    def is_haiku(self):
+        return self._platform == 'haiku'
+
     def is_aix(self):
         return self._platform == 'aix'
 
