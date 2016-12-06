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
#include <limits>
#include <cmath>

int main() {
	try {
		signifix::format(0.0);
		assert(false);
	}
	catch (signifix::lower_error& error) {
		assert(error.why() == 0.0);
	}
	catch (...) {
		assert(false);
	}

	try {
		signifix::format(-std::numeric_limits<double>::infinity());
		assert(false);
	}
	catch (signifix::upper_error& error) {
		assert(error.why() == -std::numeric_limits<double>::infinity());
	}
	catch (...) {
		assert(false);
	}

	try {
		signifix::format(std::numeric_limits<double>::infinity());
		assert(false);
	}
	catch (signifix::upper_error& error) {
		assert(error.why() == std::numeric_limits<double>::infinity());
	}
	catch (...) {
		assert(false);
	}

	try {
		signifix::format(std::numeric_limits<double>::quiet_NaN());
		assert(false);
	}
	catch (signifix::inval_error& error) {
		assert(std::isnan(error.why()));
	}
	catch (...) {
		assert(false);
	}
}
