//Check Identity Matrix

#include<iostream>
#include<iomanip>

using namespace std;

void PrintMatrix(int Mat[3][3], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(3) << Mat[i][j] << "    ";
		}
		cout << endl;
	}
}

bool CheckIdentityMatrix(int Mat[3][3], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i == j && Mat[i][j] != 1)
			{
				return false;
			}
			else if (i != j && Mat[i][j] != 0)
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	int Mat[3][3] = { {1,0,0},{0,1,0},{0,0,1} };
	//int Mat[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	cout << "Matrix:\n";
	PrintMatrix(Mat, 3, 3);

	if (CheckIdentityMatrix(Mat, 3, 3))
		cout << "\nYes: Matrix is identity.\n";
	else
		cout << "\nNo: Matrix is not identity.\n";

	system("pause>0");
}