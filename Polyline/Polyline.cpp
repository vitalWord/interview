// Polyline.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <utility>
#include <iostream>
#include "Polyline.h"



int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;
	
	Points points;
	Handler handle;
	handle.InputPoints(points);
	handle.ShowInput(points);
	handle.cycle(points);
	handle.ShowCrossPoints();
	
	system("pause");
	return 0;
}

