// Example of using the vector class template

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void outputVector(const vector<int> &);
void inputVector(vector<int> &);

int main()
{
	// Creating vector objects
	vector<int> integers1(7);
	vector<int> integers2(10);

	// size method
	cout << "Size integers1: " << integers1.size() << endl;
	outputVector(integers1);

	cout << "\nSize integers2: " << integers2.size() << endl;
	outputVector(integers2);

	cout << "\nEnter 17 integers:" << endl;
	inputVector(integers1);
	inputVector(integers2);

	cout << "\nAfter input: " << endl;
	outputVector(integers1);
	outputVector(integers2);

	// Overloaded != operator
	if (integers1 != integers2)
		cout << "integers1 != integers2" << endl;

	// Copy constructor
	vector<int> integers3(integers1);
	outputVector(integers3);

	// Overloaded assignment operator
	integers1 = integers2;
	outputVector(integers1);
	outputVector(integers2);

	if (integers1 == integers2)
		cout << "integers1 equals integers2" << endl;

	// r-value
	cout << "\nintegers1[5] is " << integers1[5] << endl;

	// l-value
	integers1[5] = 1000;
	outputVector(integers1);

	// using out of range subscript
	try {
		cout << integers1.at(15) << endl;
	} catch (out_of_range &ex) {
		cout << "An exception occourred: " << ex.what() << endl;
	}
}

void outputVector(const vector<int> &array) 
{
	size_t i;

	for (i = 0; i < array.size(); ++i)
	{
		cout << setw(12) << array[i];

		if ((i + 1) % 4 == 0)
			cout << endl;
	}

	if (i % 4 != 0)
		cout << endl;
}

void inputVector(vector<int> &array)
{
	for (size_t i = 0; i < array.size(); ++i)
		cin >> array[i];
}