$NetBSD$

--- Lib/logging/__init__.py.orig	2020-08-15 05:20:16.011534336 +0000
+++ Lib/logging/__init__.py
@@ -228,7 +228,7 @@ def _releaseLock():
 
 # Prevent a held logging lock from blocking a child from logging.
 
-if not hasattr(os, 'register_at_fork'):  # Windows and friends.
+if sys.platform.startswith('haiku') or not hasattr(os, 'register_at_fork'):  # Windows and friends.
     def _register_at_fork_reinit_lock(instance):
         pass  # no-op when os.register_at_fork does not exist.
 else:
