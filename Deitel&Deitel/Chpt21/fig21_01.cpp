#include <iostream>
#include <iomanip>
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"
using namespace std;

int main()
{
    //  create base-class object
    CommissionEmployee commissionEmployee(
        "Sue", "Jones", "222-22-2222", 10000, .06);

    //  create base-class pointer
    CommissionEmployee *commissionEmployeePtr = 0;

    //  create derived-class object
    BasePlusCommissionEmployee basePlusCommissionEmployee(
        "Bob", "Lewis", "333-33-3333", 5000, .04, 300 );

    //  create derived-class pointer
    BasePlusCommissionEmployee *basePlusCommissionEmployeePtr = 0;

    //  set floating-point output formatting
    cout << fixed << setprecision( 2 );

    //  output objects using static binding
    cout << "Invoking print function on base-class and derived class "
        << "\nobjects with static binding\n\n";
    commissionEmployee.print();
    cout << "\n\n";
    basePlusCommissionEmployee.print();

    //  output objects using dynamic binding
    cout << "\n\n\nInvoking print function on base-class and "
        << "derived-class \nobjects with dynamic binding";

    //  aim base class pointer at base-class object and print
    commissionEmployeePtr = &commissionEmployee;
    cout << "\n\nCalling virtual function print with base-class pointer to "
        << "\nbase-class object invokes base-class print function:\n\n";
    commissionEmployeePtr->print();    //  invokes base-class print

    //  aim derived-class pointer at derived-class object and print
    basePlusCommissionEmployeePtr = &basePlusCommissionEmployee;
    cout << "\n\n\nCalling print with derived-class pointer to "
        << "\nderived-class object invokes derived-class "
        << "print function:\n\n";
    basePlusCommissionEmployeePtr->print(); //  invokes derived-class print

    // aim base-class pointer at derived-class object and print
    commissionEmployeePtr = &basePlusCommissionEmployee;
    cout << "\n\n\nCalling virtual print with base-class pointer to "
        << "derived-class object\ninvokes derived-class print "
        << "function on that derived-class object:\n\n";
    commissionEmployeePtr->print(); //  invokes base-class print
    cout << endl;
}   //  end main
