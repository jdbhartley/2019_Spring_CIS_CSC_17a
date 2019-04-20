/* 
 * Author: James Hartley
 * Created on April 17, 2019, 1:24 PM
 * Description: Encrypt 4-digit number
 */

#include <iostream>
#include <math.h>

using namespace std;

int Encrypt(int);
int getDigit(int, int);

int main(int argc, char** argv) {  
    int origNum;
    
    cout << "Enter 4-digit number to by encrypted" << endl;
    cin >> origNum;
    
    if (origNum > 9999 || origNum < 1000) {
        cout << "Number must be 4 digits!" << endl;
        return 1;
    }
    
    for (int i = 0; i < 4; i++) {
        if (getDigit(origNum, i+1) > 7) {
            cout << "Error! Numbers must be between 0-7" << endl;
            return 1;
        }
    }
    cout << "Encrypted: " << Encrypt(origNum);
    
    return 0;
}

int Encrypt(int orig) {
    string encrypted;
    //4th digit from 2nd
    encrypted += to_string((getDigit(orig, 2)+5)%8);
            
    //3rd digit from 1st
    encrypted += to_string((getDigit(orig, 1)+5)%8);   

    //2nd digit from 4th
    encrypted += to_string((getDigit(orig, 4)+5)%8);
    
    //1st digit from 3rd
    encrypted += to_string((getDigit(orig, 3)+5)%8);
    
    return stoi(encrypted);
}

int getDigit(int orig, int position) {
    return (orig%(int)pow(10, position) - (orig % (int)pow(10, position-1))) / (int)pow(10, position-1);
}
