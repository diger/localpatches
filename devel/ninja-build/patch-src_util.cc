$NetBSD$

--- src/util.cc.orig	2020-08-18 19:28:04.036175872 +0000
+++ src/util.cc
@@ -583,6 +583,10 @@ double GetLoadAverage() {
     return -0.0f;
   return 1.0 / (1 << SI_LOAD_SHIFT) * si.loads[0];
 }
+#elif defined(__HAIKU__)
+double GetLoadAverage() {
+    return -0.0f;
+}
 #else
 double GetLoadAverage() {
   double loadavg[3] = { 0.0f, 0.0f, 0.0f };
