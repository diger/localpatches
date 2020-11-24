$NetBSD: patch-Modules_socketmodule.c,v 1.1 2018/07/03 03:55:40 adam Exp $

Support NetBSD's socketcan implementation

--- Modules/socketmodule.c.orig	2020-11-24 10:05:41.109576192 +0000
+++ Modules/socketmodule.c
@@ -3111,7 +3111,7 @@ sock_connect(PySocketSockObject *s, PyOb
         return NULL;
 
     res = internal_connect(s, SAS2SA(&addrbuf), addrlen, 1);
-    if (res < 0)
+    if (res == -1)
         return NULL;
 
     Py_RETURN_NONE;
@@ -3137,7 +3137,7 @@ sock_connect_ex(PySocketSockObject *s, P
         return NULL;
 
     res = internal_connect(s, SAS2SA(&addrbuf), addrlen, 0);
-    if (res < 0)
+    if (res == -1)
         return NULL;
 
     return PyLong_FromLong((long) res);
@@ -7163,7 +7163,9 @@ PyInit__socket(void)
     /* SOCK_RAW is marked as optional in the POSIX specification */
     PyModule_AddIntMacro(m, SOCK_RAW);
 #endif
+#ifndef __HAIKU__
     PyModule_AddIntMacro(m, SOCK_SEQPACKET);
+#endif
 #if defined(SOCK_RDM)
     PyModule_AddIntMacro(m, SOCK_RDM);
 #endif
