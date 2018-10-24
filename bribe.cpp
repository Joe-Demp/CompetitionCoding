#include <iostream>

using namespace std;

int main()
{
	int articles, ifactor; 
	int citations;
	cin >> articles >> ifactor;

	cout << ( articles * ( ifactor - 1 )) + 1;

	return 0;
}