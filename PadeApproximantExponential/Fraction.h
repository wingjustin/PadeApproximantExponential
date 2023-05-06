#pragma once

namespace MyMath {
	class Fraction {
	public:
		long long numerator;
		long long denominator;

		Fraction();

		Fraction(long long numerator);
		Fraction(long long numerator, long long denominator);

		long long GetGcd(long long a, long long b);
		long long GetLcm(long long a, long long b);

		void Reduction();
		Fraction& Inverse();
		Fraction& Absolute();

		Fraction& operator=(Fraction otherFraction);
		Fraction& operator=(long long otherInteger);
		Fraction& operator++();
		Fraction& operator--();

		Fraction& operator+=(Fraction otherFraction);
		Fraction& operator-=(Fraction otherFraction);
		Fraction& operator*=(Fraction otherFraction);
		Fraction& operator/=(Fraction otherFraction);

		Fraction& operator+=(long long otherInteger);
		Fraction& operator-=(long long otherInteger);
		Fraction& operator*=(long long otherInteger);
		Fraction& operator/=(long long otherInteger);

		Fraction operator+(Fraction otherFraction);
		Fraction operator-(Fraction otherFraction);
		Fraction operator*(Fraction otherFraction);
		Fraction operator/(Fraction otherFraction);

		Fraction operator+(long long otherInteger);
		Fraction operator-(long long otherInteger);
		Fraction operator*(long long otherInteger);
		Fraction operator/(long long otherInteger);

		bool operator==(Fraction otherFraction);
		bool operator!=(Fraction otherFraction);
		bool operator>=(Fraction otherFraction);
		bool operator<=(Fraction otherFraction);
		bool operator>(Fraction otherFraction);
		bool operator<(Fraction otherFraction);

		bool operator==(long long otherInteger);
		bool operator!=(long long otherInteger);
		bool operator>=(long long otherInteger);
		bool operator<=(long long otherInteger);
		bool operator>(long long otherInteger);
		bool operator<(long long otherInteger);
	};
}
