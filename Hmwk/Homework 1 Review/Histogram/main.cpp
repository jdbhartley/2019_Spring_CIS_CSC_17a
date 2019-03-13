/* 
 * File:   main.cpp
 * Author: YOUR NAME HERE
 * Created on DATE AND TIME HERE
 * Purpose:  Histogram
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    char chars[4];
    
    //Input or initialize values Here
    cout<<"Create a histogram chart."<<endl;
    cout<<"Input 4 digits as characters."<<endl;
    cin >> setw(1) >> chars[3] >> chars[2] >> chars[1] >> chars[0];
    
    for(int i=0; i < 4; i++) {
        //output the value
        cout << chars[i] << " ";
        
        //Check if its a letter, if not convert to number.
        if (isalpha(chars[i])) {
            cout << "?" << endl;
            continue;
        }
        else {
            //Convert char to number
            chars[i] -= '0';
        }
        
        //Loop through and print asterisks depending on value
        for(int j=0; j < chars[i]; j++) {
            cout << "*";
        }
        
        //endl
        cout << endl;
    }
    
    //Exit
    return 0;
}