#include <iostream>
#include <string>
#include "account_creation.h"
#include <fstream>
#include <filesystem>

int main()
{
    Create_User Account;   //Creating an object from the class

    std::string username;

    std::cout << "\nEnter the name of the Account holder: ";
    std::getline(std::cin, username);

    Account.name = username;   // Mapping the username from input to the name in the class

    // check that folder exists
    if (!std::filesystem::exists("accounts"))
    {
        std::filesystem::create_directory("accounts");
    }

    std::string path = "accounts/" + username + ".txt";

    std::ifstream inFile(path);
    std::ofstream file;

    if (inFile.is_open())
    {
        std::cout << "\nExisting account found! Loading data your data!\n";

        std::getline(inFile, Account.name);
        inFile >> Account.balance;

        inFile.close();
    }
    else
    {
        std::cout << "\nNo account found, creating new account, Thank you for joining us!\n";

        Account.balance = 0;

        file.open(path);
        file << Account.name << "\n";
        file << Account.balance << "\n";
        file.close();
    }

    // Open log file in append mode
    file.open(path, std::ios::app);
    file << "\nSession started\n";

    while (1)
    {
        std::cout << "\nWelcome " << Account.name << "\n";
        std::cout << "\n1. View balance\n";
        std::cout << "2. Deposit funds\n";
        std::cout << "3. Withdraw\n";
        std::cout << "4. Delete account\n";
        std::cout << "5. Exit\n";

        int choice;
        std::cout << "\nChoice: ";
        std::cin >> choice;

        switch (choice)
        {
            case 1:
                Account.View_balance();
                break;

            case 2:
            {
                float amount;
                std::cout << "Enter deposit amount: ";
                std::cin >> amount;

                Account.Deposit(amount);

                file << "Deposited: £" << amount << "\n";
                file << "Balance: £" << Account.balance << "\n";
                break;
            }

            case 3:
            {
                float amount;
                std::cout << "Enter withdrawal amount: ";
                std::cin >> amount;

                Account.Withdraw(amount);

                file << "Withdrawn: £" << amount << "\n";
                file << "Balance: £" << Account.balance << "\n";
                break;
            }

            case 4:
            {
                file.close();

                std::filesystem::remove(path);

                std::cout << "\nAccount deleted successfully!\n";
                return 0;
            }

            case 5:
                file << "Session ended\n";
                file.close();

                std::cout << "\nGoodbye!\n";
                return 0;

            default:
                std::cout << "\nInvalid choice\n";
                break;
        }
    }
}
