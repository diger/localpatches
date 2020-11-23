$NetBSD$

--- include/X11/Xos_r.h.orig	2020-04-14 15:29:25.788004864 +0000
+++ include/X11/Xos_r.h
@@ -88,6 +88,10 @@ in this Software without prior written a
 # endif
 #endif /* _XOS_R_H */
 
+#ifdef __HAIKU__
+#define _POSIX_THREAD_SAFE_FUNCTIONS
+#endif
+
 #ifndef WIN32
 
 #ifdef __cplusplus
@@ -248,7 +252,7 @@ typedef struct {
  */
 
 #if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__OpenBSD__) || \
-    defined(__APPLE__) || defined(__DragonFly__)
+    defined(__APPLE__) || defined(__DragonFly__) || defined(__HAIKU__)
 static __inline__ void _Xpw_copyPasswd(_Xgetpwparams p)
 {
    memcpy(&(p).pws, (p).pwp, sizeof(struct passwd));
