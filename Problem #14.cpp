// Check Scalar Matrix

#include<iostream>
#include<iomanip>

using namespace std;

void PrintMatrix(int Mat[3][3], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(3) << Mat[i][j] << "    ";
		}
		cout << endl;
	}
}

bool CheckScalarMatrix(int Mat[3][3], int rows, int cols)
{
	int FirstDiagonalElement = Mat[0][0];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i == j && Mat[i][j] != FirstDiagonalElement)
			{
				return false;
			}
			else if (i != j && Mat[i][j] != 0)
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	//int Mat[3][3] = { {9,0,0},{0,9,0},{0,0,8} };
	int Mat[3][3] = { {9,0,0},{0,9,0},{0,0,9} };
	cout << "Matrix:\n";
	PrintMatrix(Mat, 3, 3);

	if (CheckScalarMatrix(Mat, 3, 3))
		cout << "\nYes: Matrix is scalar.\n";
	else
		cout << "\nNo: Matrix is not scalar.\n";

	system("pause>0");
}