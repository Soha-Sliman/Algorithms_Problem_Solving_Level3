//sum of Matrix

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

int SumOfMatrix(int Arr[3][3], int row, int col)
{
	int sum = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			sum += Arr[i][j];
		}
	}
	return sum;
}

int main()
{
	srand((unsigned)time(NULL));
	int Mat[3][3];
	FillMatrix(Mat, 3, 3);
	cout << "Matrix:" << endl;
	PrintMatrix(Mat, 3, 3);
	cout << "\nThe sum of the matrix is: " << SumOfMatrix(Mat, 3, 3) << endl;
	system("pause>0");
}