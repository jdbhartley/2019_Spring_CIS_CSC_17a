#include <iostream>
#include <iomanip>

using namespace std;

//Function Prototypes
int *getData(int &);         //Return the array size and the array
void prntDat(const int *,int);    //Print the integer array
float *median(int *,int);  //Fill the median Array with the Float array size, the median, and the integer array data
void prntMed(float *, int *, int arySize);     //Print the median Array
int* sort(const int *, int );

int main(){
	int *array;
	int arySize;
	float *medAry;
	int *sortedAry;
	
	array = getData(arySize);
	sortedAry = sort(array, arySize);
	medAry = median(sortedAry, arySize);
	prntDat(array, arySize);
	cout << endl;
	prntMed(medAry, array, arySize);
	
	delete[] array;
	delete[] medAry;
	delete[] sortedAry;
	return 0;
}

int* sort(const int *array, int arySize) {
    int* sArray = new int[arySize];
    memcpy(sArray, array, arySize * sizeof *array);
    
    for (int i = 0; i < arySize; i++) {
        for (int j = i+1; j < arySize; j++) {
            if ( *(sArray + i) > *(sArray + j) )
            {
                int tmp = *(sArray + i);
                *(sArray + i) = *(sArray + j);
                *(sArray + j) = tmp;
            }
        }
    }
    
    return sArray;
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

float *median(int *array, int arySize) {
    float *median = new float[arySize+2];
    *median = arySize+2;
    int index = arySize/2;
    
    if (arySize%2 == 0) {
        *(median + 1) = *(array + arySize/2);
        *(median + 1) -= 0.50f;
    }
    else
    {
        *(median + 1) = *(array + (arySize/2));
    }
    
    for (int i = 2; i < arySize+2; i++) {
        *(median + i) = *(array + i-2);
    }
    
    return median;
}

void prntDat(const int *array,int arySize) {
    for (int i = 0; i < arySize; i++) {
        cout << *(array + i);
        i < arySize-1?cout<<" ":cout<<"";
    }
}

void prntMed(float *array, int *origArray, int arySize) {
    cout << *array << " ";
    cout << fixed << setprecision(2) << *(array + 1) << " ";
    for (int i = 0; i < arySize; i++) {
        cout << fixed << setprecision(2) << static_cast< float >(*(origArray + i));
        i < arySize-1?cout<<" ":cout<<"";
    }
}