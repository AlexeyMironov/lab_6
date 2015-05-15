// Solve3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <stdexcept>

using namespace std;

EquationRoots3 Solve3(double a, double b, double c, double d)
{
	
}

int _tmain(int argc, _TCHAR* argv[])
{
	double a = 0;
	double b = 0;
	double c = 0;
	double d = 0;
	cout << "Enter the coefficients of the equation (a b c d) ... " << endl;

	cin >> a >> b >> c >> d;
			
	cout << "a=" << a << "  b=" << b << "  c=" << c << "  d=" << d << endl;
	system("pause");


	return 0;
}

