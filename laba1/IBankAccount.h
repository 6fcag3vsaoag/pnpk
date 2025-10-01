#ifndef IBANKACCOUNT_H
#define IBANKACCOUNT_H

class BankAccount;

class IBankAccount {
public:
    virtual int getAccountId() const = 0;
    virtual double getBalance() const = 0;
    virtual const char* getCurrency() const = 0;
    virtual bool PayOrder(double amount) = 0;
    virtual bool TransferTo(BankAccount& target, double amount) = 0;
    virtual void CloseAccount() = 0;
    virtual ~IBankAccount() = default;
};

#endif