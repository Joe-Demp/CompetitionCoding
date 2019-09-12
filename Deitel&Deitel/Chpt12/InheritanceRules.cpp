// friend functions are not inherited

// protected members
// can be accessed within the body of a base class, by members and friends of that base class
//	and by members and friends of any class that inherits the base class

// e.g. inheritance with the Shape class

class Shape
{
public:
	Shape(Colour &) {/*constructor code*/}
	void print() const;
	double area();
	Colour getColour();
private:
	Colour c;
}

class Triangle : public Shape
{
public:
	Triangle(Colour &c, double b, double h)
		: Shape(c), 		// base class initializer syntax
		base(b), height(h)
	{
		// empty constructor
	}

	void setBase(double);
	void setHeight(double);
	// etc
private:
	double base;
	double height;
}

// Note, must use base class initializer syntax
//	otherwise default (implicit) constructor is called or compilation error
// must also #include base class's .h file
// To call a base class function: preceed the call with BaseClass::
// 	useful for overrides
// Base class constructors, destructors and overloaded assignment operators are not inherited

// public protected private
//
// private data hidden from derived class in all cases
// in general, the derived class sees the most hidden version
// i.e. if a method is public in the base class but the class is inherited as protected, then the method is protected in the derived class etc.


