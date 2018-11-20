#include <iostream>
using namespace std;

int main() {
	int side_dots = 2;
	int k, iterations;
	cin >> iterations;

	for ( k = 0; k < iterations; ++k ) {
		side_dots += side_dots - 1;
	}

	cout << side_dots * side_dots;
	return 0;
}