// Solution to the "Which Base is it Anyway" problem on open.kattis.com
// Joseph Dempsey, 06/09/2019

#include <iostream>
#include <cstdio>
#define OCT 8
#define HEX 16
#define TEN 10
using namespace std;

/* Will fail- return 0 -if decimal can't be interpreted as an octal number
 */
int asBase(int base, int decimal) {
	int result = 0, x = 1;
	int unit;

	// take off the unit, multiply by x and add onto result
	while (decimal > 0) {
		unit = decimal % TEN;
		if (unit >= base)
			return 0;
		else {
			result +=  unit * x;
			x *= base;
			decimal /= TEN;
		}
	}
	return result;
}

int main() {
	// Take in size of data set
	int K, setNum, decimal;
	cin >> K;

	for (int i = 0; i < K; ++i) {
		cin >> setNum >> decimal;
		printf("%d %d %d %d\n", setNum, asBase(OCT, decimal), decimal, asBase(HEX, decimal));
	}
}