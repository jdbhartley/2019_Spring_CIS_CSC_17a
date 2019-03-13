#include <iostream>

using namespace std;

//Prototypes
int *getData(int &);//Read the array
int *augment(const int *,int);//Augment and copy the original array
void prntAry(const int *,int);//Print the array

int main(){
    int arySize;
    int *array;
    
	array = getData(arySize);
	prntAry(array, arySize);
	cout << endl;
	array = augment(array, arySize);
	prntAry(array, arySize+1);
	
	return 0;
}

int *augment(const int *array , int arySize) {
    int *tmpAry = new int[arySize + 1];
    *(tmpAry) = 0;
    
    for (int i = 1; i < arySize + 1; i++) {
        *(tmpAry + i) = *(array + i - 1);
    }
    
    return tmpAry;
}

int *getData(int &arySize) {
    //Get Array size from input
    cin >> arySize;
    
    //Make new dynamic array from array size;
    int *array = new int[arySize];
    
    //Loop to fill the array
    for (int i = 0; i < arySize; i++)
    {
        cin >> *(array + i);
    }
    
    //return the array
    return array;
}

void prntAry(const int *array,int arySize) {
    for (int i = 0; i < arySize; i++) {
        cout << *(array + i);
        i < arySize-1?cout<<" ":cout<<"";
    }
}