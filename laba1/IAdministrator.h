#ifndef IADMINISTRATOR_H
#define IADMINISTRATOR_H

class CreditCard;

class IAdministrator {
public:
    virtual int getAdminId() const = 0;
    virtual const char* getName() const = 0;
    virtual void BlockCardForOverlimit(CreditCard& card) = 0;
    virtual ~IAdministrator() = default;
};

#endif