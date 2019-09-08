#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee
{
public:
    Employee( const string &, const string &, const string & );

    void setFirstName( const string & );
    string getFirstName() const;

    void setLastName( const string & );
    string getLastName() const;

    void setSocialSecurityNumber( const string & );
    string getSocialSecurityNumber() const;

    //  pure virtual function makes Employee an abstract base class
    virtual double earnings() const = 0;    //  pure virtual
    virtual void print() const;             //  virtual
private:
    string firstName;
    string lastName;
    string socialSecurityNumber;
};  //  end class Employee

#endif
