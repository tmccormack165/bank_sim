#include <iostream>
#include "Account.h"

using namespace std;


int main(){
    Account a;

    a.Deposit(50);
    a.Withdraw(5);

    Account b;
    
    // send 30 dollars from a to b
    b = a.Wire(b, 30);


    cout << "B Balance: " << b.getBalance() << endl;
    return 0;
}