--- cpan/File-Temp/t/lock.t.orig	2020-11-19 15:48:32.567541760 +0000
+++ cpan/File-Temp/t/lock.t	2020-11-19 15:48:36.553648128 +0000
@@ -9,6 +9,8 @@
 # see if we have O_EXLOCK
   eval { &Fcntl::O_EXLOCK; };
   if ($@) {
+  if ($@  || $^O eq 'haiku') {
+    # haiku doesn't implement O_EXLOCK yet (but it defines the value)
     plan skip_all => 'Do not seem to have O_EXLOCK';
   } else {
     plan tests => 4;
