#include <iostream>
#include <string>
using namespace std;

/* static members have class scope
 * can be initialised once
 * static const ints or enums can be initialised at declaration
 * 	all other static objects must be defined at global namespace scope (outside the class definition)
 *
 */

// e.g. a class with static members
class Martian
{
public:
	Martian(string);
	static int getCount() const;
	static string martianMessage;
private:
	static const int martianCount = 0;
};

int main()
{
	// e.g. call to a static function
	cout << Martian::getCount();

	// accessing a public static object
	cout << Martian::martianMessage;

	// Note: Martian message must be defined in another file (once)
}

/*******************************
e.g. definition of martianMessage in a seperate file,
note: no static keyword (only at declaration)
*/
string Martian::martianMessage("Hello, welcome to Mars!");