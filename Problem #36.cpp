//Count Each Word In String

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

int CountEachWord(string s)
{
	string delim = " ";
	int pos = 0;
	string sWord;
	int count = 0;

	while ((pos = s.find(delim)) != std::string::npos)
	{
		sWord = s.substr(0, pos);
		if (sWord != "")
		{
			count++;
		}
		s.erase(0, pos + delim.length());
	}
	if (s != "")
	{
		count++;
	}
	return count;
}

int main()
{
	string s = ReadString();

	cout << "\nThe number of words in your string is: " << CountEachWord(s);
	system("pause>0");
}