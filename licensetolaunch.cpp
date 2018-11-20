#include <iostream>
using namespace std;

int main() {
	int n, min = -1, min_index;
	int i = 0, value;

	cin >> n >> min;
	min_index = 0;

	for ( int i = 1; i < n; ++i ) {
		cin >> value;
		if ( value < min ) {
			min = value;
			min_index = i;
		}
	}

	cout << min_index;
	return 0;
}