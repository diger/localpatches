--- ext/Errno/Errno_pm.PL.orig	2020-06-14 23:01:25.961544192 +0000
+++ ext/Errno/Errno_pm.PL	2020-11-19 15:36:32.247726080 +0000
@@ -143,7 +143,7 @@
 	$file{$linux_errno_h} = 1;
     } elsif ($^O eq 'haiku') {
 	# hidden in a special place
-	$file{'/boot/develop/headers/posix/errno.h'} = 1;
+	$file{'/boot/system/develop/headers/posix/errno.h'} = 1;
 
     } elsif ($^O eq 'vos') {
 	# avoid problem where cpp returns non-POSIX pathnames
