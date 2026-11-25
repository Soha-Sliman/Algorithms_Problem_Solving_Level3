//Remove Punctuations(Other Ways)

#include<iostream>
#include<string>

using namespace std;

/*string RemovePunctuations(string s) //First Method
{
	string st = "";
	string puncts = ".,;!?@#$%^&*()_+-=[]{}|'\"<>~/\\";

	for (char c : s)
	{
		if (puncts.find(c) == std::string::npos)
		{
			st += c; 
		}
	}
	return st;
}*/


string RemovePunctuations(string s) // Second Way
{
    string st = "";

    for (char c : s)
	{

        if ((c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9') ||
            c == ' ')
        {
            st += c;
        }
    }
    return st;
}

int main()
{
	string S1 = "Welcome to Jordan, Jordan is a nice country; it's amazing.";

	cout << "Original String:\n" << S1;
	cout << "\n\nPunctuations Removed:\n" << RemovePunctuations(S1) << "\n";

	system("pause>0");
	return 0;
}
