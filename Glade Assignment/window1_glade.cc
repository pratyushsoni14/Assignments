#include "window1_glade.hh"

GtkBuilder *builder;
GtkListStore *list_store;

gchar *on_department_combo_changed(GtkComboBox *combo_box) {
    gchar *department = nullptr;
    GtkTreeIter iter;

    if (gtk_combo_box_get_active_iter(combo_box, &iter)) {
        GtkTreeModel *model = gtk_combo_box_get_model(combo_box);
        gtk_tree_model_get(model, &iter, 0, &department, -1);
    }

    return department;
}

void on_submit_button_clicked(GtkWidget *button, gpointer user_data) {
    GtkWidget *entry = GTK_WIDGET(user_data);
    GtkWidget *department_combo = GTK_WIDGET(gtk_builder_get_object(builder, "combobox1"));
    GtkWidget *male_radio = GTK_WIDGET(gtk_builder_get_object(builder, "male"));
    GtkWidget *female_radio = GTK_WIDGET(gtk_builder_get_object(builder, "female"));
    GtkWidget *treeview = GTK_WIDGET(gtk_builder_get_object(builder, "treeview1"));

    gchar *department = on_department_combo_changed(GTK_COMBO_BOX(department_combo));

    const gchar *text = gtk_entry_get_text(GTK_ENTRY(entry));

    const gchar *gender = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(male_radio)) ? "Male" : "Female";

    GtkTreeIter iter;
    gtk_list_store_append(list_store, &iter);
    gtk_list_store_set(list_store, &iter, 0, text, 1, department ? department : "Not selected", 2, gender, -1);

    g_print("Submitted:\n");
    g_print("Name: %s\n", text);
    g_print("Department: %s\n", department ? department : "Not selected");
    g_print("Gender: %s\n", gender);

    gtk_entry_set_text(GTK_ENTRY(entry), "");

    gtk_combo_box_set_active(GTK_COMBO_BOX(department_combo), -1);

    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(male_radio), FALSE);
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(female_radio), FALSE);

    g_free(department);
}
