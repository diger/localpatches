--- cpan/ExtUtils-MakeMaker/lib/ExtUtils/MM.pm.orig	2020-11-19 15:41:31.487325696 +0000
+++ cpan/ExtUtils-MakeMaker/lib/ExtUtils/MM.pm	2020-11-19 15:41:39.460062720 +0000
@@ -60,7 +60,8 @@
 $Is{UWIN}   = $^O =~ /^uwin(-nt)?$/;
 $Is{Cygwin} = $^O eq 'cygwin';
 $Is{NW5}    = $Config{osname} eq 'NetWare';  # intentional
-$Is{BeOS}   = ($^O =~ /beos/i or $^O eq 'haiku');
+$Is{BeOS}   = $^O =~ /beos/i;
+$Is{Haiku}  = $^O eq 'haiku';
 $Is{DOS}    = $^O eq 'dos';
 if( $Is{NW5} ) {
     $^O = 'NetWare';
