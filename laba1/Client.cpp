#include "Client.h"
#include <iostream>

Client::Client(int id, const std::string& clientName, const std::string& phone)
    : clientId(id), name(clientName), phoneNumber(phone), account(nullptr), card(nullptr) {}

Client::~Client() {
    // Не удаляем account и card, так как они могут управляться внешней логикой
    // (например, администратором или системой). Это предотвращает двойное удаление.
}

int Client::getClientId() const { return clientId; }
std::string Client::getName() const { return name; }
std::string Client::getPhoneNumber() const { return phoneNumber; }

void Client::setBankAccount(BankAccount* acc) { account = acc; }
void Client::setCreditCard(CreditCard* cc) { card = cc; }

BankAccount* Client::getBankAccount() const { return account; }
CreditCard* Client::getCreditCard() const { return card; }

bool Client::payOrder(double amount) {
    if (!account) {
        std::cout << "Error: No bank account linked to client.\n";
        return false;
    }
    return account->PayOrder(amount);
}

bool Client::transferTo(BankAccount* target, double amount) {
    if (!account) {
        std::cout << "Error: No bank account linked to client.\n";
        return false;
    }
    return account->TransferTo(target, amount);
}

void Client::closeAccount() {
    if (account) {
        account->CloseAccount();
        // account = nullptr; // Опционально: снять ссылку после закрытия
    } else {
        std::cout << "No account to close.\n";
    }
}

void Client::blockCard() {
    if (card) {
        card->BlockCard();
    } else {
        std::cout << "No card to block.\n";
    }
}