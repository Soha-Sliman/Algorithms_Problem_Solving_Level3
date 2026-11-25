//Fibonacci Series With Recursion

#include<iostream>

using namespace std;

void PrintFibonacciSeriesUsingRecursion(int Number, int PrevNum1, int PrevNum2)
{

	if (Number <= 0)
	{
		return;
	}
	cout << PrevNum2 << "  ";

	PrintFibonacciSeriesUsingRecursion(Number - 1, PrevNum2, PrevNum1 + PrevNum2);
}

int main()
{
	PrintFibonacciSeriesUsingRecursion(10, 0, 1);
		system("pause>0");
}
	