// stdafx.h: ���������� ���� ��� ����������� ��������� ���������� ������
// ��� ���������� ������ ��� ����������� �������, ������� ����� ������������, ��
// �� ����� ����������
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <utility>
//#include <vector>

struct EquationRoots3
{
	int numberRealRoots;
	double realRoots[3];
	std::pair<double, double> conjugateComplexRoots[2];
};


// TODO: ���������� ����� ������ �� �������������� ���������, ����������� ��� ���������
