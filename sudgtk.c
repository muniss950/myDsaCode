#include <gtk/gtk.h>

GtkWidget *grid[9][9];

void button_clicked(GtkWidget *widget, gpointer data) {
    // Handle button click here
    g_print("Button clicked: %s\n", gtk_button_get_label(GTK_BUTTON(widget)));
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Sudoku-like Frontend");
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *table = gtk_table_new(9, 9, TRUE);
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char button_label[2];
            snprintf(button_label, sizeof(button_label), "%d", 0);
            grid[i][j] = gtk_button_new_with_label(button_label);
            g_signal_connect(grid[i][j], "clicked", G_CALLBACK(button_clicked), NULL);
            gtk_table_attach_defaults(GTK_TABLE(table), grid[i][j], j, j + 1, i, i + 1);
        }
    }

    GtkWidget *vbox = gtk_vbox_new(FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), table, TRUE, TRUE, 0);

    gtk_container_add(GTK_CONTAINER(window), vbox);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}

