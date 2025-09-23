#include "Administrator.h"
#include <iostream>

Administrator::Administrator(int id, const std::string& adminName)
    : adminId(id), name(adminName) {}

int Administrator::getAdminId() const { return adminId; }
std::string Administrator::getName() const { return name; }

void Administrator::BlockCardForOverlimit(CreditCard* card) {
    if (!card) {
        std::cout << "Error: Invalid card pointer.\n";
        return;
    }
    if (card->getCurrentDebt() > card->getCreditLimit()) {
        std::cout << "[Admin " << name << "] Blocking card due to overlimit.\n";
        card->BlockCard();
    } else {
        std::cout << "[Admin " << name << "] Card is within limit. No action required.\n";
    }
}