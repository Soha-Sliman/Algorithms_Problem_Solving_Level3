//Split String

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

int main()
{
	vector <string> vstring;
	/*string s2 = "Mohammed,Ali,Ahmad,Hussein";

	vstring = SplitString(s2, ",");*/

	vstring = SplitString(ReadString(), " ");
	cout << "\nTokens = " << vstring.size() << endl;

	for (string& s : vstring)
	{
		cout << s << endl;
	}

	system("pause>0");
}



