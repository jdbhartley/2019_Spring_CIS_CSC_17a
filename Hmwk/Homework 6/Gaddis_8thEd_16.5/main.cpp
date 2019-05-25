#include <iostream>

using namespace std;

template <typename T>
T Total(T length) {
    T tot = 0;
    for (T i = 0; i < length; i++) {
        T temp = 0;
        cin >> temp;
        tot += temp;
    }
    
    return tot;
}


int main(int argc, char** argv) {

    cout << "Enter number of values you want to input: " << endl;
    
    int i = 0;
    cin >> i;
    cout << "Enter your values: " << endl;
    cout << Total(<i);
    return 0;
}

