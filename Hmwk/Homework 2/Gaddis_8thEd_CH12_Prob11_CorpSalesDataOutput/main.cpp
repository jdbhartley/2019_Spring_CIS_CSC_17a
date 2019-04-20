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

void structToFile(string fileName, division* div, int arySize) {
    fstream fileObject;
    fileObject.open(fileName, ios::out | ios::binary);
    fileObject.write(reinterpret_cast<char *>(div), sizeof(division) * arySize);
    fileObject.close();
}

int main(int argc, char** argv) {
    division divs[4];
    cout << "Enter division names" << endl;
    cin >> divs[0].name;
    cin >> divs[1].name;
    cin >> divs[2].name;
    cin >> divs[3].name;
    
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << "Please enter Quarter " << j+1 << " sales for " << divs[i].name << " division" << endl;
            cin >> divs[i].qtrSales[j];
        }
    }
    
    structToFile("struct.dat", divs, 4);
    return 0;
}

