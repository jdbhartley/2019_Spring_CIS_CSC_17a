#include <iostream>

using namespace std;

template <typename T>
T Minimum(T n1, T n2) {
    if (n1 < n2) {
        return n1;
    }
    else if (n2 < n1) {
        return n2;
    }
}

template <typename T>
T Maximum(T n1, T n2) {
    if (n1 < n2) {
        return n2;
    }
    else if (n2 < n1) {
        return n1;
    }
}

int main(int argc, char** argv) {
    
    cout << Minimum(5.0, 1.2);
    cout << endl;
    cout << Maximum("Testing2", "Testing");
    cout << endl;
    cout << Minimum(1, 100);
    return 0;
}

