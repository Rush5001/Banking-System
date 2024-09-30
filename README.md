How to run:
1. Using the Command Line with g++
This method uses the g++ compiler and is suitable for environments like MinGW on Windows or GCC on Linux/Mac.

Open Command Prompt or Terminal:

For Windows: Open the Command Prompt or PowerShell.
For Linux/Mac: Open the Terminal.
Navigate to the Project Directory:

Use the cd command to navigate to the root directory of your project where your src folder is located:
bash
Copy code
cd path\to\BankingSystem\src
Compile the Program:

Use the following command to compile the program using g++:

bash
Copy code
g++ -std=c++17 -o BankingSystem.exe main.cpp User.cpp Account.cpp Loan.cpp Notification.cpp Database.cpp Server.cpp Client.cpp -I ../include -lws2_32
Explanation:
-std=c++17: Use the C++17 standard.
-o BankingSystem.exe: Specifies the name of the output executable.
main.cpp, User.cpp, etc.: Lists all source files to be compiled.
-I ../include: Specifies the include directory for header files.
-lws2_32: Links the Winsock2 library (necessary for networking on Windows).
If you are using a different compiler or are on Linux/Mac, you might need to remove the -lws2_32 option and adjust paths as necessary.

Run the Program:

After compiling, run the executable with:
bash
Copy code
.\BankingSystem.exe  # For Windows
./BankingSystem      # For Linux/Mac
This will start the program, and you should see the initial menu asking if you are a Customer or an Assistant.
