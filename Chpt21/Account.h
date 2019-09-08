#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
public:
    Account( double );

    void setBalance( double );
    double getBalance() const;

    void credit( double );
    void debit( double );
private:
    double balance;
};  //  end class Account

#endif
