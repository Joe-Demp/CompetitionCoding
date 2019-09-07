#include <iostream>

using namespace std;

int fib(int n) {
	int f_2 = 0, f_1 = 1, tmp;

	for (int i = 0; i < n; ++i) {
		tmp = f_1;
		f_1 += f_2;
		f_2 = tmp;
	}
	return f_1;
}

int main() {
	for (int i = 0; i < 20; ++i) {
		cout << i << " : " << fib(i) << endl;
	}
}