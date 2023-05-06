#pragma once

#include "Fraction.h"

#define _ABSOLUTE_DOUBLE_HI  0x7FFFFFFF
#define _DOUBLE_HI(x) *(1 + (int*)&x)

namespace MyMath {
	class LUP {
	public:
		static void SolvingLinearEquations(int n, double** matrix, double* x);
		static void SolvingLinearEquations(int n, Fraction** matrix, Fraction* x);
	};
}
