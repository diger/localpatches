$NetBSD$

--- Utilities/cmlibuv/src/unix/core.c.orig	2020-10-06 12:28:17.918028288 +0000
+++ Utilities/cmlibuv/src/unix/core.c
@@ -1418,7 +1418,9 @@ int uv_os_getpriority(uv_pid_t pid, int*
     return UV_EINVAL;
 
   errno = 0;
-  r = getpriority(PRIO_PROCESS, (int) pid);
+#ifndef __HAIKU__
+   r = getpriority(PRIO_PROCESS, (int) pid);
+#endif
 
   if (r == -1 && errno != 0)
     return UV__ERR(errno);
@@ -1432,8 +1434,10 @@ int uv_os_setpriority(uv_pid_t pid, int
   if (priority < UV_PRIORITY_HIGHEST || priority > UV_PRIORITY_LOW)
     return UV_EINVAL;
 
-  if (setpriority(PRIO_PROCESS, (int) pid, priority) != 0)
-    return UV__ERR(errno);
+#ifndef __HAIKU__
+   if (setpriority(PRIO_PROCESS, (int) pid, priority) != 0)
+     return UV__ERR(errno);
+#endif
 
   return 0;
 }
