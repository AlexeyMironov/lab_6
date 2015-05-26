// Solve3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include "math.h"
#include <stdexcept>

using namespace std;

double GetDiscriminant(double q, double p)
{
	return (((q * q) / 4) + ((p * p * p) / 27));
}

double RoundNumber(double number)
{
	return round(number * 10) / 10;
}

EquationRoots3 GetResultIfDiscriminantLessZero(double a, double b, double p, double q, double D)
{
	EquationRoots3 result;
	double angle;

	if (q == 0)
	{
		angle = M_PI / 2;
	}
	if (q < 0)
	{
		angle = atan(-2 * sqrt(-D) / q);
	}
	if (q > 0)
	{
		angle = atan(-2 * sqrt(-D) / q) + M_PI;
	}

	result.numberRealRoots = 3;

	result.realRoots[0] = 2 * sqrt(-p / 3) * cos(angle / 3) - (b / (3 * a));
	result.realRoots[1] = 2 * sqrt(-p / 3) * cos((angle + 2 * M_PI) / 3) - (b / (3 * a));
	result.realRoots[2] = 2 * sqrt(-p / 3) * cos((angle + 4 * M_PI) / 3) - (b / (3 * a));
	
	/*result.roots.push_back(2 * sqrt(-p / 3) * cos(angle / 3) - (b / (3 * a)));
	result.roots.push_back(2 * sqrt(-p / 3) * cos((angle + 2 * M_PI) / 3) - (b / (3 * a)));
	result.roots.push_back(2 * sqrt(-p / 3) * cos((angle + 4 * M_PI) / 3) - (b / (3 * a)));*/
	return result;
}

EquationRoots3 GetResultIfDiscriminantMoreZero(double a, double b, double q, double D)
{
	EquationRoots3 result;
	result.numberRealRoots = 1;

	double temp1 = cbrt((-q / 2) + sqrt(D)) + cbrt((-q / 2) - sqrt(D));
	double temp2 = cbrt((-q / 2) + sqrt(D)) - cbrt((-q / 2) - sqrt(D));

	result.realRoots[0] = temp1 - (b / (3 * a));
	result.conjugateComplexRoots[0].first = (-temp1 / 2) - (b / (3 * a));
	result.conjugateComplexRoots[0].second = sqrt(3) * temp2 / 2;
	result.conjugateComplexRoots[1].first = result.conjugateComplexRoots[0].first;
	result.conjugateComplexRoots[1].second = -result.conjugateComplexRoots[0].second;
	return result;
}

EquationRoots3 GetResultIfDiscriminantEqualZero(double a, double b, double q, double D)
{
	EquationRoots3 result;
	result.numberRealRoots = 2;
	result.realRoots[0] = 2 * cbrt(-q / 2) - b / (3 * a);
	result.realRoots[1] = -cbrt(-q / 2) - b / (3 * a);
	return result;
}

EquationRoots3 Solve3(double a, double b, double c, double d)
{
	if (a == 0)
	{
		throw std::invalid_argument("the argument must not be = 0");
	}

	EquationRoots3 result;
	double p = ((3 * a * c) - (b * b)) / (3 * a * a);
	double q = ((2 * b * b * b) - (9 * a * b * c) + (27 * a * a * d)) / (27 * a * a * a);
	double D = RoundNumber(GetDiscriminant(q, p));

	if (D < 0)
	{
		result = GetResultIfDiscriminantLessZero(a, b, p, q, D);
	}

	if (D > 0)
	{
		result = GetResultIfDiscriminantMoreZero(a, b, q, D);
	}
	if (D == 0)
	{
		result = GetResultIfDiscriminantEqualZero(a, b, q, D);
	}
	return result;
	
}

void PrintResult(EquationRoots3 const &result)
{
	cout << "real roots: " << endl;
	for (int i = 0; i < result.numberRealRoots; i++)
	{
		cout << "x" << i + 1 << " = " << result.realRoots[i] << endl;
	}
	if (result.numberRealRoots == 1)
	{
		cout << "conjugate complex roots: " << endl;
		for (int i = 0; i < 2; i++)
		{
			cout << "x" << i + 2 << " = " << result.conjugateComplexRoots[i].first << "and " << result.conjugateComplexRoots[i].second << endl;
		}
	}
	system("pause");
	
}
int main()
{
	double a = 0, b = 0, c = 0, d = 0; // D = 0
	EquationRoots3 result;
	result.numberRealRoots = 0;
	for (int i = 0; i < 2; i++)
	{
		result.conjugateComplexRoots[i].first = result.conjugateComplexRoots[i].second = 0;
	}

	for (int i = 0; i < 3; i++)
	{
		result.realRoots[i] = 0;
	}

	try
	{
		cin >> a >> b >> c >> d;
		result = Solve3(a, b, c, d);
		PrintResult(result);
	}
	catch (std::invalid_argument const & e)
	{
		cout << "Error: " << e.what() << "\n";
	}
	return 0;
}
