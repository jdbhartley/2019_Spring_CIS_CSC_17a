/* 
 * File:    main.cpp
 * Author:  James Hartley
 * Created: January 25, 10:35AM
 * Purpose: Cross one-side or the other
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void forwardSlash(unsigned short);
void backSlash(unsigned short);
void cross(unsigned short);

//Program Execution Begins Here

int main(int argc, char** argv) {
    //Declare all Variables Here
    unsigned short x;
    char shape; //f-> forward b->backward x->cross

    //Input or initialize values Here
    cout << "Create a numbered shape that can be sized." << endl;
    cout << "Input an integer number [1,50] and a character [x,b,f]." << endl;
    cin >> x>>shape;

    //Draw the shape
    switch (shape) {
        case 'f':
            forwardSlash(x);
            break;
        case 'b':
            backSlash(x);
            break;
        case 'x':
            cross(x);
            break;
    }

    //Exit
    return 0;
}

void forwardSlash(unsigned short x) {
    //Forward Slash
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            if (j == x - i - 1) {
                if (x % 2 == 0) {
                    cout << x - (i);
                } else {
                    cout << i + 1;
                }
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void backSlash(unsigned short x) {
    //Forward Slash
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            if (j == i) {
                if (x % 2 == 0) {
                    cout << i + 1;
                } else {
                    cout << x - i;
                }
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void cross(unsigned short x) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            if (j == x - i - 1) {
                if (x % 2 == 0) {
                    cout << x - i;
                } else {
                    cout << i + 1;
                }
            } else if (j == i) {
                if (x % 2 == 0) {
                    cout << i + 1;
                } else {
                    cout << x - i;
                }
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}