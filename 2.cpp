#include <iostream>

const int c_kM = 5;
typedef int Matrix[c_kM][c_kM];

int min_from_top_sector(Matrix& m)
{
	int min = m[0][0];
	for(int i = 0; i < c_kM / 2 + c_kM % 2; i++)
	{
		for(int j = i; j < c_kM - i; j++)
		{
			if(m[i][j] < min) min = m[i][j];
		}
	}

	return min;
}

int main(int argc, char* argv[])
{
	Matrix matrix;// = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};

	std::cout << min_from_top_sector(matrix) << std::endl;

	return 0;
}