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
//! C++ header file of libsignifix.
//!
//! Wraps the C header file of libsignifix by making use of C++ strings and
//! exception based error handling intead of C strings and return code based
//! error handling.
//!
//! @file signifix.hxx
//!
#ifndef _SIGNIFIX_HXX
#define _SIGNIFIX_HXX

#include <string>
#include <sstream>
#include <iomanip>
#include <exception>

extern "C" {
#include "signifix.h"
}

//!
//! C++ encapsulation of libsignifix.
//!
namespace signifix {
	//!
	//! Wraps #SIGNIFIX_PROPER.
	//!
	const char PROPER = SIGNIFIX_PROPER;

	//!
	//! Wraps #SIGNIFIX_SIGNED.
	//!
	const char SIGNED = SIGNIFIX_SIGNED;

	//!
	//! Wraps #SIGNIFIX_SPACED.
	//!
	const char SPACED = SIGNIFIX_SPACED;

	//!
	//! Error abstraction implementing its #description formatting.
	//!
	class error: public std::exception {
		//!
		//! The number causing this error.
		//!
		double number;
	protected:
		//!
		//! An #signifix_errstr formatted with the number causing this error.
		//!
		std::string description;

		//!
		//! Formats and stores the error #description.
		//!
		//! @param errnum  The error number returned by signifix_format().
		//! @param number  The number causing this error.
		//!
		error(int errnum, double number): number(number) {
			std::ostringstream err;
			err << SIGNIFIX_ERRSTR(errnum);
			if (errnum != SIGNIFIX_EINVAL)
				err << " for number " << std::setprecision(4) << number;
			description = err.str();
		}
	public:
		//!
		//! The number causing this error.
		//!
		//! @return  The #number.
		//!
		double why() const {
			return number;
		}

		//!
		//! Error description.
		//!
		//! @return  The #description.
		//!
		virtual const char* what() const throw() {
			return description.c_str();
		}

		virtual ~error() throw() {}
	};

	//!
	//! Wraps #SIGNIFIX_EUPPER and its #description.
	//!
	class upper_error: public error {
		//!
		//! Invokes signifix::error::error() with #SIGNIFIX_EUPPER.
		//!
		//! @param number  The number causing this error.
		//!
		public: upper_error(double number): error(SIGNIFIX_EUPPER, number) {};
	};

	//!
	//! Wraps #SIGNIFIX_ELOWER and its #description.
	//!
	class lower_error: public error {
		//!
		//! Invokes signifix::error::error() with #SIGNIFIX_ELOWER.
		//!
		//! @param number  The number causing this error.
		//!
		public: lower_error(double number): error(SIGNIFIX_ELOWER, number) {};
	};

	//!
	//! Wraps #SIGNIFIX_EINVAL and its #description.
	//!
	class inval_error: public error {
		//!
		//! Invokes signifix::error::error() with #SIGNIFIX_EINVAL.
		//!
		//! @param number  The number causing this error.
		//!
		public: inval_error(double number): error(SIGNIFIX_EINVAL, number) {};
	};

	//!
	//! Wraps #SIGNIFIX_ETRUNC and its #description.
	//!
	class trunc_error: public error {
		//!
		//! Invokes signifix::error::error() with #SIGNIFIX_ETRUNC.
		//!
		//! @param number  The number causing this error.
		//!
		public: trunc_error(double number): error(SIGNIFIX_ETRUNC, number) {};
	};

	//!
	//! Wraps #SIGNIFIX_EPRINT and its #description.
	//!
	class print_error: public error {
		//!
		//! Invokes signifix::error::error() with #SIGNIFIX_EPRINT.
		//!
		//! @param number  The number causing this error.
		//!
		public: print_error(double number): error(SIGNIFIX_EPRINT, number) {};
	};

	//!
	//! Wraps signifix_format().
	//!
	//! @param number  The number to be formatted.
	//! @param plus    The plus sign character. Predefined values are ::PROPER,
	//!                ::SIGNED, and ::SPACED.
	//!
	//! @return  The formatted number.
	//!
	//! @throws  signifix::upper_error
	//! @throws  signifix::lower_error
	//! @throws  signifix::inval_error
	//! @throws  signifix::trunc_error
	//! @throws  signifix::print_error
	//!
	std::string format(double number, char plus = PROPER) {
		char buffer[SIGNIFIX_BUFLEN];
		int strlen;
		if (0 > (strlen = signifix_format(buffer, number, plus)))
			switch (strlen) {
				case SIGNIFIX_EUPPER: throw upper_error(number);
				case SIGNIFIX_ELOWER: throw lower_error(number);
				case SIGNIFIX_EINVAL: throw inval_error(number);
				case SIGNIFIX_ETRUNC: throw trunc_error(number);
				case SIGNIFIX_EPRINT: throw print_error(number);
			}
		return std::string(buffer, strlen);
	}
}

#endif
