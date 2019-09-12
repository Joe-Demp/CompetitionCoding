#include <iostream>
#include <iomanip>
#include <vector>
#include <typeinfo>
#include "Employee.h"
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"
using namespace std;

int main()
{
    cout << fixed << setprecision( 2 );

    vector < Employee * > employees( 3 );

    employees[ 0 ] = new SalariedEmployee(
        "John", "Smith", "111-11-1111", 800 );
    employees[ 1 ] = new CommissionEmployee(
        "Sue", "Jones", "333-33-3333", 10000, .06 );
    employees[ 2 ] = new BasePlusCommissionEmployee(
        "Bob", "Lewis", "444-44-4444", 5000, .04, 300 );

    //  polymorphically process each element in vector employees
    for ( size_t i = 0; i < employees.size(); ++i )
    {
        employees[ i ]->print();
        cout << endl;

        //  downcast pointer
        BasePlusCommissionEmployee *derivedPtr =
            dynamic_cast < BasePlusCommissionEmployee * >
                ( employees[ i ] );

        //  determine whether element points to base-salaried
        //  commission employee
        if ( derivedPtr != 0 )  //  0 if not a BasePlusCommissionEmployee
        {
            double oldBaseSalary = derivedPtr->getBaseSalary();
            cout << "old base salary: $" << oldBaseSalary << endl;
            derivedPtr->setBaseSalary( 1.1 * oldBaseSalary );
            cout << "new base salary with 10% increase is: $"
                << derivedPtr->getBaseSalary() << endl;
        }   //  end if

        cout << "earned $" << employees[ i ]->earnings() << "\n\n";
    }   //  end for

    //  release objects pointed to by vector's elements
    for ( size_t j = 0; j < employees.size(); ++j )
    {
        cout << "deleting object of "
            << typeid( *employees[ j ] ).name() << endl;

        delete employees[ j ];
    }   //  end for
}   //  end main
