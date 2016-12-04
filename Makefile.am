# This file is part of Signifix, see <https://qu1x.org/signifix>.
#
# Copyright (c) 2016 Rouven Spreckels <n3vu0r@qu1x.org>
#
# Signifix is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License version 3
# as published by the Free Software Foundation on 29 June 2007.
#
# Signifix is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with Signifix. If not, see <https://www.gnu.org/licenses>.

ACLOCAL_AMFLAGS = -I m4
AUTOMAKE_OPTIONS = subdir-objects

lib_LTLIBRARIES = libsignifix.la

libsignifix_ladir = $(includedir)/signifix
libsignifix_la_LDFLAGS = -version-info 0:0:0
libsignifix_la_HEADERS = src/signifix.h src/signifix.hxx
libsignifix_la_SOURCES = $(libsignifix_la_HEADERS) src/signifix.c

if ENABLE_DOC

doxygendir = $(docdir)/html
doxygen_DATA = doc/html/*

$(doxygen_DATA): | doc/html

doc/html: $(libsignifix_la_SOURCES)
	doxygen doc/Doxyfile

clean-local:
	rm -rf doc/html doc/doxygen_sqlite3.db

endif
