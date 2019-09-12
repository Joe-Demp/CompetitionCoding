#import <cmath>

// Unary: overloaded as a member function with no arguments
//		or as a global function with one argument
// Binary: similar (one argument inside the class, two outside)

// Dynamic Memory Allocation
// new and delete

// e.g. new returns a pointer to the newly allocated memory
Time *timePtr = new Time;
delete timePtr;

// arrays
int *myNumbers = new int[10];	//Note: int myNumbers[] = new int[10] *not allowed*
delete [] myNumbers;			//Note delete without [] is undefined on arrays

// Conversion constructors
//	single argument constructors that turn objects of one class into another
// e.g.

class String
{
public:
	String();
	String(char*);	// conversion constructor, converts C style strings to String objects
};

// Conversion Operator e.g.
class Complex
{
public:
	Complex(int real, int imag)
		: a(real), b(imag)
	{
		// empty constructor
	}

	operator double() {	// syntax: operator destination-type() {}
		return getMag();// return type specified by the destination type
	}
	

private:
	double a;
	double b;

	double getMag() {
		return sqrt(a*a + b*b);
	}
};


// Overloading Unary operators
// e.g.
class Count
{
public:
	Count &operator++();		// prefix increment operator
	Count operator++(int);		// postfix increment operator
		// dummy integer flags that it's a postfix operator

private:
	int i;
};

// takes the calling object, increments it and returns a reference to said object
Count &Count::operator++()
{
	++i;
	return *this;
}

// takes the calling object, makes a copy of it, increments the original and returns the copy 
// 	Note the dummy variable needn't have a name
Count Count::operator++(int)
{
	Count returned(*this);
	++i;
	return returned;
}

// Constructors can be declared explicit to prevent implicit conversions
// e.g.
class Array
{
public:
	Array();
	explicit Array(int = 10);
// etc.
};

void outputArray(Array &a) {
	// ..
}

// declaring the conversion constructor as implicit prevents outputArray being 
//	called with an int argument
// can still call: outputArray( Array(3) ) (explicitly)



