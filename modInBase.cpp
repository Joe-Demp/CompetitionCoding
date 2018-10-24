#include <iostream>
#include <cmath>

using namespace std;

/*Sections of a programme to take in two numbers p and m in base b
 *	perform p % m and return the answer in base b

 *	Ideas so far are to convert the inputs into base 10
 *		perform the operation, convert back to base b and return the output
 * 	
 *	May not be optimal 
 */

long long convertToBase( long long b, long long convertant )
{
	long long newNumber = 0;
	long long place = 1;
	long long remainder;

	while ( convertant > 0 )
	{
		remainder = convertant % b;
		convertant /= b;
		newNumber += remainder * place; 
		place *= 10;

		// cerr << "b = " << b 
		// 	<< "\nconvertant = " << convertant 
		// 	<< "\nnewNumber = " << newNumber << endl;
	}	//	end while

	return newNumber;
}	//	end cTB

long long convertFromBase( long long b, long long convertant )
{
	long long newNumber = 0;
	long long basePower = 1;
	long long divisor = 1;
	long long decimalSlicer = 1;

	//	Find a decimal number that is larger than convertant
	while ( convertant > decimalSlicer ) {
		decimalSlicer *= 10;
	}
	//	Then divide it by 10 to create the slicer
	decimalSlicer /= 10;

	while ( convertant > 0 ) {

	}	//	end while
}	//	end cFB

int main()
{
	long long a, b;

	cin >> a >> b;

	cout << convertToBase( a, b );
	return 0;
}	//	end main