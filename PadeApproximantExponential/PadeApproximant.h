#pragma once

#include "LUP.h"

namespace MyMath {
	class PadeApproximant {
	public:
		static void GetRationalFunctionOfExponential(int n, double*& numerators, double*& denominators);
		static void GetRationalFunctionOfExponential(int n, Fraction*& numerators, Fraction*& denominators);
	};
}
