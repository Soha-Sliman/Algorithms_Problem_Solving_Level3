//Count Letters(Match Case)

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

char InvertLetterCase(char char1)
{
	return isupper(char1) ? tolower(char1) : toupper(char1);
}

short CountLetters(string s, char c, bool MatchCase = true)
{
	int count = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (MatchCase)
		{
			if (s[i] == c)
				count++;
		}
		else
		{
			if (tolower(s[i]) == tolower(c))
				count++;
		}
	}
	return count;
}



int main()
{
	string s = ReadString();
	char c = ReadChar();

	cout << "\nLetter '" << c << "' count = " << CountLetters(s, c);
	cout << "\nLetter \'" << c << "\' ";
	cout << "Or \'" << InvertLetterCase(c) << "\' ";
	cout << " Count = " << CountLetters(s, c, false);

	system("pause>0");
}