$NetBSD$

--- ext/Errno/Errno_pm.PL.orig	2013-08-12 02:44:48.000000000 +0000
+++ ext/Errno/Errno_pm.PL
@@ -143,7 +143,7 @@ sub get_files {
 	$file{$linux_errno_h} = 1;
     } elsif ($^O eq 'haiku') {
 	# hidden in a special place
-	$file{'/boot/develop/headers/posix/errno.h'} = 1;
+	$file{'/boot/system/develop/headers/posix/errno.h'} = 1;
 
     } elsif ($^O eq 'vos') {
 	# avoid problem where cpp returns non-POSIX pathnames
