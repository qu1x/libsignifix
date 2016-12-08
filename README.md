> This file is part of Signifix, see <https://qu1x.org/signifix>.
> 
> Copyright (c) 2016 Rouven Spreckels <n3vu0r@qu1x.org>
> 
> Signifix is free software: you can redistribute it and/or modify
> it under the terms of the GNU Lesser General Public License version 3
> as published by the Free Software Foundation on 29 June 2007.
> 
> Signifix is distributed in the hope that it will be useful,
> but WITHOUT ANY WARRANTY; without even the implied warranty of
> MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
> GNU Lesser General Public License for more details.
> 
> You should have received a copy of the GNU Lesser General Public License
> along with Signifix. If not, see <https://www.gnu.org/licenses>.

# libsignifix

Number Formatter of Fixed Significance with Metric Unit Prefix

[![Build Status](https://travis-ci.org/qu1x/libsignifix.svg?branch=master)](https://travis-ci.org/qu1x/libsignifix)

[Documentation](https://qu1x.org/file/libsignifix-0.2.0/index.html)

Signifix guarantees a fixed number of significant figures and a fixed number
of resulting characters by automatically choosing the metric unit prefix and
appropriately adjusting the floating point precision.

This is a `C99` compatible library (`signifix.h`, `signifix.c`) with a `C++98`
compatible header only wrapper (`signifix.hxx`).

# Examples

Following examples make use of `C++14` features.

The fixed number of significant figures and resulting characters prevent the
digits and prefixed units from jumping to the left or right:

```c++
#include <signifix/signifix.hxx>

#include <cassert>

int main() {
	assert(signifix::format(1e-04) == "100.0 µ");
	assert(signifix::format(1e-03) == "1.000 m");
	assert(signifix::format(1e-02) == "10.00 m");
	assert(signifix::format(1e-01) == "100.0 m");
	assert(signifix::format(1e+00) == "1.000  ");
	assert(signifix::format(1e+01) == "10.00  ");
	assert(signifix::format(1e+02) == "100.0  ");
	assert(signifix::format(1e+03) == "1.000 k");
	assert(signifix::format(1e+04) == "10.00 k");
	assert(signifix::format(1e+05) == "100.0 k");
	assert(signifix::format(1e+06) == "1.000 M");
}
```

This is useful to smoothly refresh a transfer rate inside a terminal:

```c++
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
```

Or to monitor a measured quantity like an electrical current including its
direction with an optional space placeholder to align with negative values.

```c++
#include <signifix/signifix.hxx>

#include <cassert>

int main() {
	auto format_load = [](auto current) {
		return signifix::format(current, signifix::SPACED) + "A";
	};

	assert(format_load( 1.476e-06) == " 1.476 µA");
	assert(format_load(-2.927e-06) == "-2.927 µA");
}
```

In case of displaying a file size difference after modification, a plus sign
might be preferred for positive values:

```c++
#include <signifix/signifix.hxx>

#include <cassert>

int main() {
	auto format_diff = [](auto curr, auto prev) {
		return signifix::format(curr - prev, signifix::SIGNED) + "B";
	};

	assert(format_diff(78'346, 57'393) == "+20.95 kB");
	assert(format_diff(27'473, 46'839) == "-19.37 kB");
}
```

# Installation

## Either getting a release

1. Download stable source distribution tarball.

		wget https://qu1x.org/file/libsignifix-0.2.0.tar.xz

2. Extract and enter.

		tar -xJf libsignifix-0.2.0.tar.xz
		cd libsignifix-0.2.0

## Or getting a snapshot

Required dependencies:

		git autoreconf libtool

1. Clone repository.

		git clone https://github.com/qu1x/libsignifix.git

2. Enter and generate latest source distribution.

		cd libsignifix
		./bootstrap

## Installing one of them

Required dependencies:

		build-essential

Optional dependencies:

		doxygen

1. Configure, build, and install.

To not generate documentation with `doxygen`, disable it with `--disable-doc`.

		./configure CFLAGS="$CFLAGS -std=c99"
		make
		sudo make install

2. Keep to uninstall someday.

		sudo make uninstall

# Version

libsignifix-0.2.0 <https://qu1x.org/signifix>

# License

GNU Lesser General Public License version 3

# Authors

* Copyright (c) 2016 Rouven Spreckels <n3vu0r@qu1x.org>

