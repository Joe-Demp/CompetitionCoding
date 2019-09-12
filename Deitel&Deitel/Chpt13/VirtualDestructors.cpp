// applying delete to a Base class pointer, pointing to a derived class object, leads to undefined behaviour
//	use virtual destructor in the base class
//	virtual applies to all destructors in subclasses (even those with different names)

// e.g. Polymorphism.cpp