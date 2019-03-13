#include <iostream>

using namespace std;

//Function Prototypes
int *getData(int &);            //Return the array size and the array from the inputs
int *sumAry(const int *,int);   //Return the array with successive sums
void prntAry(const int *,int);  //Print the array

int main(){
	int arySize;
	int* array;
	int* sum;
	
	array = getData(arySize);
	sum = sumAry(array, arySize);
	prntAry(array, arySize);
	cout << endl;
	prntAry(sum, arySize);
	
	return 0;
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

int *sumAry(const int *array, int arySize) {
    int* sum = new int[arySize];
    int tmpsum = 0;
    for (int i = 0; i < arySize; i++)
    {
        *(sum + i) = *(array + i) + *(sum + (i - 1));
    }
    
    return sum;
}
