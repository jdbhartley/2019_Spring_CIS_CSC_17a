/* 
 * Author: James Hartley
 * Created on April 17, 2019, 1:24 PM
 * Description: Encrypt 4-digit number
 */

#include <iostream>
#include <math.h>

using namespace std;

int Reassemble(int);
int Decrypt(int);
int getDigit(int, int);

int main(int argc, char** argv) {  
    int origNum;
    
    cout << "Enter 4-digit number to by decrypted" << endl;
    cin >> origNum;
    
    cout << Reassemble(origNum) << " decrypted";
    
    return 0;
}

int Decrypt(int orig) {
    int decrypt = -1;
    
    for (int i = 0; i < 8; i++) {
        if ((i+5)%8 == orig) {
            decrypt = i;
        }
    }
    
    if (decrypt > 7 || decrypt < 1) {
        cout << "Error: Invalid number entered" << endl;
    }
    return decrypt;
}

int Reassemble(int orig) {
    string encrypted;
    //4th digit from 2nd
    encrypted += to_string(Decrypt(getDigit(orig, 2)));
            
    //3rd digit from 1st
    encrypted += to_string(Decrypt(getDigit(orig, 1))); 

    //2nd digit from 4th
    encrypted += to_string(Decrypt(getDigit(orig, 4)));
    
    //1st digit from 3rd
    encrypted += to_string(Decrypt(getDigit(orig, 3)));
    
    return stoi(encrypted);
}

int getDigit(int orig, int position) {
    return (orig%(int)pow(10, position) - (orig % (int)pow(10, position-1))) / (int)pow(10, position-1);
}
