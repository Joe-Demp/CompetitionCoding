#include <iostream>
#include "Account.h"

Account::Account( double bal )
{
    setBalance( bal );
}   //  end constructor

void Account::setBalance( double bal )
{
    balance = bal;
}

double Account::getBalance() const
{
    return balance;
}

void Account::credit( double amount )
{
    balance += amount;
}   //  end credit

void Account::debit( double amount )
{
    balance -= amount;
}   //  end credit
