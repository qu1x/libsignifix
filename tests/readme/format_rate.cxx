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
	auto format_rate = [](auto bytes, auto seconds) {
		return signifix::format((double)bytes / (double)seconds) + "B/s";
	};

	assert(format_rate(42'667, 300) == "142.2  B/s");
	assert(format_rate(42'667,  30) == "1.422 kB/s");
	assert(format_rate(42'667,   3) == "14.22 kB/s");
}
