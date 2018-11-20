#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long result = 0;
	int i, j, N, base, power, subtotal;
	cin >> N;

	for ( i = 0; i < N; ++i ) {
		cin >> base;
		power = base % 10;
		base /= 10;
		subtotal = 1;

		for ( j = 0; j < power; ++j )
			subtotal *= base;

		result += subtotal;
	} 	//	end for

	cout << result;
	return 0;
}