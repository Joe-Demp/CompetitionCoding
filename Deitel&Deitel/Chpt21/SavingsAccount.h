#include "Account.h"

#ifndef SAVINGS_H
#define SAVINGS_H

class SavingsAccount : public Account
{
public:
    SavingsAccount( double, double );

    void setInterestRate( double );
    double getInterestRate() const;

    double calculateInterest() const;
    void applyInterest();
private:
    double interestRate;
};  //  end class SavingsAccount

#endif
