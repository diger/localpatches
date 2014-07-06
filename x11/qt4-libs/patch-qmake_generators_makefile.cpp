$NetBSD$

--- qmake/generators/makefile.cpp.orig	2013-06-07 05:17:01.018087936 +0000
+++ qmake/generators/makefile.cpp
@@ -2208,6 +2208,8 @@ QString MakefileGenerator::buildArgs(con
             ret += " -unix";
         else if (Option::target_mode == Option::TARG_WIN_MODE)
             ret += " -win32";
+        else if(Option::target_mode == Option::TARG_HAIKU_MODE)
+            ret += " -haiku";
     }
 
     //configs
