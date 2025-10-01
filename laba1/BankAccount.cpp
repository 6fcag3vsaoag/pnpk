#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount(int id, double bal, const std::string& curr)
    : accountId(id), balance(bal), currency(curr) {
}

int BankAccount::getAccountId() const {
    return accountId;
}

double BankAccount::getBalance() const {
    return balance;
}

const char* BankAccount::getCurrency() const {
    return currency.c_str();
}

bool BankAccount::PayOrder(double amount) {
    if (balance >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}

bool BankAccount::TransferTo(BankAccount& target, double amount) {
    if (balance >= amount) {
        balance -= amount;
        target.deposit(amount);
        return true;
    }
    return false;
}

void BankAccount::CloseAccount() {
    balance = 0.0;
    std::cout << "Банковский аккаунт " << accountId << " закрыт" << std::endl;
}

void BankAccount::deposit(double amount) {
    balance += amount;
}

bool BankAccount::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}