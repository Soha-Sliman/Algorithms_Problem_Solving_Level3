//Upper/Lower All Letters of a string
#include <string>
#include <iostream>

using namespace std;

string ReadString()
{
	string S1;
	cout << "Please Enter Your String?\n";
	getline(cin, S1);
	return S1;
}

string UpperAllStrings(string s1)
{
	for (int i = 0; i < s1.length(); i++)
	{
		s1[i] = toupper(s1[i]);
	}
	return s1;
}

string LowerAllStrings(string s2)
{
	for (int i = 0; i < s2.length(); i++)
	{
		s2[i] = tolower(s2[i]);
	}
	return s2;
}

int main()
{
	string s1 = ReadString();

	cout << "\nString after upper:\n" << UpperAllStrings(s1);
	cout << "\n\nString after lower:\n"; 
	s1 = LowerAllStrings(s1);
	cout << s1 << endl;

	system("pause>0");
}