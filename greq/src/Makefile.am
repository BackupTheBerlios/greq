-include local_options.mk
bin_PROGRAMS = greq
greq_SOURCES = greq.c check_button.c entry_field.c okay_cancel.c\
	       option_menu.c greq.h
LDFLAGS = `gtk-config --libs`
CFLAGS += `gtk-config --cflags`
MOSTLYCLEANFILES= *~
MAINTAINERCLEANFILES = Makefile.in stamp-h.in
