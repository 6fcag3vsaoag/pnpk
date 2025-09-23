#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount(int id, double initialBalance, const std::string& curr)
    : accountId(id), balance(initialBalance), currency(curr) {}

int BankAccount::getAccountId() const { return accountId; }
double BankAccount::getBalance() const { return balance; }
std::string BankAccount::getCurrency() const { return currency; }

bool BankAccount::PayOrder(double amount) {
    if (amount <= 0) {
        std::cout << "Error: Payment amount must be positive.\n";
        return false;
    }
    if (balance < amount) {
        std::cout << "Error: Insufficient funds. Balance: " << balance << " " << currency << "\n";
        return false;
    }
    balance -= amount;
    std::cout << "Payment of " << amount << " " << currency << " successful. New balance: " << balance << "\n";
    return true;
}

bool BankAccount::TransferTo(BankAccount* target, double amount) {
    if (!target) {
        std::cout << "Error: Target account is null.\n";
        return false;
    }
    if (amount <= 0) {
        std::cout << "Error: Transfer amount must be positive.\n";
        return false;
    }
    if (balance < amount) {
        std::cout << "Error: Insufficient funds for transfer. Balance: " << balance << " " << currency << "\n";
        return false;
    }
    balance -= amount;
    target->balance += amount; // Прямой доступ, так как в рамках одного класса/дружественной логики
    std::cout << "Transfer of " << amount << " " << currency << " to account " << target->getAccountId() << " successful.\n";
    return true;
}

void BankAccount::CloseAccount() {
    if (balance != 0) {
        std::cout << "Warning: Account " << accountId << " closed with non-zero balance: " << balance << " " << currency << "\n";
    } else {
        std::cout << "Account " << accountId << " successfully closed.\n";
    }
    // В реальной системе здесь мог бы быть код для архивации или блокировки в БД.
}