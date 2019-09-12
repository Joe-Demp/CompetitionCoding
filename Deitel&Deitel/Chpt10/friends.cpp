#include <iostream>
using namspace std;

/* friend: defined outside a class's scope but has rights to access all class members, public and private
 * standalone functions, entire classes or member functions can be friends
 * 
 * e.g. below 
 */

class Count
{
	// friend components supercede public, private etc. Place at the top 
	friend void setX(Count &, int);
public:
	Count()
		: x(0)
	{
		// empty constructor
	}

	void print() const {
		cout << x << endl;
	}
private:
	int x;
};

// Definition of friend function.
// Not inside scope of class (no Count:: operator)
// Still has access to all members
void setX(Count &c, int val) {
	c.x = val;
}
