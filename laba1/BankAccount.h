#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include "IBankAccount.h"
#include <string>

class BankAccount : public IBankAccount {
private:
    int accountId;
    double balance;
    std::string currency;

public:
    BankAccount(int id, double balance, const std::string& currency);

    // Геттеры
    int getAccountId() const override;
    double getBalance() const override;
    const char* getCurrency() const override;

    // Методы платежей
    bool PayOrder(double amount) override;
    bool TransferTo(BankAccount& target, double amount) override;
    void CloseAccount() override;

    // Дополнительные методы
    void deposit(double amount);
    bool withdraw(double amount);
};

#endif