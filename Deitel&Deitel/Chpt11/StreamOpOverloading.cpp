// Operator overloading with non-static functions (operators called on class members)
// No implicit overloading: overloading + and = does not imply that += is overloaded

// () [] -> or any of the assignment (=) operators must be overloaded using a class member function
// all of the others can be class members or standalone functions

// operator member functions can only accept objects of their class as their leftmost argument
// e.g. with BigInteger: x + y, for overloaded operator +
//			if the + function is inside the class, x MUST be a BigInteger
//			outside the class, it might be any numeric data type and y may be a BigInteger

// operator functions can be friends if they need to access class data

// e.g.
#include <iostream>
#include <string>
using namespace std;

class Alien
{
	friend ostream &operator<<(ostream &, const Alien &);
	friend istream &operator>>(istream &, Alien &);
private:
	string name;
};

ostream &operator<<(ostream &output, const Alien &a) 
{
	output << a.name;
	return output;		// enables cascading calls
}

istream &operator>>(istream &input, Alien &a)
{
	input >> a.name;
	return input;		// cascading calls
}

int main()
{
	Alien joey;
	cin >> joey;
	cout << "The alien's name is: " << joey;
}