#include "Administrator.h"
#include "CreditCard.h"
#include <iostream>

Administrator::Administrator(int id, const std::string& adminName)
    : adminId(id), name(adminName) {
}

int Administrator::getAdminId() const {
    return adminId;
}

const char* Administrator::getName() const {
    return name.c_str();
}

void Administrator::BlockCardForOverlimit(CreditCard& card) {
    if (card.getCurrentDebt() > card.getCreditLimit()) {
        card.BlockCard();
        std::cout << "Администратор " << name << " заблокировал карту за превышение лимита" << std::endl;
        std::cout << "Номер карты: " << card.getCardNumber() << std::endl;
        std::cout << "Текущий долг: " << card.getCurrentDebt() << std::endl;
        std::cout << "Кредитный лимит: " << card.getCreditLimit() << std::endl;
    } else {
        std::cout << "Превышение лимита не обнаружено" << std::endl;
    }
}