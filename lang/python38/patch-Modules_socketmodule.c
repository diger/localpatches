$NetBSD: patch-Modules_socketmodule.c,v 1.1 2019/10/15 16:50:11 adam Exp $

Support NetBSD's socketcan implementation

--- Modules/socketmodule.c.orig	2020-11-23 15:53:06.972029952 +0000
+++ Modules/socketmodule.c
@@ -3242,7 +3242,7 @@ sock_connect(PySocketSockObject *s, PyOb
     }
 
     res = internal_connect(s, SAS2SA(&addrbuf), addrlen, 1);
-    if (res < 0)
+    if (res == -1)
         return NULL;
 
     Py_RETURN_NONE;
@@ -3273,7 +3273,7 @@ sock_connect_ex(PySocketSockObject *s, P
     }
 
     res = internal_connect(s, SAS2SA(&addrbuf), addrlen, 0);
-    if (res < 0)
+    if (res == -1)
         return NULL;
 
     return PyLong_FromLong((long) res);
@@ -7419,7 +7419,9 @@ PyInit__socket(void)
     /* SOCK_RAW is marked as optional in the POSIX specification */
     PyModule_AddIntMacro(m, SOCK_RAW);
 #endif
+#ifndef __HAIKU__
     PyModule_AddIntMacro(m, SOCK_SEQPACKET);
+#endif
 #if defined(SOCK_RDM)
     PyModule_AddIntMacro(m, SOCK_RDM);
 #endif
