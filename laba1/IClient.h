#ifndef ICLIENT_H
#define ICLIENT_H

class BankAccount;

class IClient {
public:
    virtual int getClientId() const = 0;
    virtual const char* getName() const = 0;
    virtual const char* getPhoneNumber() const = 0;
    virtual bool payOrder(double amount) = 0;
    virtual bool transferTo(BankAccount& target, double amount) = 0;
    virtual void closeAccount() = 0;
    virtual void blockCard() = 0;
    virtual ~IClient() = default;
};

#endif