//Count Small/Capital Letters(method 2)

#include<iostream>
#include<string>

using namespace std;

enum enWhatToCount{SmallLetters = 0, CapitalLetters = 1, All = 2};

string ReadString()
{
	string st;
	cout << "Please enter your string? \n";
	getline(cin, st);
	return st;
}

short CountLetters(string s, enWhatToCount WhatToCount = enWhatToCount::All)
{
	if (WhatToCount == enWhatToCount::All)
	{
		return s.length();
	}
	short count = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (WhatToCount == enWhatToCount::CapitalLetters && isupper(s[i]))
			count++;
		else if (WhatToCount == enWhatToCount::SmallLetters && islower(s[i]))
			count++;
	}
	return count;
}

int main()
{
	string s = ReadString();

	cout << "\nString Length = " << CountLetters(s) << endl;
	cout << "\nCapital Letters Count = " << CountLetters(s, enWhatToCount::CapitalLetters) << endl;
	cout << "\nSmall Letters Count = " << CountLetters(s, enWhatToCount::SmallLetters) << endl;

	system("pause>0");
}