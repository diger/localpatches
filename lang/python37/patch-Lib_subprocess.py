$NetBSD$

--- Lib/subprocess.py.orig	2020-08-15 05:20:16.051904512 +0000
+++ Lib/subprocess.py
@@ -1537,6 +1537,8 @@ class Popen(object):
                         SubprocessError)
                 if issubclass(child_exception_type, OSError) and hex_errno:
                     errno_num = int(hex_errno, 16)
+                    if sys.platform.startswith('haiku'):
+                        errno_num = -errno_num;
                     child_exec_never_called = (err_msg == "noexec")
                     if child_exec_never_called:
                         err_msg = ""
