$NetBSD$

--- Lib/webbrowser.py.orig	2020-09-23 12:36:32.036700160 +0000
+++ Lib/webbrowser.py
@@ -1,4 +1,4 @@
-#! /usr/bin/env python3
+#!/boot/common/bin/python3.8
 """Interfaces for launching and remotely controlling Web browsers."""
 # Maintained by Georg Brandl.
 
@@ -543,6 +543,11 @@ def register_standard_browsers():
                         "netscape", "opera", iexplore):
             if shutil.which(browser):
                 register(browser, None, BackgroundBrowser(browser))
+    elif sys.platform[:5] == "haiku":
+        # First try to use the default configured browser
+        register("haiku-default", None, GenericBrowser("open"))
+        # Fall back to WebPositive as the standard browser of Haiku
+        register("webpositive", None, BackgroundBrowser("WebPositive"))
     else:
         # Prefer X browsers if present
         if os.environ.get("DISPLAY") or os.environ.get("WAYLAND_DISPLAY"):
