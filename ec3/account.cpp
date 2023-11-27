#include "account.h"
#include <iostream>
#include <string>
#include <random>


Account::Account(std::string accountNum, std::string accountOwner, double balance)
{
    this->balance = double(balance);
    this->accountOwner = std::string(accountOwner);
    this->accountNum = std::string(accountNum);
}

Account::Account(const Account& orig)
{
    this->accountNum = std::string(orig.accountNum);
    this->balance = double(orig.balance);
    this->accountOwner = std::string(orig.accountOwner);
}


void Account::deposit(const double& money)
{
    (this->balance) += money;

}
double Account::getBalance() const
{
    return this-> balance;
}

void Account::withdraw(const double& money)
{
    //Withdraw money from account
    if (money > this->balance)
    {
        std::cout << "Insufficient funds" << std::endl;
    }
    else
    {
        (this->balance) -= money;
    }
}

void Account::display() const 
{
    //Display account details
    std::cout << "Account Holder: " << this->accountOwner << std::endl;
    std::cout << "Account Number: " << this->accountNum << std::endl;
    std::cout << "Balance: " << this->balance << std::endl;
}



std::ostream& operator<<(std::ostream& os, const Account& account) 
{
    account.display();
    return os;
}