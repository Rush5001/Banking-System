#include "../include/User.hpp"
#include "../include/Database.hpp"
#include "../include/Loan.hpp"
#include <iostream>
#include <string>

// Global database instance
Database db;

// Function prototypes
void mainMenu();
void customerMenu();
void assistantMenu();
bool authenticateAssistant();
void loadData();
void saveData();

int main() {
    // Load existing data from file
    loadData();

    mainMenu();

    // Save data to file before exiting
    saveData();

    return 0;
}

void mainMenu() {
    int choice;

    do {
        std::cout << "\n--- Main Menu ---\n";
        std::cout << "1. Customer\n";
        std::cout << "2. Assistant\n";
        std::cout << "3. Exit\n";
        std::cout << "Select an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                customerMenu();
                break;
            case 2:
                if (authenticateAssistant()) {
                    assistantMenu();
                } else {
                    std::cerr << "Authentication failed." << std::endl;
                }
                break;
            case 3:
                std::cout << "Exiting the program." << std::endl;
                break;
            default:
                std::cerr << "Invalid option. Please try again." << std::endl;
        }
    } while (choice != 3);
}

void customerMenu() {
    std::string name, email, password;
    int option;

    do {
        std::cout << "\n--- Customer Menu ---\n";
        std::cout << "1. Create Account\n";
        std::cout << "2. Apply for Loan\n";
        std::cout << "3. Return to Main Menu\n";
        std::cout << "Select an option: ";
        std::cin >> option;

        if (option == 1) {
            std::cout << "Enter your name: ";
            std::cin.ignore();  // Ignore leftover newline character
            std::getline(std::cin, name);
            std::cout << "Enter your email: ";
            std::getline(std::cin, email);
            std::cout << "Enter your password: ";
            std::getline(std::cin, password);

            User newUser(name, email, password);
            db.addUser(newUser);
            std::cout << "Account created successfully!" << std::endl;
        } else if (option == 2) {
            int userId;
            double loanAmount;
            std::string loanType;

            std::cout << "Enter your User ID: ";
            std::cin >> userId;

            if (db.userExists(userId)) {
                std::cout << "Enter loan amount: ";
                std::cin >> loanAmount;
                std::cout << "Enter loan type (e.g., Personal, Mortgage): ";
                std::cin.ignore();
                std::getline(std::cin, loanType);

                Loan newLoan(loanType, loanAmount, 5.0, 12);  // Example interest rate and term
                db.applyForLoan(userId, newLoan);
                std::cout << "Loan application submitted. Awaiting approval." << std::endl;
            } else {
                std::cerr << "User ID not found. Please create an account first." << std::endl;
            }
        } else if (option != 3) {
            std::cerr << "Invalid option. Please try again." << std::endl;
        }
    } while (option != 3);
}

void assistantMenu() {
    int option;

    do {
        std::cout << "\n--- Assistant Menu ---\n";
        std::cout << "1. View Accounts\n";
        std::cout << "2. View Loan Applications\n";
        std::cout << "3. Approve/Reject Loans\n";
        std::cout << "4. Return to Main Menu\n";
        std::cout << "Select an option: ";
        std::cin >> option;

        if (option == 1) {
            db.displayAccounts();
        } else if (option == 2) {
            db.displayLoanApplications();
        } else if (option == 3) {
            int loanId;
            std::string decision;

            std::cout << "Enter Loan ID to approve/reject: ";
            std::cin >> loanId;
            std::cout << "Type 'approve' or 'reject': ";
            std::cin >> decision;

            if (decision == "approve") {
                db.approveLoan(loanId);
                std::cout << "Loan approved successfully!" << std::endl;
            } else if (decision == "reject") {
                db.rejectLoan(loanId);
                std::cout << "Loan rejected successfully!" << std::endl;
            } else {
                std::cerr << "Invalid decision. Returning to menu." << std::endl;
            }
        } else if (option != 4) {
            std::cerr << "Invalid option. Please try again." << std::endl;
        }
    } while (option != 4);
}

bool authenticateAssistant() {
    std::string password;
    const std::string assistantPassword = "admin123";  // Example password

    std::cout << "Enter assistant password: ";
    std::cin >> password;

    return password == assistantPassword;   
}

void loadData() {
    db.loadAccountsFromFile("accounts.txt");
    db.loadLoansFromFile("loans.txt");
}

void saveData() {
    db.saveAccountsToFile("accounts.txt");
    db.saveLoansToFile("loans.txt");
}
