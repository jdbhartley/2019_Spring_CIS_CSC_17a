#include <iostream>
#include <string.h>

using namespace std;

int *getData(int &);               //Fill the array
int *sort(const int *,int);         //Sort smallest to largest
int *reverse(const int *,int);  //Sort in reverse order
void prntDat(const int *,int); //Print the array

int main(){
	int arySize;
	int* array;
	
	//Create array
	array = getData(arySize);
	
	//Print array
	prntDat(sort(array,arySize), arySize);
        cout << endl;
	prntDat(reverse(array,arySize), arySize);
	
	delete[] array;
	return 0;
}

int *getData(int &arySize) {
    cin >> arySize;
    int *array = new int[arySize];
    for (int i = 0; i < arySize; i++)
    {
        cin >> *(array + i);
    }
    return array;
}

void prntDat(const int *array,int arySize) {
    for (int i = 0; i < arySize; i++) {
        cout << *(array + i);
        i < arySize-1?cout<<" ":cout<<"";
    }
}

int *sort(const int *array, int arySize) {
    int *tmpAry = new int[arySize];
    
    memcpy(tmpAry, array, arySize * sizeof *array);
    
    for (int i = 0; i < arySize; i++) {
        for (int j = i + 1; j < arySize; j++) {
            if (*(tmpAry + j) < *(tmpAry + i))
            {
                int tmp = *(tmpAry + j);
                *(tmpAry + j) = *(tmpAry + i);
                *(tmpAry + i) = tmp;
            }
        }
    }
    
    return tmpAry;
}

int *reverse(const int *array, int arySize) {
    int *tmpAry = new int[arySize];
    
    memcpy(tmpAry, array, arySize * sizeof *array);
    
    for (int i = 0; i < arySize; i++) {
        for (int j = i + 1; j < arySize; j++) {
            if (*(tmpAry + j) > *(tmpAry + i))
            {
                int tmp = *(tmpAry + j);
                *(tmpAry + j) = *(tmpAry + i);
                *(tmpAry + i) = tmp;
            }
        }
    }
    
    return tmpAry;
}