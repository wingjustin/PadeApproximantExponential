#include "Fraction.h"

using namespace MyMath;

Fraction::Fraction() {
	Fraction::numerator = 0;
	Fraction::denominator = 1;
}

Fraction::Fraction(const long long numerator) {
	Fraction::numerator = numerator;
	Fraction::denominator = 1;
}

Fraction::Fraction(const long long numerator, const long long denominator) {
	Fraction::numerator = numerator;
	Fraction::denominator = denominator;
}

long long Fraction::GetGcd(long long a, long long b) {
	//get the greatest common divisor
	//using Euclidean algorithm
	long long r = a % b;
	while (r) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

long long Fraction::GetLcm(long long a, long long b) {
	//get the least common multiple
	if (a > b)
		return (a / GetGcd(a, b)) * b;
	else
		return (b / GetGcd(a, b)) * a;
}

void Fraction::Reduction() {
	if (denominator == 0)
		return;
	long long gcd = GetGcd(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;

	if (denominator < 0) {
		numerator = ~numerator + 1;
		denominator = ~denominator + 1;
	}
}

Fraction& Fraction::Inverse() {
	long long temp = numerator;
	numerator = denominator;
	denominator = temp;
	
	if (denominator < 0) {
		numerator = ~numerator + 1;
		denominator = ~denominator + 1;
	}

	return *this;
}

Fraction& Fraction::Absolute() {
	if (numerator < 0)
		numerator = ~numerator + 1;
	if (denominator < 0)
		denominator = ~denominator + 1;

	return *this;
}

Fraction& Fraction::operator=(const Fraction otherFraction) {
	numerator = otherFraction.numerator;
	denominator = otherFraction.denominator;
	return *this;
}

Fraction& Fraction::operator=(const long long otherInteger) {
	numerator = otherInteger;
	denominator = 1;
	return *this;
}

Fraction& Fraction::operator++() {
	numerator += denominator;
	Reduction();
	return *this;
}

Fraction& Fraction::operator--() {
	numerator -= denominator;
	Reduction();
	return *this;
}

Fraction& Fraction::operator+=(const Fraction otherFraction) {
	//if (denominator == otherFraction.denominator)
	//	numerator += otherFraction.numerator;
	//else {
	//	long long lcm = GetLcm(denominator, otherFraction.denominator);

	//	numerator *= lcm / denominator;
	//	numerator += (lcm / otherFraction.denominator) * otherFraction.numerator;
	//	denominator = lcm;
	//}
	//Reduction();
	//return *this;

	long long n1 = numerator;
	long long d1 = denominator;
	long long n2 = otherFraction.numerator;
	long long d2 = otherFraction.denominator;

	long long gcd = GetGcd(d1, d2);

	n1 *= d2 / gcd;
	n2 *= d1 / gcd;

	numerator = n1 + n2;

	if (d1 > d2) {
		d1 /= gcd;

		gcd = GetGcd(numerator, d2);

		numerator /= gcd;
		d2 /= gcd;

		denominator = d1 * d2;
	}
	else {
		d2 /= gcd;

		gcd = GetGcd(numerator, d1);

		numerator /= gcd;
		d1 /= gcd;

		denominator = d1 * d2;
	}
	Reduction();
	return *this;
}

Fraction& Fraction::operator-=(const Fraction otherFraction) {
	//if (denominator == otherFraction.denominator)
	//	numerator -= otherFraction.numerator;
	//else {
	//	long long lcm = GetLcm(denominator, otherFraction.denominator);

	//	numerator *= lcm / denominator;
	//	numerator -= (lcm / otherFraction.denominator) * otherFraction.numerator;
	//	denominator = lcm;
	//}
	//Reduction();
	//return *this;

	long long n1 = numerator;
	long long d1 = denominator;
	long long n2 = otherFraction.numerator;
	long long d2 = otherFraction.denominator;

	long long gcd = GetGcd(d1, d2);

	n1 *= d2 / gcd;
	n2 *= d1 / gcd;

	numerator = n1 - n2;

	if (d1 > d2) {
		d1 /= gcd;

		gcd = GetGcd(numerator, d2);

		numerator /= gcd;
		d2 /= gcd;

		denominator = d1 * d2;
	}
	else {
		d2 /= gcd;

		gcd = GetGcd(numerator, d1);

		numerator /= gcd;
		d1 /= gcd;

		denominator = d1 * d2;
	}
	Reduction();
	return *this;
}

Fraction& Fraction::operator*=(const Fraction otherFraction) {
	//numerator *= otherFraction.numerator;
	//denominator *= otherFraction.denominator;

	long long n1 = numerator;
	long long d1 = otherFraction.denominator;

	long long gcd1 = GetGcd(n1, d1);

	n1 /= gcd1;
	d1 /= gcd1;

	long long n2 = otherFraction.numerator;
	long long d2 = denominator;

	long long gcd2 = GetGcd(n2, d2);

	n2 /= gcd2;
	d2 /= gcd2;

	numerator = n1 * n2;
	denominator = d1 * d2;

	Reduction();
	return *this;
}

Fraction& Fraction::operator/=(const Fraction otherFraction) {
	//numerator *= otherFraction.denominator;
	//denominator *= otherFraction.numerator;

	long long n1 = numerator;
	long long d1 = otherFraction.numerator;

	long long gcd1 = GetGcd(n1, d1);

	n1 /= gcd1;
	d1 /= gcd1;

	long long n2 = otherFraction.denominator;
	long long d2 = denominator;

	long long gcd2 = GetGcd(n2, d2);

	n2 /= gcd2;
	d2 /= gcd2;

	numerator = n1 * n2;
	denominator = d1 * d2;

	Reduction();
	return *this;
}

Fraction& Fraction::operator+=(long long otherInteger) {
	numerator += denominator * otherInteger;
	Reduction();
	return *this;
}

Fraction& Fraction::operator-=(long long otherInteger) {
	numerator -= denominator * otherInteger;
	Reduction();
	return *this;
}

Fraction& Fraction::operator*=(long long otherInteger) {
	numerator *= otherInteger;
	Reduction();
	return *this;
}

Fraction& Fraction::operator/=(long long otherInteger) {
	denominator *= otherInteger;
	Reduction();
	return *this;
}

Fraction Fraction::operator+(const Fraction otherFraction) {
	Fraction f = *this;
	return f += otherFraction;
}

Fraction Fraction::operator-(const Fraction otherFraction) {
	Fraction f = *this;
	return f -= otherFraction;
}

Fraction Fraction::operator*(const Fraction otherFraction) {
	Fraction f = *this;
	return f *= otherFraction;
}

Fraction Fraction::operator/(const Fraction otherFraction) {
	Fraction f = *this;
	return f /= otherFraction;
}

Fraction Fraction::operator+(const long long otherInteger) {
	Fraction f = *this;
	return f += otherInteger;
}

Fraction Fraction::operator-(const long long otherInteger) {
	Fraction f = *this;
	return f -= otherInteger;
}

Fraction Fraction::operator*(const long long otherInteger) {
	Fraction f = *this;
	return f *= otherInteger;
}

Fraction Fraction::operator/(const long long otherInteger) {
	Fraction f = *this;
	return f /= otherInteger;
}

bool Fraction::operator==(const Fraction otherFraction) {
	if (denominator == otherFraction.denominator)
		return numerator == otherFraction.numerator;
	else {
		//long long lcm = GetLcm(denominator, otherFraction.denominator);

		////long long a = (lcm / denominator) * numerator;
		////long long b = (lcm / otherFraction.denominator) * otherFraction.numerator;

		//return (lcm / denominator) * numerator
		//	== (lcm / otherFraction.denominator) * otherFraction.numerator;

		long long gcd = GetGcd(denominator, otherFraction.denominator);

		return (otherFraction.denominator / gcd) * numerator
			== (denominator / gcd) * otherFraction.numerator;
	}
}

bool Fraction::operator!=(const Fraction otherFraction) {
	if (denominator == otherFraction.denominator)
		return numerator != otherFraction.numerator;
	else {
		//long long lcm = GetLcm(denominator, otherFraction.denominator);

		////long long a = (lcm / denominator) * numerator;
		////long long b = (lcm / otherFraction.denominator) * otherFraction.numerator;

		//return (lcm / denominator) * numerator
		//	!= (lcm / otherFraction.denominator) * otherFraction.numerator;

		long long gcd = GetGcd(denominator, otherFraction.denominator);

		return (otherFraction.denominator / gcd) * numerator
			!= (denominator / gcd) * otherFraction.numerator;
	}
}

bool Fraction::operator>=(const Fraction otherFraction) {
	if (denominator == otherFraction.denominator)
		return numerator >= otherFraction.numerator;
	else {
		//long long lcm = GetLcm(denominator, otherFraction.denominator);

		////long long a = (lcm / denominator) * numerator;
		////long long b = (lcm / otherFraction.denominator) * otherFraction.numerator;

		//return (lcm / denominator) * numerator
		//	>= (lcm / otherFraction.denominator) * otherFraction.numerator;

		long long gcd = GetGcd(denominator, otherFraction.denominator);

		return (otherFraction.denominator / gcd) * numerator
			>= (denominator / gcd) * otherFraction.numerator;
	}
}

bool Fraction::operator<=(const Fraction otherFraction) {
	if (denominator == otherFraction.denominator)
		return numerator <= otherFraction.numerator;
	else {
		//long long lcm = GetLcm(denominator, otherFraction.denominator);

		////long long a = (lcm / denominator) * numerator;
		////long long b = (lcm / otherFraction.denominator) * otherFraction.numerator;

		//return (lcm / denominator) * numerator
		//	<= (lcm / otherFraction.denominator) * otherFraction.numerator;

		long long gcd = GetGcd(denominator, otherFraction.denominator);

		return (otherFraction.denominator / gcd) * numerator
			<= (denominator / gcd) * otherFraction.numerator;
	}
}

bool Fraction::operator>(const Fraction otherFraction) {
	if (denominator == otherFraction.denominator)
		return numerator > otherFraction.numerator;
	else {
		//long long lcm = GetLcm(denominator, otherFraction.denominator);

		////long long a = (lcm / denominator) * numerator;
		////long long b = (lcm / otherFraction.denominator) * otherFraction.numerator;

		//return (lcm / denominator) * numerator
		//	> (lcm / otherFraction.denominator) * otherFraction.numerator;

		long long gcd = GetGcd(denominator, otherFraction.denominator);

		return (otherFraction.denominator / gcd) * numerator
			> (denominator / gcd) * otherFraction.numerator;
	}
}

bool Fraction::operator<(const Fraction otherFraction) {
	if (denominator == otherFraction.denominator)
		return numerator < otherFraction.numerator;
	else {
		//long long lcm = GetLcm(denominator, otherFraction.denominator);

		////long long a = (lcm / denominator) * numerator;
		////long long b = (lcm / otherFraction.denominator) * otherFraction.numerator;

		//return (lcm / denominator) * numerator
		//	< (lcm / otherFraction.denominator) * otherFraction.numerator;

		long long gcd = GetGcd(denominator, otherFraction.denominator);

		return (otherFraction.denominator / gcd) * numerator
			< (denominator / gcd) * otherFraction.numerator;
	}
}

bool Fraction::operator==(const long long otherInteger) {
	return numerator == otherInteger * denominator;
}

bool Fraction::operator!=(const long long otherInteger) {
	return numerator != otherInteger * denominator;
}

bool Fraction::operator>=(const long long otherInteger) {
	return numerator >= otherInteger * denominator;
}

bool Fraction::operator<=(const long long otherInteger) {
	return numerator <= otherInteger * denominator;
}

bool Fraction::operator>(const long long otherInteger) {
	return numerator > otherInteger * denominator;
}

bool Fraction::operator<(const long long otherInteger) {
	return numerator < otherInteger * denominator;
}
