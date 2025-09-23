#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
#include <string>

class BankAccount {
private:
    int accountId;
    double balance;
    std::string currency;

public:
    BankAccount(int id, double initialBalance, const std::string& curr);
    ~BankAccount() = default;

    // Геттеры
    int getAccountId() const;
    double getBalance() const;
    std::string getCurrency() const;

    // Основные операции
    bool PayOrder(double amount);
    bool TransferTo(BankAccount* target, double amount);
    void CloseAccount();
};

#endif // BANK_ACCOUNT_H
