$NetBSD$

--- src/gui/dialogs/qfiledialog.cpp.orig	2013-06-07 05:16:59.040894464 +0000
+++ src/gui/dialogs/qfiledialog.cpp
@@ -295,7 +295,7 @@ Q_GUI_EXPORT _qt_filedialog_save_filenam
   This signal is emitted when the user selects a \a filter.
 */
 
-#if defined(Q_WS_WIN) || defined(Q_WS_MAC)
+#if defined(Q_WS_WIN) || defined(Q_WS_MAC) || defined(Q_WS_HAIKU)
 bool Q_GUI_EXPORT qt_use_native_dialogs = true; // for the benefit of testing tools, until we have a proper API
 #endif
 
@@ -1698,6 +1698,22 @@ extern QStringList qt_win_get_open_file_
 extern QString qt_win_get_existing_directory(const QFileDialogArgs &args);
 #endif
 
+#if defined(Q_WS_HAIKU)
+extern QString qt_haiku_get_open_file_name(const QFileDialogArgs &args,
+                                         QString *initialDirectory,
+                                         QString *selectedFilter);
+
+extern QString qt_haiku_get_save_file_name(const QFileDialogArgs &args,
+                                         QString *initialDirectory,
+                                         QString *selectedFilter);
+
+extern QStringList qt_haiku_get_open_file_names(const QFileDialogArgs &args,
+                                              QString *initialDirectory,
+                                              QString *selectedFilter);
+
+extern QString qt_haiku_get_existing_directory(const QFileDialogArgs &args);
+#endif
+
 /*
     For Symbian file dialogs
 */
@@ -1795,6 +1811,12 @@ QString QFileDialog::getOpenFileName(QWi
     }
 #endif
 
+#if defined(Q_WS_HAIKU)
+    if (qt_use_native_dialogs && !(args.options & DontUseNativeDialog)) {
+        return qt_haiku_get_open_file_name(args, &(args.directory), selectedFilter);
+    }
+#endif
+
     // create a qt dialog
     QFileDialog dialog(args);
     if (selectedFilter && !selectedFilter->isEmpty())
@@ -1888,6 +1910,12 @@ QStringList QFileDialog::getOpenFileName
     }
 #endif
 
+#if defined(Q_WS_HAIKU)
+    if (qt_use_native_dialogs && !(args.options & DontUseNativeDialog)) {
+        return qt_haiku_get_open_file_names(args, &(args.directory), selectedFilter);
+    }
+#endif
+
     // create a qt dialog
     QFileDialog dialog(args);
     if (selectedFilter && !selectedFilter->isEmpty())
@@ -1982,6 +2010,12 @@ QString QFileDialog::getSaveFileName(QWi
     }
 #endif
 
+#if defined(Q_WS_HAIKU)
+    if (qt_use_native_dialogs && !(args.options & DontUseNativeDialog)) {
+        return qt_haiku_get_save_file_name(args, &(args.directory), selectedFilter);
+    }
+#endif
+
     // create a qt dialog
     QFileDialog dialog(args);
     dialog.setAcceptMode(AcceptSave);
@@ -2066,6 +2100,11 @@ QString QFileDialog::getExistingDirector
     }
 #endif
 
+#if defined(Q_WS_HAIKU)
+    if (qt_use_native_dialogs && !(args.options & DontUseNativeDialog) && (options & ShowDirsOnly))
+    	return qt_haiku_get_existing_directory(args);
+#endif
+
     // create a qt dialog
     QFileDialog dialog(args);
     if (dialog.exec() == QDialog::Accepted) {
