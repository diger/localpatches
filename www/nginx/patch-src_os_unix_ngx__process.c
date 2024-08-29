egrep: warning: egrep is obsolescent; using grep -E
$NetBSD$

--- src/os/unix/ngx_process.c.orig	2023-04-11 01:45:34.014417920 +0000
+++ src/os/unix/ngx_process.c
@@ -71,7 +71,9 @@ ngx_signal_t  signals[] = {
 
     { SIGINT, "SIGINT", "", ngx_signal_handler },
 
+#ifdef SIGIO
     { SIGIO, "SIGIO", "", ngx_signal_handler },
+#endif
 
     { SIGCHLD, "SIGCHLD", "", ngx_signal_handler },
 
@@ -143,19 +145,23 @@ ngx_spawn_process(ngx_cycle_t *cycle, ng
         }
 
         on = 1;
+#ifdef FIOASYNC
         if (ioctl(ngx_processes[s].channel[0], FIOASYNC, &on) == -1) {
             ngx_log_error(NGX_LOG_ALERT, cycle->log, ngx_errno,
                           "ioctl(FIOASYNC) failed while spawning \"%s\"", name);
             ngx_close_channel(ngx_processes[s].channel, cycle->log);
             return NGX_INVALID_PID;
         }
+#endif
 
+#ifdef F_SETOWN
         if (fcntl(ngx_processes[s].channel[0], F_SETOWN, ngx_pid) == -1) {
             ngx_log_error(NGX_LOG_ALERT, cycle->log, ngx_errno,
                           "fcntl(F_SETOWN) failed while spawning \"%s\"", name);
             ngx_close_channel(ngx_processes[s].channel, cycle->log);
             return NGX_INVALID_PID;
         }
+#endif
 
         if (fcntl(ngx_processes[s].channel[0], F_SETFD, FD_CLOEXEC) == -1) {
             ngx_log_error(NGX_LOG_ALERT, cycle->log, ngx_errno,
@@ -394,9 +400,11 @@ ngx_signal_handler(int signo, siginfo_t
             ngx_sigalrm = 1;
             break;
 
+#ifdef SIGIO
         case SIGIO:
             ngx_sigio = 1;
             break;
+#endif
 
         case SIGCHLD:
             ngx_reap = 1;
@@ -433,7 +441,9 @@ ngx_signal_handler(int signo, siginfo_t
 
         case ngx_signal_value(NGX_RECONFIGURE_SIGNAL):
         case ngx_signal_value(NGX_CHANGEBIN_SIGNAL):
+#ifdef SIGIO
         case SIGIO:
+#endif
             action = ", ignoring";
             break;
         }
