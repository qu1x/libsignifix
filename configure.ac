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

AC_INIT([Signifix], [0.2.0],
	[n3vu0r@qu1x.org], [libsignifix], [https://qu1x.org/signifix])

AC_CONFIG_MACRO_DIR([m4])

AC_CONFIG_SRCDIR([src/signifix/signifix.hxx])

AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE

LT_INIT([disable-static])

AC_CHECK_PROG([HAVE_DOXYGEN], [doxygen], [yes], [no])
AM_CONDITIONAL([HAVE_DOXYGEN], [test x$HAVE_DOXYGEN = xyes])

AC_ARG_ENABLE([doc], AS_HELP_STRING([--disable-doc],
	[do not generate documentation with doxygen]), [], [enable_doc=yes])
AM_CONDITIONAL([ENABLE_DOC], [test x$enable_doc = xyes])
AM_COND_IF([ENABLE_DOC], [
	AM_COND_IF([HAVE_DOXYGEN], [AC_CONFIG_FILES([doc/Doxyfile])],
		[AC_MSG_ERROR([doxygen not found, skip with --disable-doc])])
])

AC_PROG_CXX

AC_CONFIG_FILES([Makefile])

AC_OUTPUT

printf "
$PACKAGE_STRING

doc: $enable_doc

"
