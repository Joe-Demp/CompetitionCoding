#ifndef BASEPLUS_H
#define BASEPLUS_H

#include "CommissionEmployee.h"

class BasePlusCommissionEmployee : public CommissionEmployee
{
public:
    BasePlusCommissionEmployee( const string &, const string &,
        const string &, double = 0.0, double = 0.0, double = 0.0 );

    void setBaseSalary( double );
    double getBaseSalary() const;

    //  keyword virtual signals intent to override
    virtual double earnings() const;
    virtual void print() const;

    virtual ~BasePlusCommissionEmployee();
private:
    double baseSalary;
};  //  end class BasePlusCommissionEmployee

#endif
