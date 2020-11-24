$NetBSD$

--- Tools/scripts/h2py.py.orig	2020-09-23 12:36:32.044826624 +0000
+++ Tools/scripts/h2py.py
@@ -49,12 +49,15 @@ except KeyError:
     try:
         searchdirs=os.environ['INCLUDE'].split(';')
     except KeyError:
-        searchdirs=['/usr/include']
-        try:
-            searchdirs.insert(0, os.path.join('/usr/include',
+        if sys.platform.find("beos") == 0 or sys.platform.find("haiku1") == 0:
+            searchdirs=os.environ['BEINCLUDES'].split(';')
+        else:
+            searchdirs=['/usr/include']
+            try:
+                searchdirs.insert(0, os.path.join('/usr/include',
                                               os.environ['MULTIARCH']))
-        except KeyError:
-            pass
+            except KeyError:
+                pass
 
 def main():
     global filedict
