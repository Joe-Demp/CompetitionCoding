#include <iostream>
using namespace std;

// Example date class
class Date
{
public:
	Date(int d = 1, int m = 1, int y = 2000) {
		day = d;
		month = m;
		year = y;
	}

	// Note on const
	/* const objects may only call const member functions, even if they don't modify data
	 * A const member function can be overloaded with a non-const version
	 *  the appropriate version is called depending on whether or not the calling object is itself const
	 */
	void print() const 
	{
		cout << day << "/" << month << "/" << year;
	}
private:
	int day;
	int month;
	int year;
};

// Note: cannot initialise const members inside the Constructor
class Increment
{
public:
	Increment(int c = 0, int i = 1)
		:count(c),		//optional initialiser for a non-const member
		 increment(i)	//mandatory initialiser for a const member
	{
		//empty constructor
	}

	//other functions left out
private:
	int count;
	const int increment;
};

/* Member initializer lists also useful for copying objects (using a default copy constructor)
 * to be composed in teh initialized object
 *  e.g. for an employee with a field 'hireDate', you could have hireDate( day1 )
 			in the initializer list, even though there is no such constructor in the Date class
 */