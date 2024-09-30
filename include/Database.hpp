
#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "User.hpp"
#include "Loan.hpp"
#include <vector>
#include <unordered_map>
#include <string>

class Database {
private:
    std::vector<User> users;
    std::unordered_map<int, std::vector<Loan>> userLoans;  // User ID to Loan list

public:
    void addUser(const User& user);
    bool userExists(int userId) const;
    void applyForLoan(int userId, const Loan& loan);
    void displayAccounts() const;
    void displayLoanApplications() const;
    void approveLoan(int loanId);
    void rejectLoan(int loanId);

    // Methods for persistent storage
    void saveAccountsToFile(const std::string& filename) const;
    void loadAccountsFromFile(const std::string& filename);
    void saveLoansToFile(const std::string& filename) const;
    void loadLoansFromFile(const std::string& filename);
};

#endif
