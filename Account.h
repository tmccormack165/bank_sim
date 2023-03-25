#include <vector> // used for storing transactions
#include <string> // used for communicating with the end user

class Account{
    // can only be accessed by public functions within the class
    private:
        int balance;

    // can be called in other files
    public:
        Account(); // declare constructor

        // return bool to indicate status of operation
        bool Deposit(int amount);
        bool Withdraw(int amount);
        Account Wire(Account transfer_acct, int amount);

        int getBalance(){return balance;} // inline


}; // classes will always end with semicolons