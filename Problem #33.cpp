//Count Vowel

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

int CountVowel(string s)
{
	int count = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (IsVowel(s[i]))
		{
			count++;
		}
	}
	return count;
}

int main()
{
	string s = ReadString();

	cout << "\nNumber is vowels is : " << CountVowel(s) << endl;

	system("pause>0");
}