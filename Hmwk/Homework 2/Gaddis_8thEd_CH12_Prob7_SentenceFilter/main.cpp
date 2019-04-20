/* 
 * Author: James Hartley
 * Created on March 21, 2019, 12:39 PM
 * Description: Gaddis Ch.12 Problem 7 Sentence Filter
 */

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    fstream input;
    fstream output;
    char ch;
    string str;
    bool uppr = false;
    
    input.open("original.txt", ios::in);
    output.open("edited.txt", ios::out);

    while (input) {
        getline(input, str, '.');
        for (int i = 0; i < str.length(); i++) {
            if (uppr == false && str[i] != ' ') {
                output.put(toupper(str[i]));
                uppr = true;
            }
            else {
                output.put(tolower(str[i]));
            }
        }
        if (!input.eof()) { output.put('.'); }
        uppr = false;
    }
    
    input.close();
    output.close();
    return 0;
}

