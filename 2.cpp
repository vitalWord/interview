// Квадратная матрица разделена диагоналями на четыре сектора. 
// Напишите функцию min_from_top_sector(), которая будет 
// находить значение ячейки, минимальное для всех ячеек верхнего 
// сектора, включая отрезки диагоналей, составляющие этот сектор.

#include <iostream>

const int c_kM = 5;
typedef int Matrix[c_kM][c_kM];

int min_from_top_sector(Matrix& m)
{
	int l = 0, r = c_kM - 1;
	int min = m[0][0];
	
	int j = 0;
	while (l <= r) {
		for (int i = l; i < r; i++)
			if (m[i][j] < min) min = m[i][j];
		l++; r--;
		j++;
	}

	return min;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Matrix matrix;
	
	// matrix initialization

	std::cout << min_from_top_sector(matrix) << std::endl;

	return 0;
}
