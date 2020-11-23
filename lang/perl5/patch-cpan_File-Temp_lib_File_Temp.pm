--- cpan/File-Temp/lib/File/Temp.pm.orig	2020-11-19 15:50:45.589299712 +0000
+++ cpan/File-Temp/lib/File/Temp.pm	2020-11-19 15:51:55.971505664 +0000
@@ -2142,7 +2142,8 @@
     # On NFS the link count may still be 1 but we can't know that
     # we are on NFS.  Since we can't be sure, we'll defer it
 
-    return 1 if $fh[3] == 0 || $^O eq 'cygwin';
+    # On haiku, the link count seems to be always 1 (at least for BFS)
+    return 1 if $fh[3] == 0 || $^O eq 'cygwin' || $^O eq 'haiku';
   }
   # fall-through if we can't unlink now
   _deferred_unlink($fh, $path, 0);
