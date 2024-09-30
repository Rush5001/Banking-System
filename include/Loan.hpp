
#ifndef LOAN_HPP
#define LOAN_HPP

#include <string>
#include <iostream>

class Loan {
private:
    int id;
    std::string loanType;
    double principalAmount;
    double interestRate;
    int loanTerm;  // In months
    std::string status;  // Status: "Pending", "Approved", "Rejected"
    static int idCounter;  // Static variable to keep track of loan IDs

public:
    Loan(const std::string& type, double amount, double interestRate, int term);
    Loan(int id, const std::string& type, double amount, double interestRate, int term, const std::string& status);

    int getId() const;
    std::string getLoanType() const;
    double getPrincipalAmount() const;
    std::string getStatus() const;
    void approve();
    void reject();

    // Serialization and Deserialization
    friend std::ostream& operator<<(std::ostream& os, const Loan& loan);
    friend std::istream& operator>>(std::istream& is, Loan& loan);
};

#endif
