
#include "../include/User.hpp"

int User::idCounter = 1;  // Initialize static ID counter

User::User(const std::string& name, const std::string& email, const std::string& password)
    : id(idCounter++), name(name), email(email), password(password) {}

User::User(int id, const std::string& name, const std::string& email, const std::string& password)
    : id(id), name(name), email(email), password(password) {}

int User::getId() const {
    return id;
}

std::string User::getName() const {
    return name;
}

std::string User::getEmail() const {
    return email;
}

std::string User::getPassword() const {
    return password;
}

// Serialization: Save user information to a file
std::ostream& operator<<(std::ostream& os, const User& user) {
    os << user.id << "," << user.name << "," << user.email << "," << user.password;
    return os;
}

// Deserialization: Load user information from a file
std::istream& operator>>(std::istream& is, User& user) {
    std::string idStr;
    if (std::getline(is, idStr, ',')) {
        user.id = std::stoi(idStr);
        std::getline(is, user.name, ',');
        std::getline(is, user.email, ',');
        std::getline(is, user.password, ',');
    }
    return is;
}
