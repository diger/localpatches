$NetBSD$

--- Lib/webbrowser.py.orig	2020-08-15 05:20:16.033554432 +0000
+++ Lib/webbrowser.py
@@ -538,6 +538,11 @@ def register_standard_browsers():
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
