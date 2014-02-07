#include <iostream>

const int c_kM = 5;
typedef int Matrix[c_kM][c_kM];

int min_from_top_sector(Matrix& m)
{
	int max = 0;
	for(int i = 0; i < c_kM / 2 + c_kM % 2; i++)
	{
		for(int j = i; j < c_kM - i; j++)
		{
			if(m[i][j] > max) max = m[i][j];
		}
	}

	return max;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Matrix matrix;

	std::cout << min_from_top_sector(matrix) << std::endl;

	return 0;
}
