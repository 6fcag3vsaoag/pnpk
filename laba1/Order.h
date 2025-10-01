#ifndef ORDER_H
#define ORDER_H

#include "IOrder.h"
#include <string>

class Order : public IOrder {
private:
    int orderId;
    double amount;
    std::string description;

public:
    Order(int id, double amount, const std::string& description);

    // Геттеры
    int getOrderId() const override;
    double getAmount() const override;
    const char* getDescription() const override;
};

#endif