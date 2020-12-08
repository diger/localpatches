$NetBSD$

--- xmlif/xmlif.l.orig	2015-02-11 12:20:51.005242880 +0000
+++ xmlif/xmlif.l
@@ -46,22 +46,22 @@ static int nselections;		/* number of se
 static ifsense;			/* sense of last `if' or unless seen */
 static char *attribute;		/* last attribute scanned */
 
-struct stack_t {
+struct stack_type {
     int			matched;	/* matched at current level */
     int			suppressed;    /* suppressed branch? */
-    struct stack_t	*up;
+    struct stack_type	*up;
 };
-static struct stack_t head, *end = &head;
+static struct stack_type head, *end = &head;
 
 static void push_level(void)
 /* create activation record for the current level */
 {
-    struct stack_t *newelt;
+    struct stack_type *newelt;
 
 #ifdef DEBUG
     fprintf(stderr, "{push_level()}");
 #endif /* DEBUG */
-    newelt = (struct stack_t *)malloc(sizeof(struct stack_t));
+    newelt = (struct stack_type *)malloc(sizeof(struct stack_type));
     newelt->up = end;
     end = newelt;
 
@@ -72,7 +72,7 @@ static void push_level(void)
 static void pop_level(void)
 /* delete activation record for the current level */
 {
-    struct stack_t *up = end->up;
+    struct stack_type *up = end->up;
 
 #ifdef DEBUG
     fprintf(stderr, "{pop_level()}");
@@ -96,7 +96,7 @@ static void stash_attribute(char *attr)
 static void end_attribute(void)
 /* we've seen all the attributes of a conditional, process them now */
 {
-    struct stack_t	*up;
+    struct stack_type	*up;
 
     if (attribute)
 	free(attribute);
