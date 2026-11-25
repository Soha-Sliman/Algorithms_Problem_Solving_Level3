//Convert Record To Line

#include<iostream>
#include<string>

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

string ConvertRecordToLine(stClientData ClientData, string seperator = "#//#")
{
	string stClientRecord = "";
	stClientRecord += ClientData.AccountNumber + seperator;
	stClientRecord += ClientData.PinCode + seperator;
	stClientRecord += ClientData.Name + seperator;
	stClientRecord += ClientData.Phone + seperator;
	stClientRecord += to_string(ClientData.AccountBalance);
	return stClientRecord;
}

int main()
{
	cout << "\nPlease Enter Client Data: \n\n";

	stClientData ClientData;
	ClientData = ReadClientData();

	cout << "\n\nClient Record for Saving is: \n";
	cout << ConvertRecordToLine(ClientData);

	system("pause>0");
	return 0;
}

