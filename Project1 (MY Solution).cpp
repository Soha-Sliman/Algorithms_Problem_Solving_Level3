//Bank 1 (My Solution)

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

enum enMainMenuOptions{ShowClientList=1, AddNewClients=2, DeleteClient=3, UpdateClientInfo=4, FindClient=5, Exit=6};

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
			if (Line != "")
			{
				Client = ConvertLineDataToRecord(Line);
				vClients.push_back(Client);
			}
		}
		MyFile.close();
	}
	return vClients;
}

void PrintClientRecord(stClientData Client)
{
	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(12) << left << Client.AccountBalance;
}

void PrintAllClientsData(vector <stClientData> &vClients)
{
	system("cls");
	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ")Client(s).";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";

	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	for (stClientData Client : vClients)
	{
		PrintClientRecord(Client);
		cout << endl;
	}

	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
}

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

stClientData ReadClientRecord(string AccountNumber)
{
	stClientData ClientData;

	ClientData.AccountNumber = AccountNumber;

	cout << "Enter PinCode? ";
	getline(cin >> ws, ClientData.PinCode);

	cout << "Enter Name? ";
	getline(cin, ClientData.Name);

	cout << "Enter Phone? ";
	getline(cin, ClientData.Phone);

	cout << "Enter AccountBalance? ";
	cin >> ClientData.AccountBalance;

	return ClientData;
}

string ReadClientAccountNumber()
{
	string AccountNumber = "";
	cout << "\nEnter AccountNumber? ";
	getline(cin >> ws, AccountNumber);
	return AccountNumber;
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

bool FindClientByAccountNumber(string AccountNumber, vector <stClientData> vClients, stClientData& Client)
{

	vClients = LoadCleintsDataFromFile(ClientsFileName);
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
	vector <stClientData> vClients = LoadCleintsDataFromFile(ClientsFileName);

	string AccountNumber = ReadClientAccountNumber();

	

	while (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		cout << "\nClient with account number [" << AccountNumber << "] already exists,Enter another account number?";
		getline(cin >> ws, AccountNumber);
	}

	Client = ReadClientRecord(AccountNumber);

	AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
}

void AddClients()
{
	char AddMore = 'Y';

	do
	{
		system("cls");
		cout << "___________________________________\n";
		cout << "         Add New Client Screen      \n";
		cout << "___________________________________\n";
		cout << "Adding New Client:\n\n";

		AddNewClient();

		cout << "\nClient Added Successfully, do you want to add more clients ? Y / N ? ";
		cin >> AddMore;

	} while (toupper(AddMore) == 'Y');
}

void PrintClientCard(stClientData Client)
{
	cout << "\nThe following are the client details:\n";
	cout << "_______________________________________\n";

	cout << "\nAccout Number: " << Client.AccountNumber;
	cout << "\nPin Code : " << Client.PinCode;
	cout << "\nName : " << Client.Name;
	cout << "\nPhone : " << Client.Phone;
	cout << "\nAccount Balance: " << Client.AccountBalance;

	cout << "\n_______________________________________\n";
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
	system("cls");
	stClientData Client;
	char Answer = 'n';

	cout << "___________________________________\n";
	cout << "         Delete Client Screen      \n";
	cout << "___________________________________\n";

	AccountNumber =  ReadClientAccountNumber();

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
	
		PrintClientCard(Client);

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

bool UpdateClientByAccountNumber(string AccountNumber, vector<stClientData>& vClients)
{
	system("cls");
	stClientData Client;
	char Answer = 'n';

	cout << "___________________________________\n";
	cout << "      Update Client Info Screen    \n";
	cout << "___________________________________\n";

	AccountNumber = ReadClientAccountNumber();

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);

		cout << "\n\nAre you sure you want update this client? y/n ? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			for (stClientData& c : vClients)
			{
				if (c.AccountNumber == AccountNumber)
				{
					c = ReadClientRecord(AccountNumber);
					break;
				}

			}
			SaveCleintsDataToFile(ClientsFileName, vClients);

			cout << "\n\nClient Updated Successfully.";

			return true;
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";

		return false;
	}
}

void GoBackToMainMenue()
{
	cout << "\n\nPress any key to go back to main menue...";
	system("pause>0");
}

enMainMenuOptions ReadMainMenueOption()
{
	int choice = 0;
	cout << "\nChoose what do you want to do? [1 to 6]? ";
	cin >> choice;
	return (enMainMenuOptions)choice;
}

void DrawScreenHeader()
{
	system("cls");
	cout << "\n===========================================\n";
	cout << "\n                 Main Menue Screen          \n";
	cout << "\n===========================================\n";
	cout << "\n\t [1] Show Client List.\n";
	cout << "\n\t [2] Add New Client.\n";
	cout << "\n\t [3] Delete Client.\n";
	cout << "\n\t [4] Update Client Info.\n";
	cout << "\n\t [5] Find Client.\n";
	cout << "\n\t [6] Exit.\n";
	cout << "\n===========================================\n";
}

void ShowFindClientScreen(vector <stClientData>& vClients)
{
	system("cls");
	cout << "\n-----------------------------------\n";
	cout << "\tFind Client Screen\n";
	cout << "-----------------------------------\n";

	string AccountNumber = ReadClientAccountNumber();
	stClientData Client;

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is not found!\n";
	}
}

void PrintMainMenueScreen(vector<stClientData> &vClients)
{
	enMainMenuOptions MainMenue;

	stClientData Client;
	
	do
	{
		DrawScreenHeader();

		MainMenue = ReadMainMenueOption();

		switch (MainMenue)
		{
		case enMainMenuOptions::ShowClientList:
		{
			vClients = LoadCleintsDataFromFile(ClientsFileName);
			PrintAllClientsData(vClients);
			GoBackToMainMenue();
			break;
		}
		case enMainMenuOptions::AddNewClients:
		{
			AddClients();
			GoBackToMainMenue();
			break;
		}
		case enMainMenuOptions::DeleteClient:
		{
			DeleteClientByAccountNumber(Client.AccountNumber, vClients);
			GoBackToMainMenue();
			break;
		}
		case enMainMenuOptions::UpdateClientInfo:
		{
			UpdateClientByAccountNumber(Client.AccountNumber, vClients);
			GoBackToMainMenue();
			break;
		}
		case enMainMenuOptions::FindClient:
		{
			ShowFindClientScreen(vClients);
			GoBackToMainMenue();
			break;
		}
		case enMainMenuOptions::Exit:
		{
			system("cls");
			cout << "___________________________________\n";
			cout << "         Program Ends :)           \n";
			cout << "___________________________________\n";
			break;
		}

		}


	} while (MainMenue != enMainMenuOptions::Exit);
}

int main()
{

	vector <stClientData> vClients = LoadCleintsDataFromFile(ClientsFileName);

	PrintMainMenueScreen(vClients);

	system("pause>0");
}