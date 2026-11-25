//Remove Punctuations

#include<iostream>
#include<string>

using namespace std;

string RemovePunctuations(string s)
{
	string st = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (!ispunct(s[i]))
		{
			st += s[i];
		}
	}
	return st;
}

int main()
{
	string S1 = "Welcome to Jordan, Jordan is a nice country; it's amazing.";

	cout << "Original String:\n" << S1;
	cout << "\n\nPauncuations Removed:\n" << RemovePunctuations(S1);

	system("pause>0");
}