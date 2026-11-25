//Is Vowel?

#include<iostream>
#include<string>

using namespace std;

char ReadChar()
{
	char ch;
	cout << "Please enter a character? \n";
	cin >> ch;
	return ch;
}

bool IsVowel(char c)
{
	c = tolower(c);
	return((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u'));
}

int main()
{
	char c = ReadChar();

	if (IsVowel(c))
		cout << "\nYes Letter \'" << c << "\' is vowel.\n";
	else
		cout << "\nYes Letter \'" << c << "\' is'nt vowel.\n";

	system("pause>0");
}