$NetBSD$

--- Lib/test/test_fileio.py.orig	2020-09-23 12:36:32.055574528 +0000
+++ Lib/test/test_fileio.py
@@ -384,6 +384,7 @@ class OtherFileTests:
                     self.assertEqual(f.writable(), True)
                     if sys.platform != "darwin" and \
                        'bsd' not in sys.platform and \
+                       'haiku' not in sys.platform and \
                        not sys.platform.startswith(('sunos', 'aix')):
                         # Somehow /dev/tty appears seekable on some BSDs
                         self.assertEqual(f.seekable(), False)
