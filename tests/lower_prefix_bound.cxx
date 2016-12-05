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
	assert(signifix::format(-0.99951e-24) == "-1.000 y");
	bool lower_error = false;
	try {
		signifix::format(-0.99949e-24);
	}
	catch (signifix::lower_error&) {
		lower_error = true;
	}
	assert(lower_error);
}
