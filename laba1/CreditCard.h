#ifndef CREDIT_CARD_H
#define CREDIT_CARD_H

#include <string>

class CreditCard {
private:
    std::string cardNumber;
    double creditLimit;
    double currentDebt;
    bool isBlocked;

public:
    CreditCard(const std::string& number, double limit);
    ~CreditCard() = default;

    // Геттеры
    std::string getCardNumber() const;
    double getCreditLimit() const;
    double getCurrentDebt() const;
    bool isCardBlocked() const;

    // Операции
    void BlockCard();
    void AddDebt(double amount); // Вспомогательный метод для демонстрации
};

#endif // CREDIT_CARD_H