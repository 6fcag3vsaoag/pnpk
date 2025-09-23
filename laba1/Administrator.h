#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "CreditCard.h"

class Administrator {
private:
    int adminId;
    std::string name;

public:
    Administrator(int id, const std::string& adminName);
    ~Administrator() = default;

    // Геттеры
    int getAdminId() const;
    std::string getName() const;

    // Операции
    void BlockCardForOverlimit(CreditCard* card);
};

#endif // ADMINISTRATOR_H