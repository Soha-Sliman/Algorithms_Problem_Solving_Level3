//Sum Each Row In Matrix

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

int SumEachRowInMatrix(int Arr[3][3], int row, int col)
{
	int sum = 0;
	for ( int j = 0; j < col; j++)
	{
		sum += Arr[row][j];
	}
	return sum;
}

void PrintSumEachRowInMatrix(int Arr[3][3], int row, int col)
{
	cout << "\nThe following are the sum of each row in the matrix :\n";

	for (int i = 0; i < row; i++)
	{
		cout << "Row " << i + 1 << " Sum = " << SumEachRowInMatrix(Arr, i, col) << endl;
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

int main()
{
	srand((unsigned)time(NULL));

	int Arr[3][3];

	FillMatrix(Arr, 3, 3);

	cout << "The following is a 3x3 random matrix: " << endl;
	PrintMatrix(Arr, 3, 3);

	PrintSumEachRowInMatrix(Arr, 3, 3);

	system("pause>0");

}
