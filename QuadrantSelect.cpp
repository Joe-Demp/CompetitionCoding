#define DEBUG 0
/*
	A programme to take in a set of coordinates from a file and print their quadrant to file

	From Katiss, by Joseph Dempsey
	October 2018
*/

#include <iostream>
#include <fstream>
/*
 *Notes:
 *	ofstream : output file stream ( can create files )
 * 	ifstream : input file stream
 *  fstream  : general filestream, can do both input and output 
 */
using namespace std;

int checkQuadrant( int a, int b );

int main()
{
	int x, y;

	//	Opens the file for reading 
	ifstream inFile;
	inFile.open( "2.in", ios::in );

	//	get the data values
	inFile >> x;
	inFile >> y;
	inFile.close();			//	closes the file

#if DEBUG
	cout << x << ", " << y << endl;
#endif

	//	write the answer to file
	ofstream outFile;
	outFile.open( "myAns.ans", ios::out );
	outFile << checkQuadrant( x, y );
	outFile.close();

#if DEBUG
	cout << checkQuadrant( x, y );
#endif
}	//	end main

/* Function to check which quadrant a point is in with a, b <> 0
 */
int checkQuadrant( int a, int b )
{
	if ( a > 0 && b > 0 ) {
		return 1;
	}
	else if ( a < 0 && b > 0 ) {
		return 2;
	}
	else if ( a < 0 && b < 0 ) {
		return 3;
	}
	else if ( a > 0 && b < 0 ) {
		return 4;
	}	//	end elifs
}