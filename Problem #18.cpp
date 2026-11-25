//Intersected Numbers In Matrices

#include<iostream>
#include<iomanip>

using namespace std;


void PrintMatrix(int Mat[3][3], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << setw(3) << Mat[i][j] << "     ";
		}
		cout << endl;
	}
}

void PrintIntersectedNumbers(int Mat1[3][3], int Mat2[3][3], int rows, int cols)
{
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			for (int l = 0; l < rows ; l++)
			{
				for (int k = 0; k < cols; k++)
				{
					if (Mat1[i][j] == Mat2[l][k])
					{
						cout << Mat1[i][j] << "    ";
					}
				}
			}
		}
	}
	cout << "\n";
}

int main()
{
	int Mat1[3][3] = { {77,5,12},{22,20,1},{1,0,9} };
	int Mat2[3][3] = { {5,80,90},{22,77,1},{10,8,33} };

	cout << "\nMatrix1:\n";
	PrintMatrix(Mat1, 3, 3); 

	cout << "\nMatrix2:\n";
	PrintMatrix(Mat2, 3, 3);

	cout << "\nIntersected numbers are:\n";
	PrintIntersectedNumbers(Mat1, Mat2, 3, 3);

	return 0;
}