#include "PadeApproximant.h"

using namespace MyMath;

void PadeApproximant::GetRationalFunctionOfExponential(const int n, double*& numerators, double*& denominators) {
    const int m = n;

    numerators = new double[m + 1];
    denominators = new double[n + 1];

    double** matrix = new double* [m];
    double* x = new double[m];

    //Taylor series of exp(x)
    long long* coefficients = new long long[m + n + 1];
    coefficients[0] = 1;
    for (int i = 1; i < m + n + 1; i++)
        coefficients[i] = coefficients[i - 1] * i;

    //try to calculate the rational function of Pade approximant of exp(x)
    for (int i = 0; i < m; i++) {
        x[i] = -1.0 / coefficients[n + 1 + i];
        //matrix[i] = new double[n];
        matrix[i] = new double[n];
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 1.0 / coefficients[n + i - j];
        }
    }

    LUP::SolvingLinearEquations(n, matrix, x);

    //b0
    denominators[0] = 1;
    //b1, b2, ... bn
    for (int i = 1; i <= n; i++)
        denominators[i] = x[i - 1];

    //a0
    numerators[0] = 1.0 / coefficients[0];
    //a1, a2, ... an
    for (int i = 1; i <= m; i++) {
        numerators[i] = 1.0 / coefficients[i];
        for (int j = 1; j <= i; j++)
            numerators[i] += 1.0 / coefficients[i - j] * denominators[j];
    }

    delete[] coefficients;
    for (int i = 0; i < m; i++)
        delete[] matrix[i];
    delete[] matrix;
    delete[] x;
}

void PadeApproximant::GetRationalFunctionOfExponential(const int n, Fraction*& numerators, Fraction*& denominators) {
    const int m = n;

    numerators = new Fraction[m + 1];
    denominators = new Fraction[n + 1];

    Fraction** matrix = new Fraction * [m];
    Fraction* x = new Fraction[m];

    //Taylor series of exp(x)
    long long* coefficients = new long long[m + n + 1];
    coefficients[0] = 1;
    for (int i = 1; i < m + n + 1; i++)
        coefficients[i] = coefficients[i - 1] * i;

    //try to calculate the rational function of Pade approximant of exp(x)
    for (int i = 0; i < m; i++) {
        x[i] = Fraction(-1, coefficients[n + 1 + i]);
        //matrix[i] = new double[n];
        matrix[i] = new Fraction[n];
        for (int j = 0; j < n; j++) {
            matrix[i][j] = Fraction(1, coefficients[n + i - j]);
        }
    }

    LUP::SolvingLinearEquations(n, matrix, x);

    //b0
    denominators[0] = 1;
    //b1, b2, ... bn
    for (int i = 1; i <= n; i++)
        denominators[i] = x[i - 1];

    //a0
    numerators[0] = Fraction(1, coefficients[0]);
    //a1, a2, ... an
    for (int i = 1; i <= m; i++) {
        numerators[i] = Fraction(1, coefficients[i]);
        for (int j = 1; j <= i; j++)
            numerators[i] += Fraction(1, coefficients[i - j]) * denominators[j];
    }

    delete[] coefficients;
    for (int i = 0; i < m; i++)
        delete[] matrix[i];
    delete[] matrix;
    delete[] x;
}
