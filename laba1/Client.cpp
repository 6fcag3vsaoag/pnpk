#include "Client.h"
#include "BankAccount.h"
#include "CreditCard.h"
#include "Order.h"
#include <iostream>

Client::Client(int id, const std::string& clientName, const std::string& phone)
    : clientId(id), name(clientName), phoneNumber(phone), account(nullptr), card(nullptr) {
}

Client::~Client() {
    for (Order* order : orders) {
        delete order;
    }
}

// Геттеры
int Client::getClientId() const {
    return clientId;
}

const char* Client::getName() const {
    return name.c_str();
}

const char* Client::getPhoneNumber() const {
    return phoneNumber.c_str();
}

// Методы для работы с аккаунтом и картой
void Client::setBankAccount(BankAccount* acc) {
    account = acc;
}

void Client::setCreditCard(CreditCard* creditCard) {
    card = creditCard;
}

BankAccount* Client::getBankAccount() {
    return account;
}

CreditCard* Client::getCreditCard() {
    return card;
}

// Методы платежей
bool Client::payOrder(double amount) {
    if (!account || !card) {
        std::cout << "Клиент не имеет аккаунта или карты" << std::endl;
        return false;
    }

    if (card->isCardBlocked()) {
        std::cout << "Карта заблокирована" << std::endl;
        return false;
    }

    // Проверяем доступный кредит
    if (card->canMakePurchase(amount)) {
        // Снимаем деньги с банковского счета
        if (account->PayOrder(amount)) {
            // Добавляем долг на кредитную карту
            card->AddDebt(amount);
            std::cout << "Заказ оплачен успешно на сумму: " << amount << std::endl;
            return true;
        }
    }

    std::cout << "Недостаточно средств для оплаты заказа" << std::endl;
    return false;
}

bool Client::transferTo(BankAccount& target, double amount) {
    if (!account) {
        std::cout << "Клиент не имеет банковского аккаунта" << std::endl;
        return false;
    }

    if (account->TransferTo(target, amount)) {
        std::cout << "Перевод выполнен успешно на сумму: " << amount << std::endl;
        return true;
    }

    return false;
}

void Client::closeAccount() {
    if (account) {
        account->CloseAccount();
        std::cout << "Аккаунт закрыт" << std::endl;
    }
}

void Client::blockCard() {
    if (card) {
        card->BlockCard();
        std::cout << "Карта заблокирована клиентом" << std::endl;
    }
}

// Методы для работы с заказами
void Client::addOrder(Order* order) {
    orders.push_back(order);
}

const std::vector<Order*>& Client::getOrders() const {
    return orders;
}