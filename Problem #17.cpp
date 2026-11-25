//Number Exists In Matrix

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

bool CheckNumberExistsInMatrix(int Mat[3][3], int Num, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (Mat[i][j] == Num)
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int Mat[3][3] = { {0,7,4},{1,2,0},{0,9,9} };

	cout << "\nMatrix:\n";
	PrintMatrix(Mat, 3, 3);

	int Num;
	cout << "\nPlease enter the number to look for in matrix? ";
	cin >> Num;

	if (CheckNumberExistsInMatrix(Mat, Num, 3, 3))
		cout << "\nYes, it's there.\n";
	else
		cout << "\nYes, it's not there.\n";

	system("pause>0");

}