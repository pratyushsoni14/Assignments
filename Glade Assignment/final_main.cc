#include "window1.hh"
#include "window1_glade.hh"

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    Window1 window1;  

    GtkWidget *window = GTK_WIDGET(gtk_builder_get_object(builder, "window1"));
    GtkWidget *entry = GTK_WIDGET(gtk_builder_get_object(builder, "entry1"));
    GtkWidget *submit_button = GTK_WIDGET(gtk_builder_get_object(builder, "button1"));
    GtkWidget *department_combo = GTK_WIDGET(gtk_builder_get_object(builder, "combobox1"));

    g_signal_connect(submit_button, "clicked", G_CALLBACK(on_submit_button_clicked), entry);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}


// g++ -c window1_glade.cc window1.cc final_main.cc `pkg-config --cflags gtk+-3.0`
// g++ -o final window1_glade.o window1.o final_main.o `pkg-config --libs gtk+-3.0`
// ./final
