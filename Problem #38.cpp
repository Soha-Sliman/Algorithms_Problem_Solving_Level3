//TrimLeft, TrimRight, Trim

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

string TrimLeft(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != ' ')
		{
			return s.substr(i, s.length() - i);
		}
	}
}

string TrimRight(string S)
{
	for (int i = S.length() - 1; i >= 0; i--)
	{
		if (S[i] != ' ')
		{
			return S.substr(0, i + 1);
		}
	}
}

string Trim(string st)
{
	return(TrimLeft(TrimRight(st)));

}

int main()
{
	/*string S1 = " Mohammed Abu-Hahdoud "; // نستخدمهاعندما لا ننشأ تابع لقراءة سلسلة
cout << "\nString = " << S1;*/

	string s = ReadString();
	cout << "\n\nTrim Left  = " << TrimLeft(s);
	cout << "\nTrim Right = " << TrimRight(s);
	cout << "\nTrim       = " << Trim(s);

	system("pause>0");
}