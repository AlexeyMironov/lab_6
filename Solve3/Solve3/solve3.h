#pragma once

#include <utility>

struct EquationRoots3
{
	int numberRealRoots;
	double realRoots[3];
	std::pair<double, double> conjugateComplexRoots[2];
};

EquationRoots3 Solve3(double a, double b, double c, double d);