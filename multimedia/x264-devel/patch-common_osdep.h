$NetBSD$

--- common/osdep.h.orig	2013-10-15 20:45:04.046923776 +0000
+++ common/osdep.h
@@ -367,6 +367,8 @@ static ALWAYS_INLINE void x264_prefetch(
     sp.sched_priority -= p;\
     pthread_setschedparam( handle, policy, &sp );\
 }
+#elif SYS_HAIKU
+#define x264_lower_thread_priority(p) { UNUSED int nice_ret = -1; }
 #else
 #include <unistd.h>
 #define x264_lower_thread_priority(p) { UNUSED int nice_ret = nice(p); }
