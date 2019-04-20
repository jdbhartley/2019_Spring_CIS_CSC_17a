/* 
 * Author: James Hartley
 * Created on April 17, 2019, 1:24 PM
 * Description: Calculate paycheck and output formatted.
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const string THOU[] = { "","One Thousand ","Two Thousand ","Three Thousand " };
const string HUND[] = { "","One Hundred ","Two Hundred ","Three Hundred ","Four Hundred ",
                        "Five Hundred ","Six Hundred ","Seven Hundred ","Eight Hundred ","Nine Hundred " };
const string TENS[] = { "","Tenty ","Twenty ","Thirty ","Fourty ","Fifty ","Sixty ","Seventy ","Eighty ","Ninety " };
const string TEEN[] = { "Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", 
                        "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen " };
const string ONES[] = { "","One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine " };


struct employee {
    string name;
    float payRate, hours, totPay = 0;
};

//Prototypes
void DispCheck(employee);
string EnglishNumber(float);

int main(int argc, char** argv) {  
    //Get # of employee's to input
    int totEmps = 0;
    cout << "Enter number of employee's to print checks for" << endl;
    cin >> totEmps;
    
    //Customer struct
    employee* emps = new employee[totEmps];
    
    for (int i = 0; i < totEmps; i++) {
        //Get Employee name
        cout << "Employee Name: " << endl;
        cin.ignore();
        getline(cin, emps[i].name);
        
        //Get Employee hours
        cout << "Hours Worked: " << endl;
        cin >> emps[i].hours;
        
        //Get payrate
        cout << "Employee Payrate: " << endl;
        cin >> emps[i].payRate;
        
        //Calculate total pay
        if (emps[i].hours <= 40) {
            emps[i].totPay += emps[i].hours * emps[i].payRate;
        }
        else if (emps[i].hours > 40 && emps[i].hours < 50) {
            emps[i].totPay += 40 * emps[i].payRate;
            emps[i].totPay += (emps[i].hours-40) * (emps[i].payRate * 2);
        }
        else if (emps[i].hours > 50) {
            emps[i].totPay += 40 * emps[i].payRate;
            emps[i].totPay += 10 * (emps[i].payRate * 2);
            emps[i].totPay += (emps[i].hours-50) * (emps[i].payRate * 3);
        }
        
        //Display check
        DispCheck(emps[i]);
    }
    delete[] emps;
    return 0;
}

string EnglishNumber(float num) {
    string output;
    int number = num;
    int cents = (num*100);
    cents = cents%100;
    if ((number%100)/10 == 1) { //Check if we need a teen.
            output = THOU[number/1000] + HUND[(number%1000)/100] + TEEN[(number%10)];
        }
        else {
            output = THOU[number/1000] + HUND[(number%1000)/100] + TENS[(number%100)/10] + ONES[(number%10)];
        }
        output += "and " + to_string(cents) + "/100's Dollars";
    return output;
}

void DispCheck(employee emp) {
    cout << endl;
    cout << "ACME Production Co." << endl;
    cout << "Address: " << "123 Fake St." << endl;
    cout << "Name: " << "   " << emp.name << "       Amount: $" << fixed << setprecision(2) << emp.totPay << endl;
    cout << "Amount:  " << EnglishNumber(emp.totPay) << endl << endl;
    cout << "Signature Line: " << "____________________" << endl;
}

