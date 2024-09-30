
#include "../include/Loan.hpp"
#include <iostream>

int Loan::idCounter = 1;  // Initialize static ID counter

Loan::Loan(const std::string& type, double amount, double interestRate, int term)
    : id(idCounter++), loanType(type), principalAmount(amount), interestRate(interestRate), loanTerm(term), status("Pending") {}

Loan::Loan(int id, const std::string& type, double amount, double interestRate, int term, const std::string& status)
    : id(id), loanType(type), principalAmount(amount), interestRate(interestRate), loanTerm(term), status(status) {}

int Loan::getId() const {
    return id;
}

std::string Loan::getLoanType() const {
    return loanType;
}

double Loan::getPrincipalAmount() const {
    return principalAmount;
}

std::string Loan::getStatus() const {
    return status;
}

void Loan::approve() {
    status = "Approved";
    std::cout << "Loan " << id << " approved." << std::endl;
}

void Loan::reject() {
    status = "Rejected";
    std::cout << "Loan " << id << " rejected." << std::endl;
}

// Serialization: Save loan information to a file
std::ostream& operator<<(std::ostream& os, const Loan& loan) {
    os << loan.id << "," << loan.loanType << "," << loan.principalAmount << "," << loan.interestRate << "," << loan.loanTerm << "," << loan.status;
    return os;
}

// Deserialization: Load loan information from a file
std::istream& operator>>(std::istream& is, Loan& loan) {
    std::string idStr, principalAmountStr, interestRateStr, loanTermStr;
    if (std::getline(is, idStr, ',')) {
        loan.id = std::stoi(idStr);
        std::getline(is, loan.loanType, ',');
        std::getline(is, principalAmountStr, ',');
        loan.principalAmount = std::stod(principalAmountStr);
        std::getline(is, interestRateStr, ',');
        loan.interestRate = std::stod(interestRateStr);
        std::getline(is, loanTermStr, ',');
        loan.loanTerm = std::stoi(loanTermStr);
        std::getline(is, loan.status, ',');
    }
    return is;
}
