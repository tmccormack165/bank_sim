#include <iostream>
#include "Account.h"

using namespace std;


int main(){
    Account a;

    // Deposit 50 dollars
    a.Deposit(50);

    // Withdraw 5 dollars
    a.Withdraw(5);

    // view report
    // report contains current balance and a history of transactions
    a.Report();

    /*
    Account b;

    // send 30 dollars from a to b
    a.Wire(b, 30);

    cout << "B Balance: " << b.getBalance() << endl;
    */
    return 0;
}