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
libsignifix_la_HEADERS = src/signifix/signifix.h src/signifix/signifix.hxx
libsignifix_la_SOURCES = $(libsignifix_la_HEADERS) src/signifix/signifix.c

check_PROGRAMS = \
metric_unit_prefix \
fixed_significance \
formatting_options \
lower_prefix_bound \
upper_prefix_bound \
upper_prefix_round \
fp_category_safety \
readme_format_test \
readme_format_rate \
readme_format_load \
readme_format_diff

metric_unit_prefix_CXXFLAGS = -Isrc
metric_unit_prefix_LDADD = libsignifix.la
metric_unit_prefix_SOURCES = tests/metric_unit_prefix.cxx

fixed_significance_CXXFLAGS = -Isrc
fixed_significance_LDADD = libsignifix.la
fixed_significance_SOURCES = tests/fixed_significance.cxx

formatting_options_CXXFLAGS = -Isrc
formatting_options_LDADD = libsignifix.la
formatting_options_SOURCES = tests/formatting_options.cxx

lower_prefix_bound_CXXFLAGS = -Isrc
lower_prefix_bound_LDADD = libsignifix.la
lower_prefix_bound_SOURCES = tests/lower_prefix_bound.cxx

upper_prefix_bound_CXXFLAGS = -Isrc
upper_prefix_bound_LDADD = libsignifix.la
upper_prefix_bound_SOURCES = tests/upper_prefix_bound.cxx

upper_prefix_round_CXXFLAGS = -Isrc
upper_prefix_round_LDADD = libsignifix.la
upper_prefix_round_SOURCES = tests/upper_prefix_round.cxx

fp_category_safety_CXXFLAGS = -Isrc
fp_category_safety_LDADD = libsignifix.la
fp_category_safety_SOURCES = tests/fp_category_safety.cxx

readme_format_test_CXXFLAGS = -std=c++14 -Isrc
readme_format_test_LDADD = libsignifix.la
readme_format_test_SOURCES = tests/readme/format_test.cxx

readme_format_rate_CXXFLAGS = -std=c++14 -Isrc
readme_format_rate_LDADD = libsignifix.la
readme_format_rate_SOURCES = tests/readme/format_rate.cxx

readme_format_load_CXXFLAGS = -std=c++14 -Isrc
readme_format_load_LDADD = libsignifix.la
readme_format_load_SOURCES = tests/readme/format_load.cxx

readme_format_diff_CXXFLAGS = -std=c++14 -Isrc
readme_format_diff_LDADD = libsignifix.la
readme_format_diff_SOURCES = tests/readme/format_diff.cxx

TESTS = $(check_PROGRAMS)

if ENABLE_DOC

doxygendir = $(docdir)/html
doxygen_DATA = doc/html/*

$(doxygen_DATA): | doc/html

doc/html: $(libsignifix_la_SOURCES)
	doxygen doc/Doxyfile

clean-local:
	rm -rf doc/html doc/doxygen_sqlite3.db

endif
