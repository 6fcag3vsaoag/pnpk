#include "Order.h"

Order::Order(int id, double amt, const std::string& desc)
    : orderId(id), amount(amt), description(desc) {
}

int Order::getOrderId() const {
    return orderId;
}

double Order::getAmount() const {
    return amount;
}

const char* Order::getDescription() const {
    return description.c_str();
}