
#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <iostream>

class User {
private:
    int id;
    std::string name;
    std::string email;
    std::string password;
    static int idCounter;  // Static variable to keep track of user IDs

public:
    User(const std::string& name, const std::string& email, const std::string& password);
    User(int id, const std::string& name, const std::string& email, const std::string& password);

    int getId() const;
    std::string getName() const;
    std::string getEmail() const;
    std::string getPassword() const;

    // Serialization and Deserialization
    friend std::ostream& operator<<(std::ostream& os, const User& user);
    friend std::istream& operator>>(std::istream& is, User& user);
};

#endif
