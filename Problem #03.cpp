//Sum Each Row In Matrix In Array

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
			Arr[i][j] = RandomNumber(1, 100);

		}
	}
}

void PrintMatrix(int Arr[3][3], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << setw(3) << Arr[i][j] << "     ";
		}
		cout << endl;
	}
}

int SumEachRowInMatrix(int Arr[3][3], int row, int col)
{
	int sum = 0;
	for (int j = 0; j < col; j++)
	{
		sum += Arr[row][j];
	}
	return sum;
}

void SumMatrixRowsInArray(int Arr[3][3], int ArrSum[3], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		ArrSum[i] = SumEachRowInMatrix(Arr, i, col);

	}
}

void PrintSumMatrixRowsInArray(int arr[3], int row)
{
	cout << "\nThe following are the sum of each row in the matrix :\n";

	for (int i = 0; i < row; i++)
	{
		cout << "Row " << i + 1 << " Sum = " << arr[i] << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Arr[3][3];
	int arr[3];

	FillMatrix(Arr, 3, 3);

	cout << "The following is a 3x3 random matrix: " << endl;
	PrintMatrix(Arr, 3, 3);

	SumMatrixRowsInArray(Arr, arr, 3, 3);

	PrintSumMatrixRowsInArray(arr, 3);

	system("pause>0");

}
