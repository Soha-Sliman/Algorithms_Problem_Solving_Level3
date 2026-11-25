//Convert Line Data To Record

#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct stClientData
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

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

stClientData ConvertLineDataToRecord(string Line, string Seperator = "#//#")
{
	stClientData ClientData;
	vector <string> vClientData;

	vClientData = SplitString(Line, Seperator);
	ClientData.AccountNumber = vClientData[0];
	ClientData.PinCode = vClientData[1];
	ClientData.Name = vClientData[2];
	ClientData.Phone = vClientData[3];
	ClientData.AccountBalance = stod(vClientData[4]);

	return ClientData;
}

void PrintClientRecord(stClientData ClientData)
{
	cout << "\n\nThe following is the extracted client record:\n";
	cout << "\nAccout Number: " << ClientData.AccountNumber;
	cout << "\nPin Code : " << ClientData.PinCode;
	cout << "\nName : " << ClientData.Name;
	cout << "\nPhone : " << ClientData.Phone;
	cout << "\nAccount Balance: " << ClientData.AccountBalance;
}

int main()
{
	string Line = "A456#//#1234#//#Soso Sl#//#098764#//#6000.000000";
	cout << "\nLine Record is:\n" << Line;

	stClientData Client = ConvertLineDataToRecord(Line);
	PrintClientRecord(Client);

	return 0;
}

