#include "Transaction.h"

Transaction::Transaction(int amount, int previous_balance, int new_amount,
                         string type, bool status){
    this->type = type;
    this->amount = amount;
    this->status = status;
    this->previous_balance = previous_balance;
    this->new_balance = new_amount;
}

void Transaction::History(){
    string status_str;
    if(this->status == true){
        status_str = "Succeeded";
    }
    else{
        status_str = "Failed";
    }
    cout << "A " << this->type << " Transaction " << status_str << endl;
    cout << "$" << this->previous_balance << " --> $" << this->new_balance << endl; 
    cout << "------------------------------------------" << endl;
    // a <deposit/withdrawl> transaction <failed/succeeded> 
    // $300 --> $500
    // ------------------------------------------

    /*
    cout << "Transaction Type: " << this->type << endl;
    cout << "Transaction Status: " << status_str << endl;
    cout << ""
    */
    

}