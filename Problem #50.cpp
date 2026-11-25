//Delete Client By Account Number

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>

using namespace std;

const string ClientsFileName = "Clients.txt";

struct stClientData
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;
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

string ConvertRecordToLine(stClientData Client, string Seperator =
	"#//#")
{
	string stClientRecord = "";

	stClientRecord += Client.AccountNumber + Seperator;
	stClientRecord += Client.PinCode + Seperator;
	stClientRecord += Client.Name + Seperator;
	stClientRecord += Client.Phone + Seperator;
	stClientRecord += to_string(Client.AccountBalance);

	return stClientRecord;
}

vector <stClientData> LoadCleintsDataFromFile(string FileName)
{
	vector <stClientData> vClients;
	fstream MyFile;

	MyFile.open(FileName, ios::in);
	if (MyFile.is_open())
	{
		string Line;
		stClientData Client;

		while (getline(MyFile, Line))
		{
			Client = ConvertLineDataToRecord(Line);
			vClients.push_back(Client);
		}

		MyFile.close();
	}

	return vClients;
}

void PrintClientRecord(stClientData Client)
{
	cout << "\nThe following are the client details:\n";
	cout << "\nAccout Number: " << Client.AccountNumber;
	cout << "\nPin Code : " << Client.PinCode;
	cout << "\nName : " << Client.Name;
	cout << "\nPhone : " << Client.Phone;
	cout << "\nAccount Balance: " << Client.AccountBalance;
}

bool FindClientByAccountNumber(string AccountNumber, vector<stClientData> vClients,
	stClientData& Client)
{
	for (stClientData c : vClients)
	{
		if (c.AccountNumber == AccountNumber)
		{
			Client = c;
			return true;
		}
	}

	return false;
}

string ReadClientAccountNumber()
{
	string AccountNumber = "";
	cout << "\nPlease enter AccountNumber? ";
	cin >> AccountNumber;
	return AccountNumber;
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<stClientData>& vClients)
{
	for (stClientData& c : vClients)
	{
		if (c.AccountNumber == AccountNumber)
		{
			c.MarkForDelete = true;

			return true;
		}
	}

	return false;
}

vector <stClientData> SaveCleintsDataToFile(string FileName, vector<stClientData> vClients)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);//overwrite

	string DataLine;

	if (MyFile.is_open())
	{
		for (stClientData C : vClients)
		{
			if (C.MarkForDelete == false)
			{
				//we only write records that are not marked for delete.
				DataLine = ConvertRecordToLine(C);
				MyFile << DataLine << endl;
			}
		}

		MyFile.close();
	}

	return vClients;
}

bool DeleteClientByAccountNumber(string AccountNumber, vector<stClientData>& vClients)
{
	stClientData Client;
	char Answer = 'n';

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientRecord(Client);

		cout << "\n\nAre you sure you want delete this client? y/n ? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			MarkClientForDeleteByAccountNumber(AccountNumber, vClients);

			SaveCleintsDataToFile(ClientsFileName, vClients);

			//Refresh Clients
			vClients = LoadCleintsDataFromFile(ClientsFileName);
			cout << "\n\nClient Deleted Successfully.";

			return true;
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";

		return false;
	}
}

int main()
{
	vector <stClientData> vClients = LoadCleintsDataFromFile(ClientsFileName);

	string AccountNumber = ReadClientAccountNumber();

	DeleteClientByAccountNumber(AccountNumber, vClients);

	return 0;
}