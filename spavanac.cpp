#include <iostream>
using namespace std;

int main() {
	int H, M;
	cin >> H >> M;

	M -= 45;
	if ( M < 0 ) {
		M += 60;
		H--;
	}	//	end if

	if ( H < 0 ) 
		H += 24;

	cout << H << " " << M;
	return 0;
}	//	end main