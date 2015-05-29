#include "stdafx.h"
#include "solve3.h"
#include <iostream>

using namespace std;

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
			cout << "x" << i + 2 << " = " << result.conjugateComplexRoots[i].first << " and " << result.conjugateComplexRoots[i].second << endl;
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
