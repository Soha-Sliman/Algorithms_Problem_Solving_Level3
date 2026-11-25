//Sum Each Col In Matrix

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

int SumEachColInMatrix(int Arr[3][3], int row, int col)
{
	int sum = 0;
	for (int i = 0; i < row; i++)
	{
		sum += Arr[i][col];
	}

	return sum;
}

void PrintSumEachColInMatrix(int Arr[3][3], int row, int col)
{
	cout << "\nThe following are the sum of each col in the matrix :\n";

	for (int j = 0; j < col; j++)
	{
		cout << "Col " << j + 1  << " Sum = " << SumEachColInMatrix(Arr, row, j) << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Arr[3][3];

	FillMatrix(Arr, 3, 3);

	cout << "The following is a 3x3 random matrix: " << endl;
	PrintMatrix(Arr, 3, 3);

	PrintSumEachColInMatrix(Arr, 3, 3);

	system("pause>0");

}
