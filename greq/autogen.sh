#! /bin/sh
aclocal -I ./ac && \
automake --add-missing && \
autoconf && \
echo "configure script generated. You may run it with ./configure"
