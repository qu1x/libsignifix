// This file is part of Signifix, see <https://qu1x.org/signifix>.
//
// Copyright (c) 2016 Rouven Spreckels <n3vu0r@qu1x.org>
//
// Signifix is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License version 3
// as published by the Free Software Foundation on 29 June 2007.
//
// Signifix is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Signifix. If not, see <https://www.gnu.org/licenses>.

//!
//! C header file of libsignifix.
//!
//! @file signifix.h
//!
#ifndef _SIGNIFIX_H
#define _SIGNIFIX_H

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

//!
//! The string buffer must be of at least this length.
//!
#define SIGNIFIX_BUFLEN 10

//!
//! Prefix only negative numbers, with '-'.
//!
#define SIGNIFIX_PROPER  0

//!
//! Additionally prefix positive numbers, with '+'.
//!

#define SIGNIFIX_SIGNED '+'

//!
//! Additionally prefix positive numbers, with ' '.
//!
#define SIGNIFIX_SPACED ' '

//!
//! Out of upper bound ±999.9 Y (≅ ±1e+27).
//!
#define SIGNIFIX_EUPPER -5

//!
//! Out of lower bound ±1.000 y (= ±1e-24).
//!
#define SIGNIFIX_ELOWER -4

//!
//! Invalid argument being not a number (NaN).
//!
#define SIGNIFIX_EINVAL -3

//!
//! Truncation due to undersized buffer.
//!
#define SIGNIFIX_ETRUNC -2

//!
//! Internal formatting error.
//!
#define SIGNIFIX_EPRINT -1

//!
//! Obtains the error string related to an error number.
//!
//! @param ERRNUM An error number returned by signifix_format().
//!
#define SIGNIFIX_ERRSTR(ERRNUM) signifix_errstr[(ERRNUM) + \
	sizeof signifix_errstr / sizeof signifix_errstr[0]]

//!
//! Error strings to be obtained by #SIGNIFIX_ERRSTR().
//!
const char* signifix_errstr[] = {
	"Out of upper bound ±999.9 Y (≅ ±1e+27)",
	"Out of lower bound ±1.000 y (= ±1e-24)",
	"Invalid argument being not a number (NaN)",
	"Truncation due to undersized buffer",
	"Internal formatting error",
};

//!
//! Number Formatter of Fixed Significance with Metric Unit Prefix.
//!
//! Formats a number to a string of a fixed number of significant figures and a
//! fixed number of resulting characters by automatically choosing the metric
//! unit prefix and appropriately adjusting the floating point precision.
//!
//! @param buffer  The buffer of the formatted string, allocated and freed by
//!                the caller. Must be of at least ::SIGNIFIX_BUFLEN bytes.
//! @param number  The number to be formatted.
//! @param plus    The plus sign character. Predefined values are
//!                ::SIGNIFIX_PROPER, ::SIGNIFIX_SIGNED and ::SIGNIFIX_SPACED.
//!
//! @return The string length in bytes of the formatted number if successful,
//!         otherwise a negative error number. The error string related to an
//!         error number can be obtained by #SIGNIFIX_ERRSTR(). Possible errors
//!         are #SIGNIFIX_EUPPER, #SIGNIFIX_ELOWER, #SIGNIFIX_EINVAL,
//!         #SIGNIFIX_ETRUNC, and #SIGNIFIX_EPRINT.
//!
int signifix_format(char* buffer, double number, char plus);

#endif
