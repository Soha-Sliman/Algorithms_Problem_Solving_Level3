//Fibonacci Series

#include<iostream>

using namespace std;

void PrintFibonacciSeries(int Number)
{
	int preNum1 = 1, preNum2 = 0;
	int FebNum = 0;

	cout << "1   ";
	for (int i = 2; i <= Number ; i++)
	{
		 FebNum = preNum1 + preNum2;
		cout << FebNum << "   ";

		preNum2 = preNum1;
		preNum1 = FebNum;

	}
}

int main()
{
	PrintFibonacciSeries(10);

	system("pause>0");
}