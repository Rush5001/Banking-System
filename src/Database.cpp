
#include "../include/Database.hpp"
#include <fstream>
#include <iostream>
#include <sstream> 


void Database::addUser(const User& user) {
    users.push_back(user);
    userLoans[user.getId()] = std::vector<Loan>();
}

bool Database::userExists(int userId) const {
    for (const auto& user : users) {
        if (user.getId() == userId) {
            return true;
        }
    }
    return false;
}

void Database::applyForLoan(int userId, const Loan& loan) {
    if (userLoans.find(userId) != userLoans.end()) {
        userLoans[userId].push_back(loan);
    }
}

void Database::displayAccounts() const {
    std::cout << "--- List of Accounts ---";
    for (const auto& user : users) {
        std::cout << "User ID: " << user.getId() << ", Name: " << user.getName() << ", Email: " << user.getEmail() << std::endl;
    }
}

void Database::displayLoanApplications() const {
    std::cout << "--- Loan Applications ---";
    for (const auto& entry : userLoans) {
        int userId = entry.first;
        for (const auto& loan : entry.second) {
            if (loan.getStatus() == "Pending") {
                std::cout << "Loan ID: " << loan.getId() << ", User ID: " << userId << ", Loan Type: " << loan.getLoanType()
                          << ", Amount: $" << loan.getPrincipalAmount() << ", Status: " << loan.getStatus() << std::endl;
            }
        }
    }
}

void Database::approveLoan(int loanId) {
    for (auto& entry : userLoans) {
        for (auto& loan : entry.second) {
            if (loan.getId() == loanId) {
                loan.approve();
                return;
            }
        }
    }
}

void Database::rejectLoan(int loanId) {
    for (auto& entry : userLoans) {
        for (auto& loan : entry.second) {
            if (loan.getId() == loanId) {
                loan.reject();
                return;
            }
        }
    }
}

// Persistent storage methods

void Database::saveAccountsToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error opening file for saving accounts." << std::endl;
        return;
    }
    for (const auto& user : users) {
        file << user.getId() << "," << user.getName() << "," << user.getEmail() << "," << user.getPassword() << std::endl;
    }
    file.close();
}

void Database::loadAccountsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file for loading accounts." << std::endl;
        return;
    }
    users.clear();
    userLoans.clear();
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string idStr, name, email, password;
        std::getline(ss, idStr, ',');
        std::getline(ss, name, ',');
        std::getline(ss, email, ',');
        std::getline(ss, password, ',');
        int id = std::stoi(idStr);
        User user(name, email, password);
        users.push_back(user);
        userLoans[user.getId()] = std::vector<Loan>();
    }
    file.close();
}

void Database::saveLoansToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error opening file for saving loans." << std::endl;
        return;
    }
    for (const auto& entry : userLoans) {
        int userId = entry.first;
        for (const auto& loan : entry.second) {
            file << loan.getId() << "," << userId << "," << loan.getLoanType() << "," << loan.getPrincipalAmount() << ","
                 << loan.getStatus() << std::endl;
        }
    }
    file.close();
}

void Database::loadLoansFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file for loading loans." << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string idStr, userIdStr, loanType, amountStr, status;
        std::getline(ss, idStr, ',');
        std::getline(ss, userIdStr, ',');
        std::getline(ss, loanType, ',');
        std::getline(ss, amountStr, ',');
        std::getline(ss, status, ',');
        int id = std::stoi(idStr);
        int userId = std::stoi(userIdStr);
        double amount = std::stod(amountStr);
        Loan loan(loanType, amount, 5.0, 12);  // Example interest rate and term
        loan.approve();  // For simplicity, set loan as approved
        userLoans[userId].push_back(loan);
    }
    file.close();
}
