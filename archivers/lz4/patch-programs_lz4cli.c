$NetBSD$

--- programs/lz4cli.c.orig	2019-08-15 11:59:59.620232704 +0000
+++ programs/lz4cli.c
@@ -658,7 +658,11 @@ int main(int argc, const char** argv)
         if (!output_filename) output_filename = stdoutmark;
     }
     else{
-        if (!recursive && !UTIL_isRegFile(input_filename)) {
+     #ifdef UTIL_HAS_CREATEFILELIST
+         if (!recursive && !UTIL_isRegFile(input_filename)) {
+      #else
+         if (!UTIL_isRegFile(input_filename)) {
+      #endif
             DISPLAYLEVEL(1, "%s: is not a regular file \n", input_filename);
             exit(1);
         }
