// Квадратная матрица разделена диагоналями на четыре сектора. 
// Напишите функцию min_from_top_sector(), которая будет 
// находить значение ячейки, минимальное для всех ячеек верхнего 
// сектора, включая отрезки диагоналей, составляющие этот сектор.

#include <iostream>

const int c_kM = 5;
typedef int Matrix[c_kM][c_kM];

int min_from_top_sector(Matrix& m)
{
	int min = m[0][0];
	int middle = c_kM / 2 + 1;
	for(int i = 0; i < middle; i++)
		for(int j = i; j < c_kM - i; j++)
		{
			if(min > m[i][j])
				min = m[i][j];
		}
	return min;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Matrix matrix;

	std::cout << min_from_top_sector(matrix) << std::endl;

	return 0;
}
