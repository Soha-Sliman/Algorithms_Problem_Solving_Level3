//Check Typical Matrices

#include<iostream>
#include<iomanip>

using namespace std;

int RandomNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;

	return RandNum;
}

void FillMatrix(int Arr[3][3], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			Arr[i][j] = RandomNumber(1, 10);

		}
	}
}

void PrintMatrix(int Arr[3][3], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %0*d ", 2, Arr[i][j]);
			//cout << setw(3) << Arr[i][j] << "     ";
		}
		cout << endl;
	}
}

bool CheckTypicalEquality(int Mat1[3][3], int Mat2[3][3], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (Mat1[i][j] != Mat2[i][j])
			{
				return false;
			}
			
		}
	}
	return true;
}

int main()
{
	srand((unsigned)time(NULL));

	int Mat1[3][3], Mat2[3][3];

	FillMatrix(Mat1, 3, 3);
	cout << "Matrix1:" << endl;
	PrintMatrix(Mat1, 3, 3);

	FillMatrix(Mat2, 3, 3);
	cout << "\nMatrix2:" << endl;
	PrintMatrix(Mat2, 3, 3);

	if (CheckTypicalEquality(Mat1, Mat2, 3, 3))
		cout << "\nYes, matrices are typical. ";
	else
		cout << "\nNo, matrices are not typical. ";

	system("pause>0");
}
