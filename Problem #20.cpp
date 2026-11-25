//Palindrome Matrix

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

/*bool IsPalindromeMatrix(int Mat[3][3], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols/2; j++)
		{
			if (Mat[i][j] != Mat[i][ cols - 1 - j] )
			{
				return false;
			}
		}
	}
	return true;
}*/

bool IsPalindromeMatrix(int Mat[3][3], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		int p = cols;

		for (int j = 0; j < cols/2; j++)
		{
			if (Mat[i][j] != Mat[i][p - 1])
			{
				return false;
			}
		}
	}
	return true;
}


int main()
{
	int Mat[3][3] = { {1,2,1},{5,5,5},{7,3,7} };

	cout << "\nMatrix1:\n";
	PrintMatrix(Mat, 3, 3);

	if (IsPalindromeMatrix(Mat, 3, 3))
		cout << "\nYes, Matrix is palindrome.\n";
	else
		cout << "\nNo, Matrix is not palindrome.\n";

	system("pause>0");
}