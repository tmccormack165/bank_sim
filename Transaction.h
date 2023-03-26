#pragma once
#include <string>
#include <iostream>
using namespace std;

class Transaction{
    private: // in general member variables should be private
        string type;
        bool status;
        int amount;
        int previous_balance;
        int new_balance;
    
    public:
        Transaction(int amount, int previous_amount, int new_amount, string type, bool status); // constructor
        void History();

};