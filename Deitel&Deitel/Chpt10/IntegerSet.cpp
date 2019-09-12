#include <iostream>
#include "IntegerSet.h"
using namespace std;

// Constructor sets all values to false: empty set
IntegerSet::IntegerSet()
	: a(SIZE)	// initialize a as a vector with capacity 100
{
	for (int i = 0; i < SIZE; ++i)
		a[i] = false;
}

IntegerSet::IntegerSet(int array[], int arraySize)
	: IntegerSet()
{
	for (int i = 0; i < arraySize; ++i)
		insertElement(array[i]);
}

IntegerSet IntegerSet::unionOfSets(const IntegerSet &other) const
{
	IntegerSet result;

	for (int i = 0; i < SIZE; ++i) {
		if (this->a[i] || other.a[i])
			result.a[i] = true;
	}

	return result;
}

IntegerSet IntegerSet::intersectionOfSets(const IntegerSet &other) const
{
	IntegerSet result;

	for (int i = 0; i < SIZE; ++i) {
		if (this->a[i] && other.a[i])
			result.a[i] = true;
	}

	return result;
}

// Returns true if the element has been 'inserted'
// Returns false if the element was already present or O.O.B.
bool IntegerSet::insertElement(int element)
{
	// bounds checking
	if (element < 0 || element >= SIZE)
		return false;

	if (a[element])		// element already present
		return false;
	else {				// element not present
		a[element] = true;
		return true;
	}
}

// Returns true if the element has been 'deleted'
// Returns false if the element was not present or O.O.B.
bool IntegerSet::deleteElement(int element)
{
	// bounds checking
	if (element < 0 || element >= SIZE)
		return false;

	if (a[element]) {	// element can be deleted
		a[element] = false;
		return true;
	} else 				// element not present
		return false;
}

void IntegerSet::printSet() const
{
	cout << "{";
	for (int i = 0; i < SIZE; ++i) 
		if (a[i])
			cout << i << " ";

	cout << "}";
}

bool IntegerSet::isEqualTo(const IntegerSet &other) const
{
	for (int i = 0; i < SIZE; ++i)
		if (this->a[i] != other.a[i])
			return false;

	return true;
}
