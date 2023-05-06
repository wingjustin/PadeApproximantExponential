// PadeApproximantExponential.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <string>
#include <sstream>
#include<conio.h>
#include <Math.h>
#include "PadeApproximant.h"

#define PRECISION 52

using namespace std;
using namespace MyMath;

int main()
{
    const int n = 10;
    const int m = n;

    cout << " Pade Approximant - ";
    cout << "[" << to_string(m) << "," << to_string(n) << "]";
    cout << " Exponential function e^x" << endl;
    cout << "===========================================================" << endl;

    char operKey = 'E';

    Fraction* numerators;
    Fraction* denominators;

    PadeApproximant::GetRationalFunctionOfExponential(n, numerators, denominators);

    //print numerators
    cout << " ";
    if (numerators[0].denominator == 1)
        cout << " " << to_string(numerators[0].numerator) << " ";
    else
        cout << to_string(numerators[0].numerator) << "/" << to_string(numerators[0].denominator);
    for (int i = 1; i < m + 1; i++) {
        long long numerator = numerators[i].numerator;
        cout << (numerator < 0 ? " - (" : " + (");
        numerator = numerator < 0 ? ~numerator + 1 : numerator;
        if (numerators[i].denominator == 1)
            cout << " " << to_string(numerator) << " ";
        else
            cout << to_string(numerator) << "/" << to_string(numerators[i].denominator);
        cout << ")x";
        if (i > 1)
            cout << "^" << to_string(i);
    }

    cout << endl;
    cout << "-----------------------------------------------------------------------------------------------";
    cout << endl;

    //print denominators
    cout << " ";
    if (denominators[0].denominator == 1)
        cout << " " << to_string(denominators[0].numerator) << " ";
    else
        cout << to_string(denominators[0].numerator) << "/" << to_string(denominators[0].denominator);
    for (int i = 1; i < n + 1; i++) {
        long long numerator = denominators[i].numerator;
        cout << (numerator < 0 ? " - (" : " + (");
        numerator = numerator < 0 ? ~numerator + 1 : numerator;
        if (denominators[i].denominator == 1)
            cout << " " << to_string(numerator) << " ";
        else
            cout << to_string(numerator) << "/" << to_string(denominators[i].denominator);
        cout << ")x";
        if (i > 1)
            cout << "^" << to_string(i);
    }

    cout << endl;
    cout << "====================================================================================================" << "\n";

    do {
        //double x = 0.00020011092601223321;
        double x = 0.0;

        cout << "Calculate e^x" << "\n";
        cout << "----------------------------------------------------------------------------------------------------" << "\n";

        cout << "Please input x (near 0 will gain better accuracy) :" << "\n" << " x = ";
        string inputWord = "";
        char temp;
        while (cin.get(temp) && temp != '\n') {
            if ((temp == ' ') && (static_cast<int>(inputWord.length()) != 0)) {
                x = stof(inputWord);
                inputWord = "";
            }
            else if (temp >= 0x30 && temp <= 0x39 || temp == 0x2E || temp == 0x2D) // (0-9 .-)
                inputWord += temp;
        }
        if (static_cast<int>(inputWord.length()) != 0) {
            x = stof(inputWord);
            inputWord = "";
        }

        cout << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
        //calculate e^x

        // a0 + x*(a1 + x*(a2 + x*(a3 + x*(... x*(a[m-1] + x*a[m])))...
        double aAns = (double)numerators[m].numerator / (double)numerators[m].denominator;
        for (int i = m - 1; i > -1; i--) {
            aAns *= x;
            aAns += (double)numerators[i].numerator / (double)numerators[i].denominator;
        }
        // 1 + x*(b1 + x*(b2 + x*(b3 + x*(... x*(b[n-1] + x*b[n])))...
        double bAns = (double)denominators[n].numerator / (double)denominators[n].denominator;
        for (int i = n - 1; i > -1; i--) {
            bAns *= x;
            bAns += (double)denominators[i].numerator / (double)denominators[i].denominator;
        }


        double estimAns = aAns / bAns;

        double standardAns = std::exp(x);

        double error = estimAns - standardAns;

        ostringstream out;
        out.precision(PRECISION);
        out << std::fixed << estimAns;

        cout << "Estimate e^x : " << (estimAns < 0 ? "" : " ") << move(out).str() << endl;

        out.str("");
        out.clear();
        out << std::fixed << standardAns;

        cout << "Standard e^x : " << (standardAns < 0 ? "" : " ") << move(out).str() << endl;

        cout << endl;

        out.str("");
        out.clear();
        out << std::fixed << error;

        cout << "Error :        " << (error < 0 ? "" : " ") << move(out).str() << endl;


        cout << endl << endl;

        //check continue
        cout << "Press Any Key to calculate e^x again; \"E\" for Exit : ";
        operKey = _getch();
        cout << "\n=========================================================================" << endl;
    } while (operKey != 'e' && operKey != 'E');

    delete[] numerators;
    delete[] denominators;

    cout << endl;

    system("pause");
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
