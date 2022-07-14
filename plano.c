#include <cairo.h>
#include <gtk/gtk.h>


int main(int argc, char *argv[]) {
  GtkWidget *window;
  GtkWidget *darea;
  cairo_t *cr;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  darea = gtk_drawing_area_new();
  gtk_container_add(GTK_CONTAINER(window), darea);
  cairo_move_to(cr, 0, 0);
  cairo_line_to(cr, 500, 500);

 
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
 
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 800, 600); 
  gtk_window_set_title(GTK_WINDOW(window), "Plano Cartesiano");

  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}