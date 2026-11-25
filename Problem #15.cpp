//Count Number In Matrix

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

int CountNumberInMatrix(int Mat[3][3], int Num, int rows, int cols)
{
	int count = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (Mat[i][j] == Num)
			{
				count++;
			}
		}
	}
	return count;
}

int main()
{
	int Mat[3][3] = { {9,0,8},{8,6,5},{5,5,9} };
	cout << "Matrix:\n";
	PrintMatrix(Mat, 3, 3);

	int Num;
	cout << "\nEnter the number to count int matrix? ";
	cin >> Num;

	cout << "\nNumber " << Num << " count in matrix is " << CountNumberInMatrix(Mat, Num, 3, 3) << endl;

	return 0;
}