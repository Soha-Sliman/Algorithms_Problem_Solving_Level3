//transpose Matrix

#include<iostream>
#include<iomanip>

using namespace std;

void FillMatrix(int Arr[3][3], int rows, int cols)
{
	int count = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			count++;
			Arr[i][j] = count;
		}
	}
}

void PrintMatrix(int Arr[3][3], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(3) << Arr[i][j] << "     ";
		}
		cout << "\n";
	}
}

void TransposeMatrix(int Arr[3][3], int arrtranspose[3][3], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arrtranspose[i][j] = Arr[j][i];

		}
		cout << "\n";

	}
}

int main()
{
	int Arr[3][3];
	int arrtranspose[3][3];

	FillMatrix(Arr, 3, 3);

	cout << "The following is a 3x3 ordered matrix: " << endl;
	PrintMatrix(Arr, 3, 3);

	TransposeMatrix(Arr, arrtranspose, 3, 3);

	cout << "The following is the transposed matrix: " << endl;
	PrintMatrix(arrtranspose, 3, 3);

	system("pause>0");
}