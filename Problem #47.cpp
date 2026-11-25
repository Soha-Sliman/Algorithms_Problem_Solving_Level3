//Add Clients To File

#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

const string ClientsFileName = "Clients.txt";

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
	getline(cin >> ws, ClientData.AccountNumber);

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

void AddDataLineToFile(string FileName, string stDataLine)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open())
	{
		MyFile << stDataLine << endl;
		MyFile.close();
	}
}

void AddNewClient()
{
	stClientData Client;
	Client = ReadClientData();
	AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
}

void AddClients()
{
	char AddMore = 'Y';
	do
	{
		system("cls");
		cout << "Adding New Client:\n\n";

		AddNewClient();

		cout << "\nClient Added Successfully, do you want to add more clients ? Y / N ? ";
		cin >> AddMore;

	} while (toupper(AddMore) == 'Y');
}

int main()
{
	AddClients();

	return 0;
}