/* 
 * Author: James Hartley
 * Created on March 21, 2019, 12:39 PM
 * Description: Gaddis Ch.12 Problem 1 File Head
 */

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    fstream input;
    string str;
    
    input.open("test.txt", ios::in);

        getline(input, str, '.');
        for (int i = 0; i < 10; i++) {
            cout << str[i];  
        }
        if (input.eof()) { cout << endl << "Complete file displayed"; }
    
    input.close();
    return 0;
}

