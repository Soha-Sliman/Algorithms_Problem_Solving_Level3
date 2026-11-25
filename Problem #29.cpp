//Count Small/Capital Letters

#include<iostream>
#include<string>

using namespace std;

string ReadString()
{
	string st;
	cout << "Please enter your string? \n";
	getline(cin, st);
	return st;
}

int  CountSmallLetters(string st)
{
	int countsmall = 0;
	for (int i = 0; i < st.length(); i++)
	{
		if (islower(st[i]))
		{
			countsmall++;
		}
	}
	return countsmall;
}

int  CountCapitalLetters(string st)
{
	int countcapital = 0;
	for (int i = 0; i < st.length(); i++)
	{
		if (isupper(st[i]))
		{
			countcapital++;
		}
	}
	return countcapital;
}

int main()
{
	string st = ReadString();
	cout << "\nString Length = " << st.length() << endl;
	cout << "\nCapital Letters Count = " << CountCapitalLetters(st) << endl;
	cout << "\nSmall Letters Count = " << CountSmallLetters(st) << endl;

	system("pause>0");
}