#include "Account.h"
#include <iostream>
using namespace std;

Account::Account() 
{
    balance = 0;
}

/* Deposit money into an account
Args:
    - amount (int): the amount of money to deposit
Return:
    - status (bool): true if the deposit was successful
*/
bool Account::Deposit(int amount){
    bool status = false;
    if(amount <= 0){
        return status;
    }
    else{
        this->balance += amount;
        status = true;
    }

    return status;
}

/* Withdraw money from an account
Args:
    - amount (int): the amount of money to deposit
Return:
    - status (bool): true if the withdraw conditions are met
*/
bool Account::Withdraw(int amount){
    bool status = false;
    int new_balance;
    new_balance = balance - amount;
    cout << "NEW BALANCE: " << new_balance << endl;
    if(amount <= 0){
        // you cannot withdraw a negative or zero amount
        return status;
    }
    else if(new_balance < 0){
        // insufficient funds
        return status;
    }
    else{
        
        // the withdraw amount is not zero and there is enough money in the account
        balance -= amount;
        status = true;
    }

    return status;
    
}

/* Send money from one account to another account
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
