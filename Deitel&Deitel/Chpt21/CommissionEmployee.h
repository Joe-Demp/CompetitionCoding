#ifndef COMMISSION_H
#define COMMISSION_H

#include "Employee.h"


class CommissionEmployee : public Employee
{
public:
    CommissionEmployee ( const string &, const string &,
        const string &, double = 0.0, double = 0.0 );

    void setGrossSales( double );
    double getGrossSales() const;

    void setCommissionRate( double );
    double getCommissionRate() const;

    //  keyword virtual signals intent to override
    virtual double earnings() const;    //  calculate earnings
    virtual void print() const;         //  print CommissionEmployee object
private:
    double grossSales;
    double commissionRate;
};  //  end class CommissionEmployee

#endif
