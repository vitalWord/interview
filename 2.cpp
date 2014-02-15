#include <iostream>

const int c_kM = 5;
typedef int Matrix[c_kM][c_kM];

int min_from_top_sector(Matrix& m)
{
	const int c_kM = 4;
	typedef int Matrix[c_kM][c_kM];

	int min_from_top_sector(Matrix& m)
	{
		double min;
		min=m[0][0];
		int indeks=(c_kM%2==0)?c_kM/2:c_kM/2+1;
		for (int i=0;i<indeks;i++)
		{
			for (int j=i;j<c_kM-i;j++)
			{
				if(m[i][j+i]<min)
					min=m[i][j];
			}
		}
		return(min);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	Matrix matrix;
	for (int i=0;i<c_kM;i++)
	{
		for(int j=0;j<c_kM;j++)
			cin>>matrix[i][j];
	}
	std::cout << min_from_top_sector(matrix) << std::endl;

	return 0;
}
