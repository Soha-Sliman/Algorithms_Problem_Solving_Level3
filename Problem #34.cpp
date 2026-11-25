//Print All Vowels In String

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

bool IsVowel(char c)
{
	c = tolower(c);
	return((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u'));
}

void PrintAllVowels(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (IsVowel(s[i]))
		{
			cout << s[i] << "   ";
		}
	}
	cout << "\n";
}

int main()
{
	string s = ReadString();

	cout << "\nVowels in string are: ";
	PrintAllVowels(s);

	system("pause>0");
}