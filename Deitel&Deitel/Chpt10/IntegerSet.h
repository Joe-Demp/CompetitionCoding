#include <vector>
#include <iostream>

#ifndef IN_SET
#define IN_SET
#define SIZE 100

class IntegerSet
{
public: 
	IntegerSet();
	IntegerSet(int [], int);

	IntegerSet unionOfSets(const IntegerSet &) const;
	IntegerSet intersectionOfSets(const IntegerSet &) const;

	bool insertElement(int);
	bool deleteElement(int);

	void printSet() const;
	bool isEqualTo(const IntegerSet &) const;
private:
	std::vector<bool> a;
};

#endif