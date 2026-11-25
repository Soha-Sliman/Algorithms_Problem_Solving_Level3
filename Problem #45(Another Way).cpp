//Convert Record To Line

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

stClientData ReadClientData()
{
	stClientData ClientData;

	cout << "Enter Account Number? ";
	getline(cin, ClientData.AccountNumber);
	cout << "Enter PinCode? ";
	getline(cin, ClientData.PinCode);
	cout << "Enter Name? ";
	getline(cin, ClientData.Name);
	cout << "Enter Phone? ";
	getline(cin, ClientData.Phone);
	cout << "Enter AccountBalance? ";
	cin >> ClientData.AccountBalance;

	return ClientData;
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

string ConvertRecordToLine(stClientData ClientData, string seperator = "#//#") 
{
	vector<string> vClientData;

	vClientData.push_back(ClientData.AccountNumber);
	vClientData.push_back(ClientData.PinCode);
	vClientData.push_back(ClientData.Name);
	vClientData.push_back(ClientData.Phone);
	vClientData.push_back(to_string(ClientData.AccountBalance));

	return JoinString(vClientData, seperator);
}

int main()
{
	cout << "\nPlease Enter Client Data: \n\n";

	stClientData ClientData;
	ClientData = ReadClientData();

	cout << "\n\nClient Record for Saving is: \n";
	cout << ConvertRecordToLine(ClientData);

	return 0;
}
