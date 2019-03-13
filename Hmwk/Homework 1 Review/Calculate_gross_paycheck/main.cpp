/* 
 * File:    main.cpp
 * Author:  James Hartley
 * Created: January 24 10:45PM
 * Purpose: Overtime
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
const char REGHRS = 20;     //Max hours paid at regular rate.
const char OTHRS = 40;      //Max hours paid at time and a half
const char PAYDT = 2;       //Amount to multiply paycheck by after 40 hours.
const float PAYOT = 1.5;    //Amount to multiply paycheck by after 20 hours.

//Function Prototypes Here
float paycheck(float, unsigned short);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    float payRate;
    unsigned short hrsWrkd;
    
    //Input or initialize values Here
    cout<<"Paycheck Calculation."<<endl;
    cout<<"Input payRate in $'s/hour and hours worked"<<endl;
    cin>>payRate>>hrsWrkd;
    
    //Calculate and output
    cout << fixed << setprecision(2) << "$" << paycheck(payRate, hrsWrkd) << endl;
    
    //Exit
    return 0;
}

float paycheck(float payRate, unsigned short hrsWrkd) {
    float result; //The value were going to return.
    if (hrsWrkd > OTHRS) { //40+ hours worked
        result = (payRate*REGHRS); //First pay off the initial 20 hours
        result += (payRate*REGHRS*PAYOT); //Pay the second 20 hours at 1.5x
        result += ((hrsWrkd-OTHRS)*(payRate*PAYDT)); //Pay the remainder at double time.
    }
    else if (hrsWrkd > REGHRS) { //20-40 hours worked.
        result = (payRate*REGHRS); //Pay them for the initial 20 hours.
        result += ((hrsWrkd-REGHRS)*(payRate*PAYOT)); //Pay the remained in 1.5x pay
    }
    else { //Worked less than 20 hours
        result = (payRate*hrsWrkd); //Pay them their base pay
    }
    
    return result;
}