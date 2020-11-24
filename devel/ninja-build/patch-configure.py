$NetBSD$

--- configure.py.orig	2020-08-18 19:28:04.021757952 +0000
+++ configure.py
@@ -56,6 +56,8 @@ class Platform(object):
             self._platform = 'msvc'
         elif self._platform.startswith('bitrig'):
             self._platform = 'bitrig'
+        elif self._platform.startswith('haiku'):
+            self._platform = 'haiku'
         elif self._platform.startswith('netbsd'):
             self._platform = 'netbsd'
         elif self._platform.startswith('aix'):
@@ -69,7 +71,7 @@ class Platform(object):
     def known_platforms():
       return ['linux', 'darwin', 'freebsd', 'openbsd', 'solaris', 'sunos5',
               'mingw', 'msvc', 'gnukfreebsd', 'bitrig', 'netbsd', 'aix',
-              'dragonfly']
+              'dragonfly', 'haiku']
 
     def platform(self):
         return self._platform
@@ -96,6 +98,9 @@ class Platform(object):
     def is_solaris(self):
         return self._platform == 'solaris'
 
+    def is_haiku(self):
+        return self._platform == 'is_haiku'
+
     def is_aix(self):
         return self._platform == 'aix'
 
@@ -472,11 +477,7 @@ if platform.supports_ninja_browse():
 
 n.comment('the depfile parser and ninja lexers are generated using re2c.')
 def has_re2c():
-    try:
-        proc = subprocess.Popen(['re2c', '-V'], stdout=subprocess.PIPE)
-        return int(proc.communicate()[0], 10) >= 1103
-    except OSError:
-        return False
+    return False
 if has_re2c():
     n.rule('re2c',
            command='re2c -b -i --no-generation-date -o $out $in',
