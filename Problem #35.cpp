//Print Each Word In String

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

void PrintEachWord(string s)
{
	string delim = " "; // delimiter
	cout << "\nYour string words are: \n\n";
	short pos = 0;
	string sWord; // define a string variable
	// use find() function to get the position of the delimiters
	while ((pos = s.find(delim)) != std::string::npos)
	{
		sWord = s.substr(0, pos); // store the word
		if (sWord != "")
		{
			cout << sWord << endl;
		}
		s.erase(0, pos + delim.length()); /* erase() until
		positon and move to next word. */
	}
	if (s != "")
	{
		cout << s << endl; // it print last word of the string
	}
}

int main()
{
	PrintEachWord(ReadString());

	system("pause>0");
}