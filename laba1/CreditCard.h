#ifndef CREDITCARD_H
#define CREDITCARD_H

#include "ICreditCard.h"
#include <string>

class CreditCard : public ICreditCard {
private:
    std::string cardNumber;
    double creditLimit;
    double currentDebt;
    bool isBlocked;

public:
    CreditCard(const std::string& number, double limit);

    // Геттеры
    const char* getCardNumber() const override;
    double getCreditLimit() const override;
    double getCurrentDebt() const override;
    bool isCardBlocked() const override;

    // Методы управления картой
    void BlockCard() override;
    void AddDebt(double amount) override;

    // Дополнительные методы
    bool canMakePurchase(double amount);
    void makePayment(double amount);
    double getAvailableCredit() const;
};

#endif