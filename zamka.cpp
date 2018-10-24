#include <iostream>
using namespace std;

#define MAX_INPUT 10000

int sumOfDigits( int x )
{
	int sum = 0;
	int divisor = MAX_INPUT;
	while ( x > 0 )
	{
		sum += x / divisor;	//	clip off the top digit
		x = x % divisor;	//	keep the rest

		divisor /= 10;		//	decrease the divisor
	}	//	end while

	return sum;
}	//	end sumOfDigits

int main() 
{
	int L, D, X, N, M;
	int counter;
	
	//	get input
	cin >> L >> D >> X;

	//	Do some computation
	//	finding N, keep counting until the sum is correct
	counter = L;
	while ( sumOfDigits( counter ) != X ) counter++;
	N = counter;

	//	finding M, keep counting down similarly
	counter = D;
	while ( sumOfDigits( counter ) != X ) counter--;
	M = counter;

	//	Return the outputs
	cout << N << endl;
	cout << M << endl;
	return 0;
}	//	end main