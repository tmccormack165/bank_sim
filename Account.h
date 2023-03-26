#pragma once // message for the compiler to include Account.h only once
#include <vector> // used for storing transactions
#include <string> // used for communicating with the end user
#include "Transaction.h"

class Account{
    // can only be accessed by public functions within the class
    private:
        int balance;
        vector <Transaction> transaction_log;

    // can be called in other files
    public:
        Account(); // declare constructor

        // return bool to indicate status of operation
        bool Deposit(int amount);
        bool Withdraw(int amount);
        bool Wire(Account &transfer_acct, int amount);
        void Report();

        int getBalance(){return balance;} // inline

        // close, invest, register user


}; // classes will always end with semicolons