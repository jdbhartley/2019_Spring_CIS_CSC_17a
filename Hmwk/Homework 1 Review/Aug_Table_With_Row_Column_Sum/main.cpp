/* 
 * File:   main.cpp
 * Author: James Hartley
 * Created on February 8th, 2019 @ 1:06PM
 * Purpose:  Sum Rows, Sum Columns, Grand Sum of an integer array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <iomanip> //setw(10)
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;  //Max Columns much larger than needed.

//Function Prototypes Here
void read(int [][COLMAX],int &,int &);//Prompt for size then table
void sum(const int [][COLMAX],int,int,int[][COLMAX]);//Sum rows,col,grand total
void print(const int [][COLMAX],int,int,int);//Either table can be printed

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //Max Rows much larger than needed
    int array[ROW][COLMAX]={};  //Declare original array
    int augAry[ROW][COLMAX]={}; //Actual augmented table row+1, col+1
    int row,col;                
    
    //Input the original table
    read(array,row,col);
    
    //Augment the original table by the sums
    sum(array,row,col,augAry);
    
    //Output the original array
    cout<<endl<<"The Original Array"<<endl;
    print(array,row,col,10);//setw(10)
    
    //Output the augmented array
    cout<<endl<<"The Augmented Array"<<endl;
    print(augAry,row+1,col+1,10);//setw(10)
    
    //Exit
    return 0;
}

void read(int a[][COLMAX],int &r,int &c) { //Prompt for size then table
cout << "Input a table and output the Augment row,col and total sums." << endl;
cout << "First input the number of rows and cols. <20 for each" << endl;
cout << "Now input the table." << endl;

    cin >> c >> r;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            cin >> a[j][i];
        }
    }
}

void sum(const int a[][COLMAX],int r,int c,int aug[][COLMAX]) { //Sum rows,col,grand total
    int sum = 0;
    for (int i = 0; i <= c; i++) {
        for (int j = 0; j <= r; j++) {
            if (j == r) {
                aug[j][i] = sum;
                sum = 0;
            }
            else {
                aug[j][i] = a[j][i];
                sum += a[j][i];
            }
        }
    }
    

    sum = 0;
    for (int i = 0; i <= r; i++) {
        for (int j = 0; j <= c; j++) {
            sum += aug[i][j];
            if (j == c) {
                aug[i][j] = sum;
                sum = 0;
            }
        }
    }
    
}

void print(const int a[][COLMAX],int r,int c,int width) { //Either table can be printed
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
                cout << setw(width) << a[j][i];
        }
        cout << endl;
    }
}