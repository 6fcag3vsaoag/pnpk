#ifndef CLIENT_H
#define CLIENT_H

#include "IClient.h"
#include "IBankAccount.h"
#include "ICreditCard.h"
#include "IOrder.h"
#include <vector>
#include <string>

class BankAccount;
class CreditCard;
class Order;

class Client : public IClient {
private:
    int clientId;
    std::string name;
    std::string phoneNumber;
    BankAccount* account;
    CreditCard* card;
    std::vector<Order*> orders;

public:
    Client(int id, const std::string& name, const std::string& phone);
    ~Client();

    // Геттеры
    int getClientId() const override;
    const char* getName() const override;
    const char* getPhoneNumber() const override;

    // Методы для работы с аккаунтом и картой
    void setBankAccount(BankAccount* account);
    void setCreditCard(CreditCard* card);
    BankAccount* getBankAccount();
    CreditCard* getCreditCard();

    // Методы платежей
    bool payOrder(double amount) override;
    bool transferTo(BankAccount& target, double amount) override;
    void closeAccount() override;
    void blockCard() override;

    // Методы для работы с заказами
    void addOrder(Order* order);
    const std::vector<Order*>& getOrders() const;
};

#endif