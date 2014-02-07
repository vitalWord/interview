// Квадратная матрица разделена диагоналями на четыре сектора. 
// Напишите функцию min_from_top_sector(), которая будет находить 
//значение ячейки, минимальное для всех ячеек верхнего сектора, 
// включая отрезки диагоналей, составляющие этот сектор.

#include <iostream>

const int c_kM = 5;
typedef int Matrix[c_kM][c_kM];

int min_from_top_sector(Matrix& m)
{
	int min = m[0][0];
	for(size_t i = 0; i < (c_kM + 1) / 2; i++) {
		for(size_t j = i; j < c_kM - i; j++) {
			if (m[i][j] < min)
				min = m[i][j];
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	Matrix matrix;

	std::cout << min_from_top_sector(matrix) << std::endl;

	return 0;
}
