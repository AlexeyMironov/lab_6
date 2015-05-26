// stdafx.h: включаемый файл дл€ стандартных системных включаемых файлов
// или включаемых файлов дл€ конкретного проекта, которые часто используютс€, но
// не часто измен€ютс€
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


// TODO: ”становите здесь ссылки на дополнительные заголовки, требующиес€ дл€ программы
