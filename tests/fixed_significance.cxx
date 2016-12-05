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

#include <signifix/signifix.hxx>

#include <cassert>

int main() {
	assert(signifix::format(1e+02) == "100.0  ");
	assert(signifix::format(1e+03) == "1.000 k");
	assert(signifix::format(1e+04) == "10.00 k");
	assert(signifix::format(1e+05) == "100.0 k");
	assert(signifix::format(1e+06) == "1.000 M");
}
