#include <iostream>
using namespace std;

// example programme, for notes (D&D p 458)

// Example date class
class Date
{
public:
	Date(int d = 1, int m = 1, int y = 2000) {
		day = d;
		month = m;
		year = y;
	}

	// Note defining functions inside the class definition inlines them
	// i.e. advises the compiler to inline them
	void print() const {
		cout << day << "/" << month << "/" << year;
	}
private:
	int day;
	int month;
	int year;
};

int main()
{
	Date d1(2, 8, 1996);
	
	/*Default memberwise assignment
	 * each data member of d1 is copied onto d2
	 * Causes problems r.e. pointers to dynamic memory
	 * Copy Constructor required
	 * Passing objects to functions causes them to be copied, degrading performance
	 * pass references instead (esp. const reference)
	 */
	Date d2 = d1;
}

/*
 *Notes on Scope
 * Member functions declared in a header and defined within a seperate file are still within their class's scope
 * i.e. it has access to the class's data etc.
 * */