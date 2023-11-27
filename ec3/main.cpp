#include <iostream>
#include <string>
#include "savings.h"
#include "checking.h"

int main(){
    Savings saving("S123", "John Doe", 1000, 0.02);
    Checking current("C456", "Jane Doe", 2000, 500);


    std::cout << saving << current << std::endl << std::endl;

    saving.deposit(500);
    current.withdraw(1000);
    
    std::cout << "Account details after transactions: " << std::endl;
    std::cout << saving << current << std::endl << std::endl;

    // Transfer 300 from savings to current
    current = current + saving;

    std::cout << "Account details after transfer: " << std::endl;
    std::cout << saving << current << std::endl << std::endl;

    return 0;



}