#include "Account.h"
#include <iostream>
using namespace std;

Account::Account() 
{
    balance = 0;
}

/* 
Deposit money into an account
Args:
    - amount (int): the amount of money to deposit
Return:
    - status (bool): true if the deposit was successful
*/
bool Account::Deposit(int amount){
    bool status = false;
    string type = "Deposit";
    int previous_balance = this->balance;

    if(amount > 0){
        this->balance += amount;
        status = true;
    }

    // record deposit status, amount
    Transaction t(amount, previous_balance, this->balance, type, status);
    this->transaction_log.push_back(t);

    return status;
}

/* 
Withdraw money from an account
Args:
    - amount (int): the amount of money to deposit
Return:
    - status (bool): true if the withdraw conditions are met
*/
bool Account::Withdraw(int amount){
    bool status = false;
    int new_balance;
    int previous_balance = this->balance;
    string type = "Withdrawl";
    new_balance = balance - amount;

    

    if(amount > 0 && new_balance > 0){
        // the withdraw amount is not zero and there is enough money in the account
        balance -= amount;
        status = true;
    }

    // save transaction data
    Transaction t(amount, previous_balance, this->balance, type, status);
    this->transaction_log.push_back(t);

    return status;
    
}


/* 
Send money from one account to another account
Args:
    - transfer_acct (Account)
    - amount (int)
Return:
    - wire_status (bool)
*/
bool Account::Wire(Account &transfer_acct, int amount){
    bool wire_status;
    //wire_status = transfer_acct.Deposit(amount);

    // attempt to withdraw amount from sending account
    wire_status = this -> Withdraw(amount);

    if(wire_status == true){
        // attempt deposit amount into transfer account
        wire_status = transfer_acct.Deposit(amount);
    }
    //cout << "transfer_acct.balance: " << transfer_acct.getBalance() << endl;

    return wire_status;
}


void Account::Report(){
    //printf("CURRENT BALLANCE: ")
    cout << "Current Balance: " << this->balance << endl;
    for(auto item:transaction_log){
        // each item is a transaction
        item.History(); // the History method will print out all of the transaction data
    }
}