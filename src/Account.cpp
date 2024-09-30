
#include "../include/Account.hpp"
#include <iostream>

Account::Account(const std::string& type) : accountType(type), balance(0.0) {}

void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        std::cout << "Deposited $" << amount << " to " << accountType << " account." << std::endl;
    }
}

void Account::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
        std::cout << "Withdrew $" << amount << " from " << accountType << " account." << std::endl;
    } else {
        std::cout << "Insufficient balance!" << std::endl;
    }
}

double Account::getBalance() const {
    return balance;
}

std::string Account::getType() const {
    return accountType;
}
