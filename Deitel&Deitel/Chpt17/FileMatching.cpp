#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
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

void initTransactionFound(int []);
void recordTransactions(ifstream &, int []);
void addValue(int [], int);
void removeValue(int [], int);
double scanTransactionFile(ifstream &, int);

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

	cout << "Running file matching" << endl;

	int TransactionFound[SIZE];
	initTransactionFound(TransactionFound);
	recordTransactions(inTransaction, TransactionFound); 	// Initial scan for found files

	//	variables for oldmast
	int accountNumber;
	string name;
	double currentBalance;

	outNewMaster.precision(2);

	// File matching and updating
	while (inOldMaster && !inOldMaster.eof())
	{
		inOldMaster >> dec >> accountNumber >> name >> currentBalance;
		currentBalance += scanTransactionFile(inTransaction, accountNumber);
		
		// write the new values to the file
		outNewMaster << fixed << showpoint << accountNumber << ' ' << name << ' ' << currentBalance << '\n';

		// cancel the accountNumber's occurence in TransactionFound
		removeValue(TransactionFound, accountNumber);
	}

	// Notify the user of TransactionFound values, flagging transactions that had no accounts
	for (int i = 0; i < SIZE; ++i)
		if (TransactionFound[i] > 0) 
			cout << "No account number " << TransactionFound[i] 
				<< " present in records. Transaction discarded" << endl;

	cout << "File Matching Complete";
}

void initTransactionFound(int array[])
{
	for (int i = 0; i < SIZE; ++i)
		array[i] = -1;
}

void recordTransactions(ifstream &input, int array[])
{
	int accountNum;
	double dollarAmount;

	input.seekg(0);
	int j = 0;
	while (input && !input.eof())
	{
		input >> accountNum >> dollarAmount;
		addValue(array, accountNum);
	}
}

void addValue(int array[], int value)
{
	int i = 0;
	while (i < SIZE && array[i] != value && array[i] != -1) ++i;
	
	if (i < SIZE && array[i] == -1)
		array[i] = value;
}

void removeValue(int array[], int value)
{
	int i = 0;
	while (i < SIZE && array[i] != value) ++i;

	if (i < SIZE) array[i] = 0;
}

/* Function to scan the transaction file for a particular account and return changes*/
double scanTransactionFile(ifstream &input, int accNo)
{
	int accountNum;
	double dollarAmount;
	double result = 0.0;

	// scan trans for relevant transactions
	input.seekg(0);
	while (input && !input.eof())
	{
		// compute changes for the account
		input >> accountNum >> dollarAmount;
		if (accountNum == accNo)	// a transaction number = the account number
			result += dollarAmount;
	}
	return result;
}