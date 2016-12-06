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
//! C source file of libsignifix.
//!
//! @file signifix.c
//!
#ifndef _SIGNIFIX_
#define _SIGNIFIX_

#include "signifix.h"

#include <math.h>
#include <stdio.h>

int signifix_format(char* buffer, double number, char plus) {
	const double factor[] = {
		1e-24, 1e-21, 1e-18, 1e-15, 1e-12, 1e-09, 1e-06, 1e-03,
		1e-00,
		1e+03, 1e+06, 1e+09, 1e+12, 1e+15, 1e+18, 1e+21, 1e+24,
	};
	const char* symbol[] = {
		"y", "z", "a", "f", "p", "n", "µ", "m",
		" ",
		"k", "M", "G", "T", "P", "E", "Z", "Y",
	};
	char sign[2] = "-";
	if (number < 0.0)
		number = -number;
	else
		sign[0] = plus;
	int prefix;
	if (number < factor[8]) {
		if (number < factor[4]) {
			if (number < factor[2])
				prefix = number < factor[1] ? 0 : 1;
			else
				prefix = number < factor[3] ? 2 : 3;
		}
		else {
			if (number < factor[6])
				prefix = number < factor[5] ? 4 : 5;
			else
				prefix = number < factor[7] ? 6 : 7;
		}
	}
	else
	if (number < factor[9])
		prefix = 8;
	else {
		if (number < factor[13]) {
			if (number < factor[11])
				prefix = number < factor[10] ? 9 : 10;
			else
				prefix = number < factor[12] ? 11 : 12;
		} else {
			if (number < factor[15])
				prefix = number < factor[14] ? 13 : 14;
			else
				prefix = number < factor[16] ? 15 : 16;
		}
	}
	if (prefix != 8)
		number = number / factor[prefix];
	int strlen;
	if (roundf(number * 1e+02) < 1e+04) {
		const double lower = roundf(number * 1e+03);
		if (lower < 1e+04) {
			if (lower < 1e+03)
				return SIGNIFIX_ELOWER;
			strlen = snprintf(buffer, SIGNIFIX_BUFLEN,
				"%s%.3f %s", sign, number, symbol[prefix]);
		} else
			strlen = snprintf(buffer, SIGNIFIX_BUFLEN,
				"%s%.2f %s", sign, number, symbol[prefix]);
	} else {
		if (roundf(number * 1e+01) < 1e+04)
			strlen = snprintf(buffer, SIGNIFIX_BUFLEN,
				"%s%.1f %s", sign, number, symbol[prefix]);
		else {
			if (++prefix == sizeof factor / sizeof factor[0])
				return isnan(number) ? SIGNIFIX_EINVAL : SIGNIFIX_EUPPER;
			strlen = snprintf(buffer, SIGNIFIX_BUFLEN,
				"%s1.000 %s", sign, symbol[prefix]);
		}
	}
	if (strlen < 0)
		return SIGNIFIX_EPRINT;
	if (strlen >= SIGNIFIX_BUFLEN)
		return SIGNIFIX_ETRUNC;
	return strlen;
}

#endif
