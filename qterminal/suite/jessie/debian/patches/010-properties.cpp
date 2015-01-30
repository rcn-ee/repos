--- a/src/properties.cpp
+++ b/src/properties.cpp
@@ -31,7 +31,7 @@
 {
     QFont default_font = QApplication::font();
     default_font.setFamily(DEFAULT_FONT);
-    default_font.setPointSize(12);
+    default_font.setPointSize(10);
     default_font.setStyleHint(QFont::TypeWriter);
     return default_font;
 }
