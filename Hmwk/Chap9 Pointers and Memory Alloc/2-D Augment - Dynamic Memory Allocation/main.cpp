#include <iostream>

using namespace std;

//Prototypes
int **getData(int &,int &);//Get the Matrix Data
void prntDat(int **,int,int);//Print the Matrix
int **augment(int **,int,int);//Augment the original array
void destroy(int **,int);//Destroy the Matrix, i.e., reallocate memory

int main(){
	int** array;
	int** augAry;
	int row, column;
	
	//Get the info.
	array = getData(row, column);
	
	//Print the info.
	prntDat(array, row, column);
	
	//Get augmented array
	augAry = augment(array, row, column);
	
	//endl
	cout << endl;
	
	//Print the augmented array
	prntDat(augAry, row+1, column+1);
	
	delete[] array;
	delete[] augAry;
	
	return 0;
}

int **augment(int **array, int row, int column) {
    int **augAry = new int*[row+1];
    for(int i = 0; i < row+1; ++i) {
        augAry[i] = new int[column+1];
    }
    
    //Loop to fill the array
    for (int i = 0; i < row+1; i++)
    {
        for (int j = 0; j < column+1; j++) {
            if (i == 0 || j == 0) {
                augAry[i][j] = 0;
            }
            else {
                augAry[i][j] = array [i-1][j-1];
            }
        }
    }
    
    return augAry;
}

int **getData(int &row, int &column) {
    //Get Array size from input
    cin >> row >> column;
    
    int** array = new int*[row];
    for(int i = 0; i < row; ++i) {
        array[i] = new int[column];
    }
    
    //Loop to fill the array
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++) {
            cin >> array[i][j];
        }
    }
    
    //return the array
    return array;
}

void prntDat(int **array, int row, int column) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << array[i][j];
            j < column-1?cout<<" ":cout<<"";
        }
        i < row-1?cout << endl:cout<<"";
    }
}
