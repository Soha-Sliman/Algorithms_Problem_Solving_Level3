//Reverse Words

#include<iostream>
#include<string>
#include<vector>

using namespace std;

string ReadString()
{
	string st;
	cout << "Please enter your string? \n";
	getline(cin, st);
	return st;
}

vector <string> SplitString(string s, string delim)
{
	vector <string> vstring;
	short pos = 0;
	string sWord;

	while ((pos = s.find(delim)) != std::string::npos)
	{
		sWord = s.substr(0, pos);
		if (sWord != "")
		{
			vstring.push_back(sWord);
		}
		s.erase(0, pos + delim.length());
	}
	if (s != "")
	{
		vstring.push_back(s);
	}
	return vstring;
}

string ReverseWordsInString(string S1)
{
	vector<string> vString;
	string S2 = "";
	vString = SplitString(S1, " ");
	// declare iterator
	vector<string>::iterator iter = vString.end();
	while (iter != vString.begin())
	{
		--iter;
		S2 += *iter + " ";
	}
	S2 = S2.substr(0, S2.length() - 1); //remove last space.
	return S2;
}

int main()
{
	string S1 = ReadString();
	cout << "\n\nString after reversing words:";
	cout << "\n" << ReverseWordsInString(S1);
	system("pause>0");
}