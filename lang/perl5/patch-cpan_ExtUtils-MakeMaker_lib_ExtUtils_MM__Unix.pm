--- cpan/ExtUtils-MakeMaker/lib/ExtUtils/MM_Unix.pm.orig	2020-11-19 15:21:25.961544192 +0000
+++ cpan/ExtUtils-MakeMaker/lib/ExtUtils/MM_Unix.pm	2020-11-19 15:24:50.585891840 +0000
@@ -25,6 +25,7 @@
     $Is{OS2}     = $^O eq 'os2';
     $Is{Win32}   = $^O eq 'MSWin32' || $Config{osname} eq 'NetWare';
     $Is{Dos}     = $^O eq 'dos';
+    $Is{Haiku}   = $^O eq 'haiku';
     $Is{VMS}     = $^O eq 'VMS';
     $Is{OSF}     = $^O eq 'dec_osf';
     $Is{IRIX}    = $^O eq 'irix';
