// Квадратная матрица разделена диагоналями на четыре сектора. 
// Напишите функцию min_from_top_sector(), которая будет 
// находить значение ячейки, минимальное для всех ячеек верхнего 
// сектора, включая отрезки диагоналей, составляющие этот сектор.

#include <iostream>

const int c_kM = 5;
typedef int Matrix[c_kM][c_kM];

int min_from_top_sector(Matrix& m)
{
	int temp = m[0][0];
	for(int i=0; i<=c_kM/2; i++)
		for(int j=i;j<c_kM-i;j++)	
			if(temp > m[i][j]) temp=m[i][j];
	return temp;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Matrix matrix;
	for(int i=0; i<c_kM; i++)
		for(int j=0;j<c_kM;j++)
			{
				std::cout << std::endl << "m[" <<i+1 <<"]["<<j+1<<"]=";
				std::cin >> matrix[i][j];
			}	

	std::cout << min_from_top_sector(matrix) << std::endl;

	return 0;
}
