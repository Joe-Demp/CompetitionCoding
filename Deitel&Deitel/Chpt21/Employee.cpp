#include <iostream>
#include "Employee.h"
using namespace std;

//  constructor
Employee::Employee( const string &first, const string &last,
    const string &ssn )
    : firstName( first ), lastName( last ), socialSecurityNumber( ssn )
{
    //  empty body
}   //  end constructor

void Employee::setFirstName( const string &first )
{
    firstName = first;
}

string Employee::getFirstName() const
{
    return firstName;
}

void Employee::setLastName( const string &last )
{
    lastName = last;
}

string Employee::getLastName() const
{
    return lastName;
}

void Employee::setSocialSecurityNumber( const string &ssn )
{
    socialSecurityNumber = ssn;
}

string Employee::getSocialSecurityNumber() const
{
    return socialSecurityNumber;
}

void Employee::print() const             //  virtual
{
    cout << getFirstName() << ' ' << getLastName()
        << "\nSocial Security Number: " << getSocialSecurityNumber();
}
