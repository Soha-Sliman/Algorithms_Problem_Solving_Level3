//Print First Letter pf Each Word

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

void PrintFirstLetterOfEachWord(string s)
{
	
	bool FirstLetter = true;
	cout << "\nFirst letters of this string: \n";

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != ' ' && FirstLetter)
		{
			cout << s[i] << endl;
		}
		FirstLetter = (s[i] == ' ' ? true : false);
	}
}

int main()
{
	PrintFirstLetterOfEachWord(ReadString());

	system("pause>0");
}