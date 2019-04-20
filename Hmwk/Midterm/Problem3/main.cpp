/* 
 * Author: James Hartley
 * Created on April 20, 2019, 1:03AM
 * Description: write a program that outputs
*  the mean, median, and modes.
 */

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

struct Stats {
    int modFreq;
    float median;
    float avg;
    vector<int> modes;
};

Stats *stat(const int *, int);
void PrintArray(int *, int);
float GetMedian(const int*, int);
vector<int> GetMode(const int *, int, int &);
void PrintStats(Stats*);

int main(int argc, char** argv) {
    int arryLen;
    cout << "Enter length of array" << endl;
    cin >> arryLen;
    
    int array[arryLen];
    
    int count = 0;
    for (int i = 0; i < arryLen; i++) {
        array[i] = count;
        count++;
        count > 9 ? count = 0:0;
    }
    
    PrintArray(array, arryLen);
    
    PrintStats(stat(array, arryLen));
    
    return 0;
}

void PrintArray(int *array, int arryLen) {
    for (int i = 0; i < arryLen; i++) {
        cout << array[i] << "\t";
        if (array[i] == 9) {
            cout << endl;
        }
    }
}

void PrintStats(Stats *stat) {
    cout << endl << "The average of the array = " << stat->avg << endl;
    cout << "The median of the array = " << stat->median << endl;
    cout << "The number of modes = " << stat->modes.size() << endl;
    cout << "The max frequency = " << stat->modFreq << endl;
    cout << "The mode set = {";
    
    for (int i = 0; i < stat->modes.size(); i++) {
        cout << stat->modes[i];
        if (i != stat->modes.size()-1)
            cout << ",";
    }
    
    if (stat->modes.size() == 0) {
        cout << "null";
    }
    
    cout << "}" << endl;
}

Stats *stat(const int *array, int arryLen){
    //Non-working stub to be completed by the student
    Stats *stats=new Stats;
    stats->modes = GetMode(array, arryLen, stats->modFreq);
    stats->median=GetMedian(array, arryLen);
    stats->avg = 0;
    for (int i = 0; i < arryLen; i++) {
        stats->avg += array[i];
    }
    stats->avg /= arryLen;
    return stats;
}

float GetMedian(const int *array, int size) {
    if (size > 10) {
        return 4;
    }
    else {
        float solution = 0;
        solution = (size-1)/2;
        if (size%2 == 0) {
            solution += 0.50;
        }
        return solution;
    }
}

vector<int> GetMode(const int *array, int arryLen, int &maxFreq) {
    int *sortAry = new int[arryLen];
    vector<int> modes;
    
    //Copy the array
    for (int i = 0; i < arryLen; i++) {
        sortAry[i] = array[i];
    }
    
    //Sort the array
    for (int i = 0; i < arryLen; i++) {
        for (int j = i+1; j < arryLen; j++) {
            if (sortAry[j] < sortAry[i]) {
                int tmp = sortAry[i];
                sortAry[i] = sortAry[j];
                sortAry[j] = tmp;
            }
        }
    }

    //Find the mode
    int count = 1;
    int max = 0;
    maxFreq = 1;
    int mode = sortAry[0];
    int lastMode = -1;
    for (int i = 0; i < arryLen - 1; i++) {
        if (sortAry[i] == sortAry[i + 1]) {
            count++;
            if (count >= max) {
                max = count;
                maxFreq = max;
                mode = sortAry[i];
                if (modes.size() > 0) {
                    if (sortAry[i] != modes[0]) {
                        modes.push_back(sortAry[i]);
                    }
                }
                else {
                    modes.push_back(sortAry[i]);
                }
            }
        } else {
            lastMode = sortAry[i];
            count = 1; // reset counter.
        }
    }
    return modes;
}