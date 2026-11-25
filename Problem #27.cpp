//Invert Character Case

#include<iostream>
#include<string>

using namespace std;

char ReadChar()
{
	char ch;
	cout << "Please enter a character: \n";
	cin >> ch;
	return ch;
}

char InvertCharacter(char ch)
{
	/*if (isupper(ch))
	{
		ch = tolower(ch);
		return ch;
	}
	else
	{
		ch = toupper(ch);
		return ch;
	}*/
	return isupper(ch) ? tolower(ch) : toupper(ch);
}

int main()
{
	char ch = ReadChar();
	cout << "\n\nChar after inverting case:\n";

	ch = InvertCharacter(ch);
	cout << ch << endl;

	system("pause>0");
}