#include <iostream>
using namespace std;

int main()
{
		int X, N, P, mbLeft;
		cin >> X >> N;

		mbLeft = X * N;
		for ( int i = 0; i < N; ++i )
		{
			cin >> P;
			mbLeft -= P;
		}

		cout << mbLeft + X;

		return 0;
}