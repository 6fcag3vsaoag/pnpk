#ifndef ICREDITCARD_H
#define ICREDITCARD_H

class CreditCard;

class ICreditCard {
public:
    virtual const char* getCardNumber() const = 0;
    virtual double getCreditLimit() const = 0;
    virtual double getCurrentDebt() const = 0;
    virtual bool isCardBlocked() const = 0;
    virtual void BlockCard() = 0;
    virtual void AddDebt(double amount) = 0;
    virtual ~ICreditCard() = default;
};

#endif