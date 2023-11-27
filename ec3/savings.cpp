#include "savings.h"
#include <iostream>
#include <string>
#include <iomanip>


Savings::Savings(std::string accountNum, std::string accountOwner, double balance, double interestRate) : Account(accountNum, accountOwner, balance) {
    this->interestRate = double(interestRate);
}


void Savings::withdraw(const double& amount) {
    if (this->getBalance() - amount < MIN_BALANCE) {
        std::cout << "Cannot withdraw $" << amount << " from account " << std::endl;
        std::cout << "Minimum balance of $" << MIN_BALANCE << " must be maintained" << std::endl;
    } else {
        Account::withdraw(amount);
    }
}

void Savings::display() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Account details for Savings Account (ID: " << this->accountNum << ")" << std::endl;
    std::cout << "Account Holder: " << this->accountOwner << std::endl;
    std::cout << "Account Balance: $" << this->getBalance() << std::endl;
    std::cout << "Interest Rate: " << this->interestRate*100 << "%" << std::endl;
}

Savings operator+(Savings& lhs, Account& rhs) {
    //Overload the + operator to add two accounts together
    rhs.withdraw(300);
    lhs.deposit(300);
    return lhs;
}