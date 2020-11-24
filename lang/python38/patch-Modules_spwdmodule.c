$NetBSD$

--- Modules/spwdmodule.c.orig	2020-09-23 12:36:32.047185920 +0000
+++ Modules/spwdmodule.c
@@ -9,6 +9,7 @@
 #ifdef HAVE_SHADOW_H
 #include <shadow.h>
 #endif
+#include <errno.h>
 
 #include "clinic/spwdmodule.c.h"
 
@@ -138,7 +139,12 @@ spwd_getspnam_impl(PyObject *module, PyO
     if (PyBytes_AsStringAndSize(bytes, &name, NULL) == -1)
         goto out;
     if ((p = getspnam(name)) == NULL) {
+// Haiku sets ENOENT if invalid user is specified. Ignore it to make KeyError is set.
+#ifdef __HAIKU__
+        if (errno != 0 && errno != ENOENT)
+#else
         if (errno != 0)
+#endif
             PyErr_SetFromErrno(PyExc_OSError);
         else
             PyErr_SetString(PyExc_KeyError, "getspnam(): name not found");
