/* this file is part of greq
 * see greq.c for copyright information
 */

#include <stdio.h>
#include <gtk/gtk.h>
#include <glib.h>
#include "greq.h"

void create_entry_field(gchar *text, gboolean hidden)
{
   GtkWidget *entry, *label, *box;
   
   entry = gtk_entry_new();
   if (!entry) quit (RETURN_ERROR_NOMEM);
   if (hidden) gtk_entry_set_visibility ((GtkEntry*)entry, FALSE);
   gtk_signal_connect ((GtkObject*)entry, key_press_event,
		       GTK_SIGNAL_FUNC (keypress_cb), NULL);
   
   if(text) {
      box = gtk_hbox_new(FALSE, 1);
      if (!box)	quit (RETURN_ERROR_NOMEM);
      label = gtk_label_new(text);
      if (!label) quit (RETURN_ERROR_NOMEM);
      
      gtk_box_pack_start((GtkBox *)box, label, FALSE, TRUE, 0);
      gtk_box_pack_end((GtkBox *)box, entry, FALSE, TRUE, 0);
      add_to_vbox(box);
   } else {
      add_to_vbox(entry);
   }
   widgets = g_slist_append(widgets, entry);
};

void last_entry_default (gchar *text)
{
   GtkWidget *entry;
   
   entry = (GtkWidget *)g_slist_last(widgets)->data;
   if (GTK_IS_ENTRY(entry)) {
      gtk_entry_set_text ((GtkEntry*) entry, text);
      gtk_editable_select_region ((GtkEditable *)entry, 0, -1);
   } else {
      fputs("ERROR: -d must be immediately preceeded by -e\n", stderr);
      quit(RETURN_ERROR_ARG);
   };
};

inline void output_entry (GtkWidget *entry)
{
   fputs(gtk_entry_get_text((GtkEntry *)entry), stdout);
}
