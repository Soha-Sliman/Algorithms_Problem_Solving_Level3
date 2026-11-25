//3*3 Random Matrix

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

int main()
{
	srand((unsigned)time(NULL));

	int Arr[3][3];
	int row = 3, col = 3;

	FillMatrix(Arr, row, col);

	cout << "\n The following is a 3x3 random matrix: " << endl;
	PrintMatrix(Arr, row, col);

	return 0;
}
