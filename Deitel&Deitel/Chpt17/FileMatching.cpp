#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define SIZE 100

/*
	Spec: oldmast + trans => newmast
		goal is to generate newmast.dat

	Strategy: consider file i for the match, 
		search trans to find a related transaction
		compute new values for the master file
		rinse and repeat until eof on the trans file
		lodge the new value of file i in newmast.dat
*/

void initAccountFound(bool []);

int main()
{
	ifstream inOldMaster("oldmast.dat", ios::in);
	ifstream inTransaction("trans.dat", ios::in);
	ofstream outNewMaster("newmast.dat", ios::out);

	if (!(inOldMaster && inTransaction && outNewMaster))
	{
		cout << "Error! Could not open one of the files.";
		exit(1);
	}

	bool accountFound[SIZE];
	initAccountFound(accountFound);

	//	variables for oldmast
	int accountNumber;
	string name;
	double currentBalance;

	// variables for trans
	int accountNum;
	double dollarAmount;

	inOldMaster >> accountNumber >> name >> currentBalance;
	while (inOldMaster)
	{
		// scan trans for relevant transactions
		inTransaction.seekg(0);
		while (inTransaction && !inTransaction.eof())
		{
			// do work
			// i.e. compute new values for the file
		}

		// write the new values to the file

		// take in a new file from oldmast
		inOldMaster >> accountNumber >> name >> currentBalance;
	}

	
	inTransaction >> accountNum >> dollarAmount;

	outNewMaster << accountNum << ' ' << name << ' ' << currentBalance;
}

void initAccountFound(bool array[])
{
	for (int i = 0; i < SIZE; ++i)
		array[i] = false;
}