#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
	// create an output file stream to file clients.txt
	ofstream outClientFile("clients.txt", ios::out);

	// exit programme if unable to create file
	//	operator! returns true if either the failbit or the badbit are set for the stream
	if (!outClientFile)
	{
		cerr << "File could not be opened" << endl;
		exit(1);
	}

	cout << "Enter the account, name and balance." << endl
		<< "Enter end-of-file to end input.\n? ";

	int account;
	string name;
	double balance;

	while (cin >> account >> name >> balance)
	{
		outClientFile << account << ' ' << name << ' ' << balance << endl;
		cout << "? ";
	}
}

// ofstream constructor: (filename, file-open mode)
//	modes: ios::out or ios::app (to append data)

// others:
//	ios::app,
//	ios::ate,	open a file for output and move to the end of the file. Data can be written anywhere
//	ios::in,	open a file for input
//	ios::out,
//	ios::trunc,	Discard the file's contents (default action for ios::out)
//	ios::binary,open a file for binary (nontext) input or output


// Alternative syntax, using method open
//	ofstream outClientFile;
//	outClientFile.open("clients.txt", ios::out);

// Explicit outClientFile.close() possible, but usually called by destructor