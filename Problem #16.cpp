//Check Sparse Matrix

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

int CountNumberInMatrix(int Mat[3][3], int Num, int rows, int cols)
{
	int count = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (Mat[i][j] == Num)
			{
				count++;
			}
		}
	}
	return count;
}

bool CheckSparseMatrix(int Mat[3][3], int rows, int cols)
{

	int SizeMatrix = rows * cols;
	return(CountNumberInMatrix(Mat, 0, 3, 3) >= ceil(SizeMatrix / 2));
}

int main()
{
	int Mat[3][3] = { {0,0,1},{1,2,0},{0,9,9} };
	//int Mat[3][3] = { {0,7,4},{1,2,0},{0,9,9} };

	cout << "\nMatrix:\n";
	PrintMatrix(Mat, 3, 3);

	if (CheckSparseMatrix(Mat, 3, 3))
		cout << "\nYes, it is sparse.\n";
	else
		cout << "\nNo, it's not sparse.\n";

	system("pause>0");
}