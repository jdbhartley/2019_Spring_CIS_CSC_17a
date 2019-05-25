#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

class NumberArray {
private:
    float *array;
    int length;
    
public:
    NumberArray(int len) {
        array = new float[len];
        length = len;
    }
    
    ~NumberArray() {
        cout << "Destroyed NumberArray" << endl;
        delete[] array;
    }
    
    void SetValue(float value, int indx) {
        if (indx < length && indx > -1) {
            array[indx] = value;
        }
        else {
            cout << "Invalid Index Entered!" << endl;
        }
    }
    
    float GetValue(int indx) {
        if (indx < length && indx > -1) {
            return array[indx];
        }
        else {
            cout << "Invalid Index Entered!" << endl;
            return 0;
        }
    }
    
    float GetHighestVal() {
        float val = 0;
        for (int i = 0; i < length; i++) {
            if (array[i] > val) {
                val = array[i];
            }
        }
        return val;
    }
    
    float GetLowestVal() {
        float val = 100000;
        for (int i = 0; i < length; i++) {
            if (array[i] < val) {
                val = array[i];
            }
        }
        return val;
    }
    
    float GetAverage() {
        float val = 0;
        for (int i = 0; i < length; i++) {
            val += array[i];
        }
        
        return val/length;
    }
};

int main(int argc, char** argv) {

    srand(time(0));
    NumberArray na(10);
    
    for (int i = 0; i < 10; i++) {
        na.SetValue(rand()%100+1, i);
    }
    
    cout << "Generated Numbers: " << endl;
    for (int i = 0; i < 10; i++) {
        cout << na.GetValue(i) << " ";
    }
    cout << endl;
    
    cout << "The Highest Number Generated = " << na.GetHighestVal() << endl;
    cout << "The Lowest Number Generated = " << na.GetLowestVal() << endl;
    cout << "The Average of the numbers = " << na.GetAverage() << endl;
    
    return 0;
}

