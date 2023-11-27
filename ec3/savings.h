#ifndef SAVINGS_H
#define SAVINGS_H

#include "account.h"
#define MIN_BALANCE 100
class Savings : public Account {
private: 
    double interestRate;
public:
    Savings(std::string accountNum, std::string accountOwner, double balance, double interestRate);
    void withdraw(const double& amount) override;
    void display() const override;
    friend Savings operator+(Savings& lhs, Account& rhs);
};


#endif // SAVINGSACCOUNT_H