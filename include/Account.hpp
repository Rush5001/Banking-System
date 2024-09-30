
#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>

class Account {
private:
    std::string accountType;
    double balance;

public:
    Account(const std::string& type);
    void deposit(double amount);
    void withdraw(double amount);
    double getBalance() const;
    std::string getType() const;
};

#endif
