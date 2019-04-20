/* 
 * Author: James Hartley
 * Created on April 17, 2019, 1:24 PM
 * Description: Encrypt 4-digit number
 */

#include <iostream>
#include <math.h>

using namespace std;

float intFactorial(float);

int main(int argc, char** argv) {  
    float count = 1;
    double factorial = 1;
    double prevFactor = 1;
    

    while (factorial >= prevFactor && count < 200) {
        prevFactor = factorial;
        factorial *= count;
        count++;
        cout << "Factorial: " << factorial << " count: " << count << endl;
    }
    
    
    //cout << "Largest factorial for a double: " << count-1 << endl;
    //cout << "Factorial: " << intFactorial(count-1) << endl;
    return 0;
}

float intFactorial(float count) {
    float factorial = 1;
    for (float i = 1; i < count; i++) {
        factorial *= i;
    }
    return factorial;
}