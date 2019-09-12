#include <iostream>
using namespace std;

// a function that uses a pointer to a function as a parameter
void selectionSort(int [], const int, bool (*)(int, int));

int main()
{
	int variable;
	int array[10];
	// nonconstant pointer to nonconstant data
	int *a;

	// nonconstant pointer to constant data
	// "b is a pointer to an integer constant"
	const int *b;

	// example
	int y;
	b = &y;
	y = 100;
	
	// compilation error, changing the value of y *through* b
	// *b += 50;

	// constant pointer to nonconstant data
	// "c is a constant pointer to an integer"
	int * const c = &variable;

	// constant pointer to constant data
	const int * const d = &variable;


	// sizeof operator
	cout << sizeof(array) << endl;
	cout << sizeof array << endl;
	cout << sizeof(long double) << endl;
	cout << sizeof variable << endl;
}

// Definition of the function declared above
// compare is a pointer to a function that takes in two integers and returns a bool
void selectionSort(int work[], const int size, bool (*compare)(int, int))
{
	// empty
}