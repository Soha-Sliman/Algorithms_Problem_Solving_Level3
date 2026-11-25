//Count Letters

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

char ReadChar()
{
	char ch;
	cout << "\n\nPlease enter a character? \n";
	cin >> ch;
	return ch;
}

short CountLetters(string s, char c)
{
	int count = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == c)
			count++;
	}
	return count;
}

int main()
{
	string s = ReadString();
	char c = ReadChar();

	cout << "\nLetter '" << c << "' count = " << CountLetters(s, c);

	system("pause>0");
}