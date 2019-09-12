// C++ compiles a class with virtual functions
//	creates a "virtual function table" (vtable)

// Three levels of pointers: triple indirection
// * pointers in vtable to virtual functions
// * pointer from an instantiated object to its vtable
// * handles contain pointers/references to objects

// compiler calculates offset of the correct function in the vtable of the object to find the right function


// Dynamic casting
// e.g. employees
#include <vector>
#include <typeinfo>

vector<Employee *> employees(3);
employees[ 0 ] = new SalariedEmployee("John", "Smith", "111-11-1111", 800 );
employees[ 1 ] = new CommissionEmployee("Sue", "Jones", "333-33-3333", 10000, .06 );
employees[ 2 ] = new BasePlusCommissionEmployee("Bob", "Lewis", "444-44-4444", 5000, .04, 300 );

for (size_t i = 0; i < employees.size(); ++i) {
	// Downcast pointer
	BasePlusCommissionEmployee *derivedPtr = 
		dynamic_cast<BasePlusCommissionEmployee *>(employees[i]);

	if (derivedPtr != 0) // downcast successful
	{
		// do something
	}
	//downcast unsuccessful if trying to downcast an object of a superclass
	//	=> derivedPtr := 0
}

// using typeinfo
// e.g. in Polymorphism.cpp
for (size_t j = 0; j < employees.size(), ++j)
{
	cout << typeid(*employees[j]).name() << endl;
}
