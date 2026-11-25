//Replace Words(Custom)

#include<iostream>
#include<string>
#include<vector>

using namespace std;

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

string JoinString(vector<string> vstring, string Delim)
{
	string st = "";

	for (string& s : vstring)
	{
		st = st + s + Delim;
	}
	return st.substr(0, st.length() - Delim.length());
}

string LowerAllString(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = tolower(S1[i]);
	}
	return S1;
}

string ReplaceWordInStringUsingSplit(string s, string StringToReplace,
	string sReplaceTo, bool MatchCase = true)
{
	vector <string> vString = SplitString(s, " ");

	for (string& s : vString)
	{
		if (MatchCase)
		{
			if (s == StringToReplace)
			{
				s = sReplaceTo;
			}
		}
		else
		{
			if (LowerAllString(s) == LowerAllString(StringToReplace))
			{
				s = sReplaceTo;
			}
		}
	}
	return JoinString(vString, " ");
}

int main()
{
	string S1 = "Welcome to Jordan , Jordan is a nice country";
	string StringToReplace = "jordan";
	string ReplaceTo = "USA";
	cout << "\nOriginal String:\n" << S1;
	cout << "\n\nReplace with match case: ";
	cout << "\n" << ReplaceWordInStringUsingSplit(S1,
		StringToReplace, ReplaceTo);
	cout << "\n\nReplace with dont match case: ";
	cout << "\n" << ReplaceWordInStringUsingSplit(S1,
		StringToReplace, ReplaceTo, false);
	system("pause>0");
}
