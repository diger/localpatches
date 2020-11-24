$NetBSD$

--- Lib/test/test_fileio.py.orig	2020-08-15 05:20:16.024641536 +0000
+++ Lib/test/test_fileio.py
@@ -384,6 +384,7 @@ class OtherFileTests:
                     self.assertEqual(f.writable(), True)
                     if sys.platform != "darwin" and \
                        'bsd' not in sys.platform and \
+                       'haiku' not in sys.platform and \
                        not sys.platform.startswith(('sunos', 'aix')):
                         # Somehow /dev/tty appears seekable on some BSDs
                         self.assertEqual(f.seekable(), False)
