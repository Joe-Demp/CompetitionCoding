#ifndef SALARIED_H
#define SALARIED_H

#include "Employee.h"

class SalariedEmployee : public Employee
{
public:
    SalariedEmployee( const string &, const string &,
        const string &, double = 0.0 );

    void setWeeklySalary( double );
    double getWeeklySalary() const;

    //  keyword virtual signals intent to override
    virtual double earnings() const;    //  'virtual' not necessary 
    virtual void print() const;
private:
    double weeklySalary;
};  //  end class SalariedEmployee

#endif
