/* 
 * Author: James Hartley
 * Created on April 17, 2019, 1:24 PM
 * Description: Develop an application using structures for a customer
 * that will determine if he/she has exceeded his/her checking 
 * account balance.
 */

#include <iostream>
#include <string>

using namespace std;



struct customer {
    string name, address, number;
    int totChks, totDeps;
    float balance;
    bool overdr = false;
};

//Prototypes
void DispCustomer(customer);

int main(int argc, char** argv) {  
    //Customer struct
    customer cust;
    
        //Get Customer name
        cout << "Customer Name: " << endl;
        getline(cin, cust.name);
        
        //Get Customer address
        cout << "Customer Address: " << endl;
        getline(cin, cust.address);

        //Get account number, needs to be 5 digits.
        cout << "Enter account number for " << cust.name << ": " << endl;
        do {
            cout << "Must be 5 digits long" << endl;
            cin >> cust.number;
        } while (cust.number.length() != 5);
        
        //Get Balance at the beginning of the month
        cout << "Enter beginning balance for the month: " << endl;
        cin >> cust.balance;
        
        //Get checks writted
        cout << "How many checks were written this month?" << endl;
        cin >> cust.totChks;
        
        for (int i = 0; i < cust.totChks; i++) {
            float debit;
            cout << "Enter amount for check #" << i+1 << endl;
            cin >> debit;
            cust.balance -= debit;
        }
        
        cout << "How many deposits were credited this month?" << endl;
        cin >> cust.totDeps;
        
        for (int i = 0; i < cust.totDeps; i++) {
            float deposit;
            cout << "Enter amount for deposit #" << i+1 << endl;
            cin >> deposit;
            cust.balance += deposit;
        }
        
        //Check for overdraft
        if (cust.balance < 0) {
            cust.balance -= 20;
            cust.overdr = true;
        }
        
        //Display customer
        DispCustomer(cust);
        
    return 0;
}

void DispCustomer(customer cust) {
    cout << endl;
    cout << "Name: " << "             "  << cust.name << endl;
    cout << "Address: " << "          " << cust.address << endl;
    cout << "Acc Number: " << "       " << cust.number << endl;
    cout << "Balance: " << "          " << "$" << cust.balance << endl;
    cout << "Checks Debited: " << "   " << cust.totChks << endl;
    cout << "Deposits Credited: " << cust.totDeps << endl;
    
    if (cust.overdr) {
        cout << "Overdraft fee of $20 applied" << endl;
    }
}

