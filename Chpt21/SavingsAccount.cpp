#include <iostream>
#include "SavingsAccount.h"

SavingsAccount::SavingsAccount( double bal, double rate )
    : Account( bal )
{
    setInterestRate( rate );
}   //  end constructor

void SavingsAccount::setInterestRate( double rate )
{
    interestRate = rate;
}

double SavingsAccount::getInterestRate() const
{
    return interestRate;
}

double SavingsAccount::calculateInterest() const
{
    return getBalance() * getInterestRate();
}

void SavingsAccount::applyInterest()
{
    credit( calculateInterest() );
}
