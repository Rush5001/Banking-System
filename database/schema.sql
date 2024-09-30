
CREATE TABLE Users (
    id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(255) NOT NULL,
    email VARCHAR(255) UNIQUE NOT NULL,
    password VARCHAR(255) NOT NULL
);

CREATE TABLE Accounts (
    id INT PRIMARY KEY AUTO_INCREMENT,
    user_id INT,
    account_type VARCHAR(50),
    balance DOUBLE,
    FOREIGN KEY (user_id) REFERENCES Users(id)
);

CREATE TABLE Loans (
    id INT PRIMARY KEY AUTO_INCREMENT,
    user_id INT,
    loan_type VARCHAR(50),
    principal_amount DOUBLE,
    interest_rate DOUBLE,
    loan_term INT,
    remaining_balance DOUBLE,
    FOREIGN KEY (user_id) REFERENCES Users(id)
);
