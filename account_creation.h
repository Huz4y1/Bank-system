#ifndef ACCOUNT_CREATION_H
#define ACCOUNT_CREATION_H

#include <string>
#include <iostream>

class Create_User
{
public:
    std::string name;
    float balance = 0;

    void Deposit(float amount);
    void Withdraw(float amount);
    void View_balance();
};

#endif
