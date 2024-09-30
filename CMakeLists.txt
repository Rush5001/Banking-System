
cmake_minimum_required(VERSION 3.10)
project(BankingSystem)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(include)

# Add source files for compilation
add_executable(BankingSystem
    src/main.cpp
    src/User.cpp
    src/Account.cpp
    src/Loan.cpp
    src/Notification.cpp
    src/Database.cpp
    src/Server.cpp
    src/Client.cpp
)

# Link against Winsock library on Windows
if(WIN32)
    target_link_libraries(BankingSystem Ws2_32)
endif()
