#include "window1.hh"
#include "window1_glade.hh"

Window1::Window1() {
    gtk_init(0, nullptr);

    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "output.glade", nullptr);

    list_store = GTK_LIST_STORE(gtk_builder_get_object(builder, "liststore1"));
}
