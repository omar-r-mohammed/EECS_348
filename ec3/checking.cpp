#include "checking.h"
#include <iostream>
#include <string>
#include <iomanip>

Checking::Checking(std::string accountNum, std::string accountOwner, double balance, double maxOverdraft) : Account(accountNum, accountOwner, balance) {
    this->maxOverdraft = double(-maxOverdraft);
}


void Checking::withdraw(const double& amount) {
    if (this->getBalance() - amount < this->maxOverdraft) {
        std::cout << "Cannot withdraw $" << amount << " from account " << std::endl;
        std::cout << "Maximum Overdraft of $" << maxOverdraft<< std::endl;
    } else {
        Account::withdraw(amount);
    }
}

void Checking::display() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Account details for Savings Account (ID: " << this->accountNum << ")" << std::endl;
    std::cout << "Account Owner: " << this->accountOwner << std::endl;
    std::cout << "Account Balance: $" << this->getBalance() << std::endl;
    std::cout << "Maximum Overdraft: $" << -this->maxOverdraft << std::endl;
}

Checking operator+(Checking& lhs, Account& rhs) {
    //Overload the + operator to add two accounts together
    rhs.withdraw(300);
    lhs.deposit(300);
    return lhs;
}