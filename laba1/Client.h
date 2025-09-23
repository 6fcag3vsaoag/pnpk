#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "BankAccount.h"
#include "CreditCard.h"

class Client {
private:
    int clientId;
    std::string name;
    std::string phoneNumber;

    BankAccount* account; // Ассоциация: один счет
    CreditCard* card;     // Ассоциация: одна карта

public:
    Client(int id, const std::string& clientName, const std::string& phone);
    ~Client(); // Деструктор для корректного удаления

    // Геттеры
    int getClientId() const;
    std::string getName() const;
    std::string getPhoneNumber() const;

    // Управление счетом и картой
    void setBankAccount(BankAccount* acc);
    void setCreditCard(CreditCard* cc);

    BankAccount* getBankAccount() const;
    CreditCard* getCreditCard() const;

    // Операции клиента
    bool payOrder(double amount);
    bool transferTo(BankAccount* target, double amount);
    void closeAccount();
    void blockCard();
};

#endif // CLIENT_H