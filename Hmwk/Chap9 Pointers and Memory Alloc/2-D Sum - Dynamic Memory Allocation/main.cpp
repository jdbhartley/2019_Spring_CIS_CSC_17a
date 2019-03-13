#include <iostream>

using namespace std;

int **getData(int &,int &);        //Return the 2-D array and its size.
void prntDat(int**,int,int);//Print the 2-D Array
void destroy(int **,int,int);       //Deallocate memory
int sum(int **, int,int);    //Return the Sum

int main(){
	int rows, columns;
	int **array;
	
	array = getData(rows, columns);
	prntDat(array, rows, columns);
	
	cout << sum(array, rows, columns);
	
	delete[] array;
	return 0;
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
        cout << endl;
    }
}

int sum(int **array, int row, int column) {
    int total = 0;
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            total += array[i][j];
        }
    }
    
    return total;
}
