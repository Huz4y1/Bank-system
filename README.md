# C++ Bank Management System

A simple command-line banking system built in C++ that demonstrates core programming concepts such as Object-Oriented Programming, file handling, and modular code design.

---

## Features

- Create a bank account using a username
- Load existing account data automatically
- Deposit funds
- Withdraw funds
- View current balance
- Delete account data
- Persistent storage using files
- Transaction logging system

---

## Concepts Used

### Object-Oriented Programming (OOP)
- Classes and objects (`Create_User`)
- Encapsulation (private balance, public methods)
- Member functions:
  - `Deposit()`
  - `Withdraw()`
  - `View_balance()`

---

### Control Flow
- `switch-case` menu system for user interaction
- `while` loop for continuous program execution
- `if-else` logic for account checking

---

### File Handling (`fstream`)
- `std::ofstream` → writing data to files
- `std::ifstream` → reading existing account data
- Persistent storage of:
  - Account name
  - Balance
  - Transaction logs
- Appending logs using `std::ios::app`

---

### Modularisation
- Code split into multiple files:
  - `main.cpp` → program logic & user interface
  - `account_creation.h` → class declaration
  - `account_creation.cpp` → class implementation

---

### Filesystem Usage
- `std::filesystem` used to:
  - Create account directory
  - Store each user in separate file
  - Delete account files

---


---

## How It Works

1. User enters account name
2. Program checks if account file exists:
   - ✔ If yes → loads balance
   - ❌ If no → creates new account
3. User interacts via menu system:
   - Deposit money
   - Withdraw money
   - View balance
   - Exit or delete account
4. All transactions are saved to a file

---


