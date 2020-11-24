$NetBSD$

--- Lib/test/test_posix.py.orig	2020-09-23 12:36:32.009699328 +0000
+++ Lib/test/test_posix.py
@@ -1167,7 +1167,7 @@ class PosixTester(unittest.TestCase):
             posix.close(f)
             support.rmtree(support.TESTFN + 'dir')
 
-    @unittest.skipUnless((os.mknod in os.supports_dir_fd) and hasattr(stat, 'S_IFIFO'),
+    @unittest.skipUnless(hasattr(os, 'mknod') and (os.mknod in os.supports_dir_fd) and hasattr(stat, 'S_IFIFO'),
                          "test requires both stat.S_IFIFO and dir_fd support for os.mknod()")
     def test_mknod_dir_fd(self):
         # Test using mknodat() to create a FIFO (the only use specified
