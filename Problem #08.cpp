//Multiply Two Matrices

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


void MultiplytowMatrices(int Arr[3][3], int arr[3][3],int MatResult[3][3], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			MatResult[i][j] = Arr[i][j] * arr[i][j];
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Mat1[3][3], Mat2[3][3], MatResult[3][3];

	FillMatrix(Mat1, 3, 3);
	cout << "Matrix1:" << endl;
	PrintMatrix(Mat1, 3, 3);

	FillMatrix(Mat2, 3, 3);
	cout << "\nMatrix2:" << endl;
	PrintMatrix(Mat2, 3, 3);

	MultiplytowMatrices(Mat1, Mat2, MatResult, 3, 3);

	cout << "\nResults:" << endl;
	PrintMatrix(MatResult, 3, 3);

	return 0;
}