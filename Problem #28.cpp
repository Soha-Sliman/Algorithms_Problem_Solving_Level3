//Invert All Letters Case

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

string InvertString(string st)
{
	for (int i = 0; i < st.length(); i++)
	{
		if (isupper(st[i]))
		{
			st[i] = tolower(st[i]);
		}
		else
		{
			st[i] = toupper(st[i]);
		}
	}

	return st;
}

int main()
{
	string st = ReadString();
	cout << "\n\nString after inverting all letter case: \n";

	st = InvertString(st);
	cout << st << endl;

	system("pause>0");
}