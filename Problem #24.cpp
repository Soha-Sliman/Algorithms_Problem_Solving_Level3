//Upper First Letter pf Each Word

#include<iostream>
#include<string>

using namespace std;

string ReadString()
{
	string Message;
	cout << "Please enter your string?\n";
	getline(cin, Message);
	return Message;
}

void UpperFirstLetterOfEachWord(string s)
{

	bool FirstLetter = true;
	cout << "\nString after conversion: \n";

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != ' ' && FirstLetter)
		{
			s[i] = toupper(s[i]);
		}
		FirstLetter = (s[i] == ' ' ? true : false);
	}
	cout << s;
}

int main()
{
	UpperFirstLetterOfEachWord(ReadString());

	system("pause>0");
}