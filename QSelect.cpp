#include <iostream>

using namespace std;

int checkQuadrant( int a, int b );

int main()
{
	int x, y;

	//	get the data values
	cin >> x;
	cin >> y;

	//	write the answer
	cout << checkQuadrant( x, y );
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