/* 
 * Author: James Hartley
 * Created on March 27, 2019, 10:09 PM
 * Description: Gaddis Ch.12 Problem 8 Array/File Functions
 */

#include <iostream>
#include <fstream>

using namespace std;

void arrayToFile(string fileName, int* array, int arySize) {
    fstream fileObject;
    fileObject.open(fileName, ios::out | ios::binary);
    fileObject.write(reinterpret_cast<char *>(array), sizeof(int) * arySize);
    fileObject.close();
}

void fileToArray(string fileName, int* array, int arySize) {
    fstream fileObject;
    fileObject.open(fileName, ios::in | ios::binary);
    fileObject.read(reinterpret_cast<char *>(array), sizeof(int) * arySize);
    fileObject.close();
}

int main(int argc, char** argv) {
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int* storedArray = new int[10];
    
    arrayToFile("array.dat", array, 10);
    fileToArray("array.dat", storedArray, 10);
    
    for (int i = 0; i < 10; i++) {
        cout << storedArray[i];
    }
    
    delete[] storedArray;
    
    return 0;
}

