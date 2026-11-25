//Join String(Overloading)

#include<iostream>
#include<string>
#include<vector>
using namespace std;

string JoinString(vector<string> vstring, string Delim)
{
	string st = "";

	for (string& s : vstring)
	{
		st = st + s + Delim;
	}
	//return st; //هون رح يعطيني الفاصل نهاية الجملة
	return st.substr(0, st.length() - Delim.length());
}

string JoinString(string Arr[], int Length, string Delim)
{
	string s = "";
	for (int i = 0; i < Length; i++)
	{
		s = s + Arr[i] + Delim;
	}
	return s.substr(0, s.length() - Delim.length());
}

int main()
{
	vector<string> vString = { "Mohammed","Hasan","Ali","Jad" };
	string Arr[] = { "Mohammed","Hasan","Ali","Jad" };

	cout << "Vector after join: \n" << JoinString(vString, " && ");
	cout << "\n\nArray after join: \n" << JoinString(Arr, 4, " && ");

	system("pause>0");
}