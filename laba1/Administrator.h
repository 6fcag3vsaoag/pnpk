#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "IAdministrator.h"
#include <string>

class CreditCard;

class Administrator : public IAdministrator {
private:
    int adminId;
    std::string name;

public:
    Administrator(int id, const std::string& name);

    // Геттеры
    int getAdminId() const override;
    const char* getName() const override;

    // Методы управления
    void BlockCardForOverlimit(CreditCard& card) override;
};

#endif