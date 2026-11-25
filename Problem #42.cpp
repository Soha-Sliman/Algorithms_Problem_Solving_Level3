//Replace Words

#include<iostream>
#include<string>

using namespace std;

string ReplaceWordInStringUsingBuiltInFunction(string s, string StringToReplace, string sReplaceTo)
{
	short pos = s.find(StringToReplace);

	while (pos != std::string::npos)
	{
		s = s.replace(pos, StringToReplace.length(), sReplaceTo); 

		pos = s.find(StringToReplace);//Find Next
	}
	return s;
}

int main()
{
	string s = "Welcome to Jordan , Jordan is a nice country";
	string StringToReplace = "Jordan";
	string sReplaceTo = "London";

	cout << "\nOrigial String\n" << s;
	cout << "\n\nString After Replace:";
	cout << "\n" << ReplaceWordInStringUsingBuiltInFunction(s, StringToReplace, sReplaceTo);
	cout << "\n";
	system("pause>0");
}