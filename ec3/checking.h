#ifndef CHECKING_H
#define CHECKING_H

#include "account.h"
class Checking : public Account {
private: 
    double maxOverdraft;
public:
    Checking(std::string accountNum, std::string accountOwner, double balance, double interestRate);
    void withdraw(const double& amount) override;
    void display() const override;
    friend Checking operator+(Checking& lhs, Account& rhs);
};


#endif 