egrep: warning: egrep is obsolescent; using grep -E
$NetBSD$

--- src/os/unix/ngx_process_cycle.c.orig	2023-04-11 01:45:34.014680064 +0000
+++ src/os/unix/ngx_process_cycle.c
@@ -87,7 +87,9 @@ ngx_master_process_cycle(ngx_cycle_t *cy
     sigemptyset(&set);
     sigaddset(&set, SIGCHLD);
     sigaddset(&set, SIGALRM);
+#ifdef SIGIO
     sigaddset(&set, SIGIO);
+#endif
     sigaddset(&set, SIGINT);
     sigaddset(&set, ngx_signal_value(NGX_RECONFIGURE_SIGNAL));
     sigaddset(&set, ngx_signal_value(NGX_REOPEN_SIGNAL));
@@ -767,12 +769,14 @@ ngx_worker_process_init(ngx_cycle_t *cyc
 
     ccf = (ngx_core_conf_t *) ngx_get_conf(cycle->conf_ctx, ngx_core_module);
 
+#if (NGX_HAVE_SETPRIORITY)
     if (worker >= 0 && ccf->priority != 0) {
         if (setpriority(PRIO_PROCESS, 0, ccf->priority) == -1) {
             ngx_log_error(NGX_LOG_ALERT, cycle->log, ngx_errno,
                           "setpriority(%d) failed", ccf->priority);
         }
     }
+#endif
 
     if (ccf->rlimit_nofile != NGX_CONF_UNSET) {
         rlmt.rlim_cur = (rlim_t) ccf->rlimit_nofile;
