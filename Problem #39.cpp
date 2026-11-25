//Join String

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

int main()
{
	vector<string> vString = { "Mohammed","Hasan","Ali","Jad" };

	cout << "Vector after join: \n\n" << JoinString(vString, " && ");

	system("pause>0");
}