$NetBSD: patch-Lib_ctypes_util.py,v 1.2 2019/05/02 12:50:42 wiedi Exp $

Fallback to clang.

Look for shared libraries in PkgSrc prefix.
Note: /usr/local will get replaced by SUBST.

Pull in patch for http://bugs.python.org/issue23287 for SunOS

--- Lib/ctypes/util.py.orig	2020-11-24 10:05:30.487849984 +0000
+++ Lib/ctypes/util.py
@@ -235,6 +235,56 @@ elif os.name == "posix":
         def find_library(name, is64 = False):
             return _get_soname(_findLib_path(name, is64) or _findLib_gcc(name))
 
+    elif sys.platform.startswith("haiku"):
+
+        def _num_version(libname):
+            # "libxyz.so.MAJOR.MINOR" => [ MAJOR, MINOR ]
+            parts = libname.split('.')
+            nums = []
+            try:
+                while parts:
+                    nums.insert(0, int(parts.pop()))
+            except ValueError:
+                pass
+            return nums or [sys.maxint]
+
+        def find_library(name):
+            if name in ('c', 'm'):
+                return find_library('root')
+            for directory in os.environ['LIBRARY_PATH'].split(os.pathsep):
+                if directory.startswith("%A/"):
+                    directory = directory.replace('%A',
+                        os.path.dirname(os.path.abspath(sys.argv[0] or os.getcwd())))
+
+                if not os.path.isdir(directory):
+                    continue
+
+                # try direct match
+                fname = os.path.join(directory, name)
+                if os.path.isfile(fname):
+                    return fname
+
+                fname = os.path.join(directory, 'lib%s.so' % name)
+                if os.path.isfile(fname):
+                    return fname
+
+                # no exact matching in this directroy
+                # collect versioned candidates, if any
+                candidates = []
+                pattern = re.compile(r'lib%s\.so\.\S+' % re.escape(name))
+                for entry in os.listdir(directory):
+                    if not os.path.isfile(os.path.join(directory, entry)):
+                        continue
+
+                    if re.match(pattern, entry):
+                        candidates.append(os.path.join(directory, entry))
+
+                if candidates:
+                    # return latest version found
+                    candidates.sort(key=_num_version)
+                    return candidates[-1]
+
+            return None
     else:
 
         def _findSoname_ldconfig(name):
@@ -332,6 +382,12 @@ def test():
             print(f"crypt\t:: {cdll.LoadLibrary(find_library('crypt'))}")
             print(f"crypto\t:: {find_library('crypto')}")
             print(f"crypto\t:: {cdll.LoadLibrary(find_library('crypto'))}")
+        elif sys.platform.startswith("haiku"):
+            print(find_library("libbz2.so.1.0"))
+            print(find_library("tracker"))
+            print(find_library("media"))
+            print(cdll.LoadLibrary(find_library("tracker")))
+            print(cdll.LoadLibrary("libmedia.so"))
         else:
             print(cdll.LoadLibrary("libm.so"))
             print(cdll.LoadLibrary("libcrypt.so"))
