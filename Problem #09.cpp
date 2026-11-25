//Print Middle Row & Col of Matrix

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

void PrintMiddleRow(int Arr[3][3], int rows, int cols)
{
	int MiddleRow = rows / 2;

		for (int j = 0; j < cols; j++)
		{
			printf(" %0*d ", 2, Arr[MiddleRow][j]);
		}
}

void PrintMiddleCol(int Arr[3][3], int rows, int cols)
{
	int MiddleCol = cols / 2;

	for (int i = 0; i < rows; i++)
	{
		printf(" %0*d ", 2, Arr[i][MiddleCol]);
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Mat1[3][3];

	FillMatrix(Mat1, 3, 3);
	cout << "Matrix1:" << endl;
	PrintMatrix(Mat1, 3, 3);

	cout << "\nMiddle Row of Matrix1 is: \n";
	PrintMiddleRow(Mat1, 3, 3);

	cout << "\n\nMiddle Col of Matrix1 is: \n";
	PrintMiddleCol(Mat1, 3, 3);

	system("pause>0");
}