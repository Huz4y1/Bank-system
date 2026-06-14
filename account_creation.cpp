#include "account_creation.h"

void Create_User::Deposit(float amount)
{
    balance += amount;
}

void Create_User::Withdraw(float amount)
{
    balance -= amount;
}

void Create_User::View_balance()
{
    std::cout << "\nCurrent balance: £" << balance << std::endl;
}
