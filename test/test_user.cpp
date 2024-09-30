
#include "../include/User.hpp"
#include "../include/Database.hpp"
#include <cassert>
#include <iostream>

void testUserCreation() {
    Database db;
    User user("Jane Doe", "jane.doe@example.com", "password123");
    assert(user.getName() == "Jane Doe");
    std::cout << "User creation test passed." << std::endl;
}

int main() {
    testUserCreation();
    return 0;
}
