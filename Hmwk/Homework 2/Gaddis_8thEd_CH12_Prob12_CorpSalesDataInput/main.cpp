/* 
 * Author: James Hartley
 * Created on March 27, 2019, 10:09 PM
 * Description: Gaddis Ch.12 Problem 11 Corporate Sales Data Output
 */

#include <iostream>
#include <fstream>

using namespace std;

struct division {
    char name[10];
    int qtrSales[4];
};

void fileToStruct(string fileName, division* div, int arySize) {
    fstream fileObject;
    fileObject.open(fileName, ios::in | ios::binary);
    fileObject.read(reinterpret_cast<char *>(div), sizeof(division) * arySize);
    fileObject.close();
}

int main(int argc, char** argv) {
    division divsImport[4];
    fileToStruct("struct.dat", divsImport, 4);
    
    for (int i = 0; i < 4; i++) {
        cout << "Division: " << divsImport[i].name << endl;
        for (int j = 0; j < 4; j++) {
            cout << "Quarter: " << j+1 << endl;
            cout << "Sales: " << divsImport[i].qtrSales[j] << endl;
        }
    }
    return 0;
}

