#include <iostream>
#include <string>
using namespace std;

int temp;

#define SWAP( A, B ) temp = A; 	\
					 A = B; 	\
					 B = temp;

int main()
{
	int cups[] = { 1, 0, 0 }, len;
	string moves;
	cin >> moves;
	len = moves.size();

	for ( int i = 0; i < len; ++i )
	{
		switch ( moves[ i ] )
		{
		case 'A':
			SWAP( cups[ 0 ], cups[ 1 ] );
			break;

		case 'B':
			SWAP( cups[ 1 ], cups[ 2 ] );
			break;

		case 'C':
			SWAP( cups[ 0 ], cups[ 2 ] );
			break;

		default:
			cerr << "Something went wrong with the switch statement" << '\n'
			<< cups[ 0 ] << cups[ 1 ] << cups[ 2 ] << endl;
		}		//		end switch
	}		//		end for

	//		print the number of the cup
	for ( int i = 0; i < 3; ++i )
		if ( cups[ i ] == 1 )
			cout << i + 1;

	return 0;
}	//	end main