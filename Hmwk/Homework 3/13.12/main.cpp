#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

class Coin {
private:
    string sideUp;
    
public:
    Coin() {
        if (rand()%101 < 50) {
            sideUp = "Heads";
        }
        else {
            sideUp = "Tails";
        }
    }
    
    void Toss() {
        if (rand()%101 < 50) {
            sideUp = "Heads";
        }
        else {
            sideUp = "Tails";
        }
    }
    
    string getSideUp() {
        return sideUp;
    }

};

int main(int argc, char** argv) {
    srand(time(NULL));
    Coin coin;
    int nHeads = 0;
    int nTails = 0;
    
    cout << "Coin Started as: " << coin.getSideUp() << endl;
    cout << "Flipping 20 times..." << endl;
    
    for (int i = 0; i < 20; i++) {
        coin.Toss();
        cout << "Flipped: " << coin.getSideUp() << endl;
        if (coin.getSideUp() == "Heads") {
            nHeads++;
        }
        else {
            nTails++;
        }
    }
    
    cout << endl;
    cout << "Flipped Heads " << nHeads << " times." << endl;
    cout << "Flipped Tails " << nTails << " times." << endl;
    return 0;
}

