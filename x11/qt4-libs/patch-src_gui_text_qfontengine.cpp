$NetBSD$

--- src/gui/text/qfontengine.cpp.orig	2013-06-07 05:16:59.056623104 +0000
+++ src/gui/text/qfontengine.cpp
@@ -762,7 +762,7 @@ QFontEngineGlyphCache *QFontEngine::glyp
     return 0;
 }
 
-#if defined(Q_WS_WIN) || defined(Q_WS_X11) || defined(Q_WS_QWS) || defined(Q_WS_QPA) || defined(Q_OS_SYMBIAN)
+#if defined(Q_WS_WIN) || defined(Q_WS_X11) || defined(Q_WS_QWS) || defined(Q_WS_QPA) || defined(Q_OS_SYMBIAN) || defined(Q_WS_HAIKU)
 static inline QFixed kerning(int left, int right, const QFontEngine::KernPair *pairs, int numPairs)
 {
     uint left_right = (left << 16) + right;
