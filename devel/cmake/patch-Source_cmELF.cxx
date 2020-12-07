$NetBSD$

--- Source/cmELF.cxx.orig	2020-10-06 12:28:17.918028288 +0000
+++ Source/cmELF.cxx
@@ -20,17 +20,17 @@
 // Include the ELF format information system header.
 #if defined(__OpenBSD__)
 #  include <elf_abi.h>
-#elif defined(__HAIKU__)
-#  include <elf32.h>
-#  include <elf64.h>
-using Elf32_Ehdr = struct Elf32_Ehdr;
-using Elf32_Shdr = struct Elf32_Shdr;
-using Elf32_Sym = struct Elf32_Sym;
-using Elf32_Rel = struct Elf32_Rel;
-using Elf32_Rela = struct Elf32_Rela;
+#else
+#  include <elf.h>
+# ifndef ELFMAG0
 #  define ELFMAG0 0x7F
+# endif
+# ifndef ELFMAG1
 #  define ELFMAG1 'E'
-#  define ELFMAG2 'L'
+# ifndef ELFMAG2
+ #  define ELFMAG2 'L'
+# endif
+# ifndef ELFMAG3
 #  define ELFMAG3 'F'
 #  define ET_NONE 0
 #  define ET_REL 1
@@ -42,6 +42,7 @@ using Elf32_Rela = struct Elf32_Rela;
 #  define EM_PPC 20
 #else
 #  include <elf.h>
+# endif
 #endif
 #if defined(__sun)
 #  include <sys/link.h> // For dynamic section information
