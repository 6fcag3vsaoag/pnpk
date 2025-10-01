#include "CreditCard.h"
#include <iostream>
#include <iomanip>

CreditCard::CreditCard(const std::string& number, double limit)
    : cardNumber(number), creditLimit(limit), currentDebt(0.0), isBlocked(false) {
}

const char* CreditCard::getCardNumber() const {
    return cardNumber.c_str();
}

double CreditCard::getCreditLimit() const {
    return creditLimit;
}

double CreditCard::getCurrentDebt() const {
    return currentDebt;
}

bool CreditCard::isCardBlocked() const {
    return isBlocked;
}

void CreditCard::BlockCard() {
    isBlocked = true;
    std::cout << "Кредитная карта заблокирована" << std::endl;
}

void CreditCard::AddDebt(double amount) {
    currentDebt += amount;
}

bool CreditCard::canMakePurchase(double amount) {
    return !isBlocked && (currentDebt + amount) <= creditLimit;
}

void CreditCard::makePayment(double amount) {
    if (amount <= currentDebt) {
        currentDebt -= amount;
        std::cout << "Платеж выполнен на сумму: " << std::fixed << std::setprecision(2) << amount << std::endl;
    } else {
        std::cout << "Сумма платежа превышает текущий долг" << std::endl;
    }
}

double CreditCard::getAvailableCredit() const {
    return creditLimit - currentDebt;
}