#ifndef IORDER_H
#define IORDER_H

class IOrder {
public:
    virtual int getOrderId() const = 0;
    virtual double getAmount() const = 0;
    virtual const char* getDescription() const = 0;
    virtual ~IOrder() = default;
};

#endif