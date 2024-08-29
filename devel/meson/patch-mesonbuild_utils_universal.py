$NetBSD$

--- mesonbuild/utils/universal.py.orig	2024-07-08 09:25:45.331612160 +0000
+++ mesonbuild/utils/universal.py
@@ -1032,8 +1032,6 @@ def default_libdir() -> str:
 
 
 def default_libexecdir() -> str:
-    if is_haiku():
-        return 'lib'
     # There is no way to auto-detect this, so it must be set at build time
     return 'libexec'
 
@@ -1041,50 +1039,34 @@ def default_libexecdir() -> str:
 def default_prefix() -> str:
     if is_windows():
         return 'c:/'
-    if is_haiku():
-        return '/boot/system/non-packaged'
     return '/usr/local'
 
 
 def default_datadir() -> str:
-    if is_haiku():
-        return 'data'
     return 'share'
 
 
 def default_includedir() -> str:
-    if is_haiku():
-        return 'develop/headers'
     return 'include'
 
 
 def default_infodir() -> str:
-    if is_haiku():
-        return 'documentation/info'
     return 'share/info'
 
 
 def default_localedir() -> str:
-    if is_haiku():
-        return 'data/locale'
     return 'share/locale'
 
 
 def default_mandir() -> str:
-    if is_haiku():
-        return 'documentation/man'
     return 'share/man'
 
 
 def default_sbindir() -> str:
-    if is_haiku():
-        return 'bin'
     return 'sbin'
 
 
 def default_sysconfdir() -> str:
-    if is_haiku():
-        return 'settings'
     return 'etc'
 
 
