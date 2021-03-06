$NetBSD$

--- tools/build/v2/tools/gcc.py.orig	2014-06-02 10:26:03.000000000 +0000
+++ tools/build/v2/tools/gcc.py
@@ -677,6 +677,9 @@ elif bjam.variable('UNIX'):
     elif host_os_name == 'BeOS':
         # BeOS has no threading options, don't set anything here.
         pass
+    elif host_os_name == 'Haiku':
+        flags('gcc', 'OPTIONS', ['<threading>multi'], ['-lroot'])
+        # there is no -lrt on HAIKU
     elif host_os_name.endswith('BSD'):
         flags('gcc', 'OPTIONS', ['<threading>multi'], ['-pthread'])
         # there is no -lrt on BSD
