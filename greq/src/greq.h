#ifdef DEBUG
  #define Debug printf
  #include <stdio.h>
#else
  #define Debug(x,...)
#endif

int create_option_menu(int optind, char *optarg, char *argv[]);
void output_option_menu(GtkWidget *m);
void create_check_button (gchar *label, gboolean toggled);
inline void output_check_button(GtkWidget *w);
void create_entry_field (gchar *text, gboolean hidden);
inline void output_entry (GtkWidget *w);
void last_entry_default (gchar *text);
void create_ok_button (gchar *label);
void ok_cb (GtkWidget *w, void *v);
void create_cancel_button(gchar *label);
void cancel_cb (GtkWidget *w, void *v);
void quit (int code);
inline void add_to_vbox(GtkWidget *child);
gint keypress_cb (GtkWidget *w, GdkEvent *e, void *v);

enum
{
   RETURN_OK,
   RETURN_ERROR_CANCEL,
   RETURN_ERROR_ARG,
   RETURN_ERROR_NOMEM
};

#ifdef MAIN_PROGRAM
   #define global
   char* key_press_event = "key_press_event";
#else
   #define global extern
   #define FIELD_SEPARATOR '\a'
   extern char* key_press_event;
#endif

global GSList *widgets;
global GtkWidget *win, *msgbox;
