//Min/Max Number In Matrix

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

int FindMinNumber(int Mat[3][3], int rows, int cols)
{
	int MinNum = Mat[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (Mat[i][j] < MinNum)
			{
				MinNum = Mat[i][j];
			}
		}
	}
	return MinNum;
}

int FindMaxNumber(int Mat[3][3], int rows, int cols)
{
	int MaxNum = Mat[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (Mat[i][j] > MaxNum)
			{
				MaxNum = Mat[i][j];
			}
		}
	}
	return MaxNum;
}

int main()
{
	int Mat1[3][3] = { {77,5,12},{22,20,3},{14,3,9} };

	cout << "\nMatrix1:\n";
	PrintMatrix(Mat1, 3, 3);

	cout << "\nMinimum Number is: " << FindMinNumber(Mat1, 3, 3) << endl;

	cout << "\nMaximum Number is: " << FindMaxNumber(Mat1, 3, 3) << endl;

	system("pause>0");

}