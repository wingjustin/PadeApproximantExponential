#include "LUP.h"

using namespace MyMath;

void LUP::SolvingLinearEquations(const int n, double** matrix, double* const x) {
	const int m = n;

    //LU factorization with Partial Pivoting

    double** U = matrix;
    double** L = matrix; // L combines with original matrix, save space

    double pivot, pivot2;
    double* interchangeRow = new double[n + 1]; //index n for element of matrix x
    for (int i = 0, j = 0, max_i = 0; i < m; i++, j++) {
        // pivoting
        //get maximum
        max_i = i;
        pivot = U[i][j];
        _DOUBLE_HI(pivot) &= _ABSOLUTE_DOUBLE_HI; // get absolute value
        for (int ii = i + 1; ii < m; ii++) {
            pivot2 = U[ii][j];
            _DOUBLE_HI(pivot2) &= _ABSOLUTE_DOUBLE_HI; // get absolute value
            if (pivot2 > pivot) {
                pivot = pivot2;
                max_i = ii;
            }
        }
        //interchange
        if (max_i != i) {
            for (int jj = 0; jj < n; jj++) {
                interchangeRow[jj] = U[i][jj];
            }
            interchangeRow[n] = x[i];
            for (int jj = 0; jj < n; jj++) {
                U[i][jj] = U[max_i][jj];
            }
            x[i] = x[max_i];
            for (int jj = 0; jj < n; jj++) {
                U[max_i][jj] = interchangeRow[jj];
            }
            x[max_i] = interchangeRow[n];
        }

        //Gaussian Elimination
        pivot = U[i][j];
        //L[i][j] = 1;
        for (int ii = i + 1; ii < m; ii++) {
            pivot2 = U[ii][j];
            L[ii][j] = pivot2 / pivot;// no need 0, store L element
            for (int jj = j + 1; jj < n; jj++) {
                U[ii][jj] -= (pivot2 * U[i][jj]) / pivot;
            }
        }
    }
    delete[] interchangeRow;

    //Ly = b;
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < i; j++) {
            x[i] -= L[i][j] * x[j];
        }
    }
    //Ux = y;
    for (int i = m - 1; i > -1; i--) {
        for (int j = n - 1; j > i; j--) {
            x[i] -= U[i][j] * x[j];
        }
        x[i] /= U[i][i];
    }
}

void LUP::SolvingLinearEquations(const int n, Fraction** matrix, Fraction* const x) {
    const int m = n;

    //LU factorization with Partial Pivoting

    Fraction** U = matrix;
    Fraction** L = matrix; // L combines with original matrix, save space

    Fraction pivot, pivot2;
    Fraction* interchangeRow = new Fraction[n + 1]; //index n for element of matrix x
    for (int i = 0, j = 0, max_i = 0; i < m; i++, j++) {
        // pivoting
        //get maximum
        max_i = i;
        pivot = U[i][j];
        pivot.Absolute(); // get absolute value
        for (int ii = i + 1; ii < m; ii++) {
            pivot2 = U[ii][j];
            pivot2.Absolute(); // get absolute value
            if (pivot2 > pivot) {
                pivot = pivot2;
                max_i = ii;
            }
        }
        //interchange
        if (max_i != i) {
            for (int jj = 0; jj < n; jj++) {
                interchangeRow[jj] = U[i][jj];
            }
            interchangeRow[n] = x[i];
            for (int jj = 0; jj < n; jj++) {
                U[i][jj] = U[max_i][jj];
            }
            x[i] = x[max_i];
            for (int jj = 0; jj < n; jj++) {
                U[max_i][jj] = interchangeRow[jj];
            }
            x[max_i] = interchangeRow[n];
        }

        //Gaussian Elimination
        pivot = U[i][j];
        //L[i][j] = 1;
        for (int ii = i + 1; ii < m; ii++) {
            pivot2 = U[ii][j];
            L[ii][j] = pivot2 / pivot;// no need 0, store L element
            for (int jj = j + 1; jj < n; jj++) {
                U[ii][jj] -= L[ii][j] * U[i][jj];
            }
        }
    }
    delete[] interchangeRow;

    ////Ly = b;
    //for (int i = 1; i < m; i++) {
    //    for (int j = 0; j < i; j++) {
    //        x[i] -= L[i][j] * x[j];
    //    }
    //}
    ////Ux = y;
    //for (int i = m - 1; i > -1; i--) {
    //    for (int j = n - 1; j > i; j--) {
    //        x[i] -= U[i][j] * x[j];
    //    }
    //    x[i] /= U[i][i];
    //}

    //Ly = b;
    for (int i = 0; i < m; i++) {
        x[i] /= U[i][i];
        for (int j = 0; j < i; j++) {
            x[i] -= (U[j][j] / U[i][i]) * (x[j] * L[i][j]);
            //x[i] -= L[i][j] * x[j];
        }
    }
    //Ux = y;
    for (int i = m - 1; i > -1; i--) {
        for (int j = n - 1; j > i; j--) {
            x[i] -= (U[i][j] / U[i][i]) * x[j];
            //x[i] -= U[i][j] * x[j];
        }
        //x[i] /= U[i][i];
    }
}
