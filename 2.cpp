// Квадратная матрица разделена диагоналями на четыре сектора. 
// Напишите функцию min_from_top_sector(), которая будет 
// находить значение ячейки, минимальное для всех ячеек верхнего 
// сектора, включая отрезки диагоналей, составляющие этот сектор.

#include <iostream>
#define min(x,y) (x>y?y:x)
const int c_kM = 5;
// row x col
typedef int Matrix[c_kM][c_kM];

int size(Matrix& m){
	return c_kM;
}

int min_from_top_sector(Matrix& m)
{
	int m_size = size(m);
	int res = m[0][0];
	for (int i = 0; i < (m_size / 2 + m_size % 2); i++) {
		for (int j = i; j < (m_size - i - 1); j++) {
			res = min(res,m[i][j]);
		}
	}
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Matrix matrix;

	std::cout << min_from_top_sector(matrix) << std::endl;

	return 0;
}
