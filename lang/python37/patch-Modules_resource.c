$NetBSD$

--- Modules/resource.c.orig	2020-08-15 05:20:16.059244544 +0000
+++ Modules/resource.c
@@ -102,6 +102,7 @@ resource_getrusage_impl(PyObject *module
                     PyFloat_FromDouble(doubletime(ru.ru_utime)));
     PyStructSequence_SET_ITEM(result, 1,
                     PyFloat_FromDouble(doubletime(ru.ru_stime)));
+#ifndef __HAIKU__
     PyStructSequence_SET_ITEM(result, 2, PyLong_FromLong(ru.ru_maxrss));
     PyStructSequence_SET_ITEM(result, 3, PyLong_FromLong(ru.ru_ixrss));
     PyStructSequence_SET_ITEM(result, 4, PyLong_FromLong(ru.ru_idrss));
@@ -116,7 +117,22 @@ resource_getrusage_impl(PyObject *module
     PyStructSequence_SET_ITEM(result, 13, PyLong_FromLong(ru.ru_nsignals));
     PyStructSequence_SET_ITEM(result, 14, PyLong_FromLong(ru.ru_nvcsw));
     PyStructSequence_SET_ITEM(result, 15, PyLong_FromLong(ru.ru_nivcsw));
-
+#else
+    PyStructSequence_SET_ITEM(result, 2, PyLong_FromLong(0));
+    PyStructSequence_SET_ITEM(result, 3, PyLong_FromLong(0));
+    PyStructSequence_SET_ITEM(result, 4, PyLong_FromLong(0));
+    PyStructSequence_SET_ITEM(result, 5, PyLong_FromLong(0));
+    PyStructSequence_SET_ITEM(result, 6, PyLong_FromLong(0));
+    PyStructSequence_SET_ITEM(result, 7, PyLong_FromLong(0));
+    PyStructSequence_SET_ITEM(result, 8, PyLong_FromLong(0));
+    PyStructSequence_SET_ITEM(result, 9, PyLong_FromLong(0));
+    PyStructSequence_SET_ITEM(result, 10, PyLong_FromLong(0));
+    PyStructSequence_SET_ITEM(result, 11, PyLong_FromLong(0));
+    PyStructSequence_SET_ITEM(result, 12, PyLong_FromLong(0));
+    PyStructSequence_SET_ITEM(result, 13, PyLong_FromLong(0));
+    PyStructSequence_SET_ITEM(result, 14, PyLong_FromLong(0));
+    PyStructSequence_SET_ITEM(result, 15, PyLong_FromLong(0));
+#endif
     if (PyErr_Occurred()) {
         Py_DECREF(result);
         return NULL;
@@ -369,19 +385,19 @@ PyInit_resource(void)
                        (PyObject*) &StructRUsageType);
 
     /* insert constants */
-#ifdef RLIMIT_CPU
+#if !defined(__HAIKU__) && defined(RLIMIT_CPU)
     PyModule_AddIntMacro(m, RLIMIT_CPU);
 #endif
 
-#ifdef RLIMIT_FSIZE
+#if !defined(__HAIKU__) && defined(RLIMIT_FSIZE)
     PyModule_AddIntMacro(m, RLIMIT_FSIZE);
 #endif
 
-#ifdef RLIMIT_DATA
+#if !defined(__HAIKU__) && defined(RLIMIT_DATA)
     PyModule_AddIntMacro(m, RLIMIT_DATA);
 #endif
 
-#ifdef RLIMIT_STACK
+#if !defined(__HAIKU__) && defined(RLIMIT_STACK)
     PyModule_AddIntMacro(m, RLIMIT_STACK);
 #endif
 
@@ -393,31 +409,31 @@ PyInit_resource(void)
     PyModule_AddIntMacro(m, RLIMIT_NOFILE);
 #endif
 
-#ifdef RLIMIT_OFILE
+#if !defined(__HAIKU__) && defined(RLIMIT_OFILE)
     PyModule_AddIntMacro(m, RLIMIT_OFILE);
 #endif
 
-#ifdef RLIMIT_VMEM
+#if !defined(__HAIKU__) && defined(RLIMIT_VMEM)
     PyModule_AddIntMacro(m, RLIMIT_VMEM);
 #endif
 
-#ifdef RLIMIT_AS
+#if !defined(__HAIKU__) && defined(RLIMIT_AS)
     PyModule_AddIntMacro(m, RLIMIT_AS);
 #endif
 
-#ifdef RLIMIT_RSS
+#if !defined(__HAIKU__) && defined(RLIMIT_RSS)
     PyModule_AddIntMacro(m, RLIMIT_RSS);
 #endif
 
-#ifdef RLIMIT_NPROC
+#if !defined(__HAIKU__) && defined(RLIMIT_NPROC)
     PyModule_AddIntMacro(m, RLIMIT_NPROC);
 #endif
 
-#ifdef RLIMIT_MEMLOCK
+#if !defined(__HAIKU__) && defined(RLIMIT_MEMLOCK)
     PyModule_AddIntMacro(m, RLIMIT_MEMLOCK);
 #endif
 
-#ifdef RLIMIT_SBSIZE
+#if !defined(__HAIKU__) && defined(RLIMIT_SBSIZE)
     PyModule_AddIntMacro(m, RLIMIT_SBSIZE);
 #endif
 
