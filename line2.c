#include <gtk/gtk.h>

gboolean draw_circle (GtkWidget *widget, cairo_t *cr, gpointer data) {
  guint width, height;
  GdkRGBA color;

  width = gtk_widget_get_allocated_width(widget);
  height = gtk_widget_get_allocated_height(widget);

  cairo_arc(cr, width/2.0, height/2.0, MIN(width, height)/4.0, 0, 2*G_PI);

  color.red = 1;
  color.green = 0;
  color.blue = 0;
  color.alpha = 1;
  gdk_cairo_set_source_rgba(cr, &color);
  cairo_set_line_width(cr, 5);

  cairo_stroke(cr);

  return FALSE;
}

gboolean draw_dot (GtkWidget *widget, cairo_t *cr, gpointer data) {
  guint width, height;
  GdkRGBA color;

  width = gtk_widget_get_allocated_width(widget);
  height = gtk_widget_get_allocated_height(widget);

  cairo_arc(cr, width/2.0, height/2.0, 1, 0, 2*G_PI);

  color.red = 0;
  color.green = 0;
  color.blue = 1;
  color.alpha = 1;
  gdk_cairo_set_source_rgba(cr, &color);
  cairo_set_line_width(cr, 5);

  cairo_stroke(cr);

  return FALSE;
}

gboolean draw_plan (GtkWidget *widget, cairo_t *cr, gpointer data) {
  guint width, height;
  GdkRGBA color;

  width = gtk_widget_get_allocated_width(widget);
  height = gtk_widget_get_allocated_height(widget);

  cairo_move_to (cr, 0, height/2.0);
  cairo_line_to (cr, width, height/2.0);
  cairo_move_to (cr, width/2.0, height);
  cairo_line_to (cr, width/2.0, 0);

  cairo_set_source_rgb (cr, 1, 0, 0);
  cairo_set_line_width (cr, 5);

  cairo_stroke (cr);

  return FALSE;
}

gint main(int argc,char *argv[]) {
  GtkWidget *window, *drawing_area;

  gtk_init(&argc, &argv);
  
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 1200, 800);
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  drawing_area = gtk_drawing_area_new();
  gtk_container_add(GTK_CONTAINER(window), drawing_area);
  g_signal_connect(G_OBJECT(drawing_area), "draw", G_CALLBACK(draw_plan), NULL);
  g_signal_connect(G_OBJECT(drawing_area), "draw", G_CALLBACK(draw_circle), NULL);
  g_signal_connect(G_OBJECT(drawing_area), "draw", G_CALLBACK(draw_dot), NULL);

  gtk_widget_show_all(window);
  gtk_main();

  return 0;
}