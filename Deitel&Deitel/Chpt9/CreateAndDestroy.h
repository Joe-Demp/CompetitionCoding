#include <string>
using namespace std;

#ifndef CREATE_H
#define CREATE_H

class CreateAndDestroy
{
public:
	CreateAndDestroy(int, string);

	// Destructor Notes
	/*
	* May not receive parameters or return a value
	* Performs termination housekeeping before the object's memory is released
	* Must be public
	* Every class has an implicit empty destructor
	* Useful to define a destructor to deal with: dynamically allocated memory, file streams etc.
	*/
	~CreateAndDestroy();
private:
	int objectID;
	string msg;
};
#endif