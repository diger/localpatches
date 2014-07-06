$NetBSD$

--- src/3rdparty/webkit/Source/JavaScriptCore/heap/MachineStackMarker.cpp.orig	2014-07-04 02:48:12.788791296 +0000
+++ src/3rdparty/webkit/Source/JavaScriptCore/heap/MachineStackMarker.cpp
@@ -45,6 +45,10 @@
 #include <mach/thread_act.h>
 #include <mach/vm_map.h>
 
+#elif OS(HAIKU)
+
+#include <OS.h>
+
 #elif OS(WINDOWS)
 
 #include <windows.h>
@@ -116,6 +120,8 @@ UNUSED_PARAM(end);
 
 #if OS(DARWIN)
 typedef mach_port_t PlatformThread;
+#elif OS(HAIKU)
+typedef thread_id PlatformThread;
 #elif OS(QNX)
 typedef pthread_t PlatformThread;
 #elif OS(WINDOWS)
@@ -140,7 +146,7 @@ public:
         , platformThread(platThread)
         , stackBase(base)
     {
-#if USE(PTHREADS) && !OS(WINDOWS) && !OS(DARWIN) && !OS(QNX)
+#if USE(PTHREADS) && !OS(WINDOWS) && !OS(DARWIN) && !OS(QNX) && !OS(HAIKU) && defined(SA_RESTART)
         struct sigaction action;
         action.sa_handler = pthreadSignalHandlerSuspendResume;
         sigemptyset(&action.sa_mask);
@@ -194,6 +200,8 @@ static inline PlatformThread getCurrentP
 {
 #if OS(DARWIN)
     return pthread_mach_thread_np(pthread_self());
+#elif OS(HAIKU)
+    return find_thread(NULL);
 #elif OS(WINDOWS)
     return pthread_getw32threadhandle_np(pthread_self());
 #elif USE(PTHREADS)
@@ -296,6 +304,8 @@ static inline void suspendThread(const P
 {
 #if OS(DARWIN)
     thread_suspend(platformThread);
+#elif OS(HAIKU)
+    suspend_thread(platformThread);
 #elif OS(QNX)
     ThreadCtl(_NTO_TCTL_ONE_THREAD_HOLD, static_cast<void*>(platformThread));
 #elif OS(WINDOWS)
@@ -311,6 +321,8 @@ static inline void resumeThread(const Pl
 {
 #if OS(DARWIN)
     thread_resume(platformThread);
+#elif OS(HAIKU)
+    resume_thread(platformThread);
 #elif OS(QNX)
     ThreadCtl(_NTO_TCTL_ONE_THREAD_CONT, static_cast<void*>(platformThread));
 #elif OS(WINDOWS)
@@ -342,6 +354,8 @@ typedef arm_thread_state_t PlatformThrea
 
 #elif OS(WINDOWS)
 typedef CONTEXT PlatformThreadRegisters;
+#elif OS(HAIKU)
+typedef thread_info PlatformThreadRegisters;
 #elif USE(PTHREADS)
 typedef pthread_attr_t PlatformThreadRegisters;
 #else
@@ -385,6 +399,9 @@ static size_t getPlatformThreadRegisters
     regs.ContextFlags = CONTEXT_INTEGER | CONTEXT_CONTROL | CONTEXT_SEGMENTS;
     GetThreadContext(platformThread, &regs);
     return sizeof(CONTEXT);
+#elif OS(HAIKU)
+	get_thread_info(platformThread, &regs);
+	return sizeof(thread_info);
 #elif USE(PTHREADS)
     pthread_attr_init(&regs);
 #if HAVE(PTHREAD_NP_H) || OS(NETBSD)
@@ -434,6 +451,8 @@ static inline void* otherThreadStackPoin
 #endif // __DARWIN_UNIX03
 
 // end OS(DARWIN)
+#elif OS(HAIKU)
+    return reinterpret_cast<void*>(regs.stack_base);
 #elif CPU(X86) && OS(WINDOWS)
     return reinterpret_cast<void*>((uintptr_t) regs.Esp);
 #elif CPU(X86_64) && OS(WINDOWS)
@@ -453,7 +472,7 @@ static inline void* otherThreadStackPoin
 #if !OS(SOLARIS)
 static void freePlatformThreadRegisters(PlatformThreadRegisters& regs)
 {
-#if USE(PTHREADS) && !OS(WINDOWS) && !OS(DARWIN)
+#if USE(PTHREADS) && !OS(WINDOWS) && !OS(DARWIN) && !OS(HAIKU)
     pthread_attr_destroy(&regs);
 #else
     UNUSED_PARAM(regs);
