#include "CreditCard.h"
#include <iostream>

CreditCard::CreditCard(const std::string& number, double limit)
    : cardNumber(number), creditLimit(limit), currentDebt(0.0), isBlocked(false) {}

std::string CreditCard::getCardNumber() const { return cardNumber; }
double CreditCard::getCreditLimit() const { return creditLimit; }
double CreditCard::getCurrentDebt() const { return currentDebt; }
bool CreditCard::isCardBlocked() const { return isBlocked; }

void CreditCard::BlockCard() {
    isBlocked = true;
    std::cout << "Card " << cardNumber << " has been BLOCKED.\n";
}

void CreditCard::AddDebt(double amount) {
    if (isBlocked) {
        std::cout << "Cannot add debt: Card is blocked.\n";
        return;
    }
    if (currentDebt + amount > creditLimit) {
        std::cout << "Warning: Adding this debt will exceed credit limit!\n";
    }
    currentDebt += amount;
    std::cout << "Debt added: " << amount << ". Current debt: " << currentDebt << "/" << creditLimit << "\n";
}