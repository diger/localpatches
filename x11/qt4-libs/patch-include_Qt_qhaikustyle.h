$NetBSD$

--- include/Qt/qhaikustyle.h.orig	2014-07-03 10:34:03.108003328 +0000
+++ include/Qt/qhaikustyle.h
@@ -0,0 +1,9 @@
+#ifndef QT_NO_QT_INCLUDE_WARN
+    #if defined(__GNUC__)
+        #warning "Inclusion of header files from include/Qt is deprecated."
+    #elif defined(_MSC_VER)
+        #pragma message("WARNING: Inclusion of header files from include/Qt is deprecated.")
+    #endif
+#endif
+
+#include "../QtGui/qhaikustyle.h"
