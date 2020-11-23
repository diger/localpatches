$NetBSD: patch-include_ttyutils.h,v 1.1 2017/12/08 08:03:35 adam Exp $

Define values if missing.

--- include/ttyutils.h.orig	2020-11-23 10:04:59.289406976 +0000
+++ include/ttyutils.h
@@ -62,7 +62,11 @@ static inline void reset_virtual_console
 {
 	/* Use defaults of <sys/ttydefaults.h> for base settings */
 #ifndef TTYDEF_IFLAG
-#define TTYDEF_IFLAG	(BRKINT | ICRNL | IMAXBEL | IXON | IXANY)
+ #ifdef IMAXBEL
+ #define TTYDEF_IFLAG	(BRKINT | ICRNL | IMAXBEL | IXON | IXANY)
+ #else
+ #define TTYDEF_IFLAG	(BRKINT | ICRNL | IXON | IXANY)
+ #endif
 #endif
 #ifndef TTYDEF_OFLAG
 #define TTYDEF_OFLAG	(OPOST | ONLCR /*| OXTABS*/)
@@ -73,16 +77,24 @@ static inline void reset_virtual_console
 #ifndef TTYDEF_CFLAG
 #define TTYDEF_CFLAG	(CREAD | CS8 | HUPCL)
 #endif
-	tp->c_iflag |= TTYDEF_IFLAG;
-	tp->c_oflag |= TTYDEF_OFLAG;
-	tp->c_lflag |= TTYDEF_LFLAG;
-
-	if ((flags & UL_TTY_KEEPCFLAGS) == 0) {
-#ifdef CBAUD
-		tp->c_lflag &= ~CBAUD;
+#ifdef TTYDEF_IFLAG
+ 	tp->c_iflag |= TTYDEF_IFLAG;
 #endif
-		tp->c_cflag |= (B38400 | TTYDEF_CFLAG);
-	}
+#ifdef TTYDEF_OFLAG
+ 	tp->c_oflag |= TTYDEF_OFLAG;
+#endif
+#ifdef TTYDEF_LFLAG
+ 	tp->c_lflag |= TTYDEF_LFLAG;
+#endif
+ 
+ 	if ((flags & UL_TTY_KEEPCFLAGS) == 0) {
+ #ifdef CBAUD
+ 		tp->c_lflag &= ~CBAUD;
+ #endif
+#ifdef TTYDEF_CFLAG
+ 		tp->c_cflag |= (B38400 | TTYDEF_CFLAG);
+#endif
+ 	}
 
 	/* Sane setting, allow eight bit characters, no carriage return delay
 	 * the same result as `stty sane cr0 pass8'
@@ -134,7 +146,11 @@ static inline void reset_virtual_console
 #define TABDLY 0
 #endif
 
-	tp->c_iflag |=  (BRKINT | ICRNL | IMAXBEL);
+#ifdef IMAXBEL
+ 	tp->c_iflag |=  (BRKINT | ICRNL | IMAXBEL);
+#else
+	tp->c_iflag |=  (BRKINT | ICRNL);
+#endif
 	tp->c_iflag &= ~(IGNBRK | INLCR | IGNCR | IXOFF | IUCLC | IXANY | ISTRIP);
 	tp->c_oflag |=  (OPOST | ONLCR | NL0 | CR0 | TAB0 | BS0 | VT0 | FF0);
 	tp->c_oflag &= ~(OLCUC | OCRNL | ONOCR | ONLRET | OFILL | \
@@ -164,31 +180,49 @@ static inline void reset_virtual_console
 	 */
 	tp->c_cc[VTIME]    = 0;
 	tp->c_cc[VMIN]     = 1;
-	tp->c_cc[VINTR]    = CINTR;
-	tp->c_cc[VQUIT]    = CQUIT;
-	tp->c_cc[VERASE]   = CERASE; /* ASCII DEL (0177) */
-	tp->c_cc[VKILL]    = CKILL;
-	tp->c_cc[VEOF]     = CEOF;
-#ifdef VSWTC
-	tp->c_cc[VSWTC]    = _POSIX_VDISABLE;
-#elif defined(VSWTCH)
-	tp->c_cc[VSWTCH]   = _POSIX_VDISABLE;
-#endif
-	tp->c_cc[VSTART]   = CSTART;
-	tp->c_cc[VSTOP]    = CSTOP;
-	tp->c_cc[VSUSP]    = CSUSP;
-	tp->c_cc[VEOL]     = _POSIX_VDISABLE;
-#ifndef CREPRINT
-#define CREPRINT	('r' & 037)
-#endif
-	tp->c_cc[VREPRINT] = CREPRINT;
-#ifndef CDISCARD
-#define CDISCARD	('o' & 037)
-#endif
-	tp->c_cc[VDISCARD] = CDISCARD;
-	tp->c_cc[VWERASE]  = CWERASE;
-	tp->c_cc[VLNEXT]   = CLNEXT;
-	tp->c_cc[VEOL2]    = _POSIX_VDISABLE;
-}
+#ifdef CINTR
+ 	tp->c_cc[VINTR]    = CINTR;
+#endif
+#ifdef CQUIT
+ 	tp->c_cc[VQUIT]    = CQUIT;
+#endif
+#ifdef CERASE
+ 	tp->c_cc[VERASE]   = CERASE; /* ASCII DEL (0177) */
+#endif
+#ifdef CKILL
+ 	tp->c_cc[VKILL]    = CKILL;
+#endif
+#ifdef CEOF
+ 	tp->c_cc[VEOF]     = CEOF;
+#endif
+ #ifdef VSWTC
+ 	tp->c_cc[VSWTC]    = _POSIX_VDISABLE;
+ #elif defined(VSWTCH)
+ 	tp->c_cc[VSWTCH]   = _POSIX_VDISABLE;
+ #endif
+#ifdef CSTART
+ 	tp->c_cc[VSTART]   = CSTART;
+#endif
+#ifdef CSTOP
+ 	tp->c_cc[VSTOP]    = CSTOP;
+#endif
+#ifdef CSUSP
+ 	tp->c_cc[VSUSP]    = CSUSP;
+#endif
+ 	tp->c_cc[VEOL]     = _POSIX_VDISABLE;
+#ifdef VREPRINT
+ 	tp->c_cc[VREPRINT] = CREPRINT;
+#endif
+#ifdef VDISCARD
+ 	tp->c_cc[VDISCARD] = CDISCARD;
+#endif
+#ifdef VWERASE
+ 	tp->c_cc[VWERASE]  = CWERASE;
+#endif
+#ifdef CLNEXT
+ 	tp->c_cc[VLNEXT]   = CLNEXT;
+ #endif
+ 	tp->c_cc[VEOL2]    = _POSIX_VDISABLE;
+ }
 
 #endif /* UTIL_LINUX_TTYUTILS_H */
