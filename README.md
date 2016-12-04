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

[Documentation](https://qu1x.org/file/libsignifix-0.1.0/index.html)

Signifix guarantees a fixed number of significant figures and a fixed number
of resulting characters by automatically choosing the metric unit prefix and
appropriately adjusting the floating point precision.

# Installation

## Either getting a release

1. Download stable source distribution tarball.

		wget https://qu1x.org/file/libsignifix-0.1.0.tar.xz

2. Extract and enter.

		tar -xJf libsignifix-0.1.0.tar.xz
		cd libsignifix-0.1.0

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

libsignifix-0.1.0 <https://qu1x.org/signifix>

# License

GNU Lesser General Public License version 3

# Authors

* Copyright (c) 2016 Rouven Spreckels <n3vu0r@qu1x.org>

