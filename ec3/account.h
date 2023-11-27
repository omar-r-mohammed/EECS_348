#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>


class Account{

protected:
    std::string accountNum;
    double balance;
    std::string accountOwner;
public:
    Account(std::string accountNum, std::string accountOwner, double balance);
    Account();
    Account(const Account& orig);
    void deposit(const double& amount);
    virtual void withdraw(const double& amount);
    double getBalance() const;
    virtual void display() const;
    friend std::ostream& operator<<(std::ostream& os, const Account& account);

};



#endif 