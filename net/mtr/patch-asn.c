$NetBSD$

--- asn.c.orig	2014-06-06 09:04:45.854065152 +0000
+++ asn.c
@@ -236,7 +236,7 @@ char *get_ipinfo(ip_t *addr) {
 #ifdef IIDEBUG
         syslog(LOG_INFO, ">> Search: %s", key);
 #endif
-        item.key = key;;
+        item.keyr = key;;
         ENTRY *found_item;
         if ((found_item = hsearch(item, FIND))) {
             if (!(val = (*((items_t*)found_item->data))[ipinfo_no]))
@@ -256,7 +256,7 @@ char *get_ipinfo(ip_t *addr) {
             syslog(LOG_INFO, "Looked up: %s", key);
 #endif
             if (iihash)
-                if ((item.key = strdup(key))) {
+                if ((item.keyr = strdup(key))) {
                     item.data = items;
                     hsearch(item, ENTER);
 #ifdef IIDEBUG
