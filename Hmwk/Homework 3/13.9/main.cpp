#include <iostream>

using namespace std;

class Population {
private:
    float pop, births, deaths, bRate, dRate;
    
public:
    void Init() {
        cout << "Enter total population: ";
        cin >> pop;
        cout << endl << "Enter total births: ";
        cin >> births;
        cout << endl << "Enter total deaths: ";
        cin >> deaths;
        cout << endl;
    }
    
    float GetBirthRate() {
        return births / pop;
    }
    float GetDeathRate() {
        return deaths / pop;
    }
};
int main(int argc, char** argv) {
    Population pop;
    pop.Init();
    
    cout << "Birth Rate: " << pop.GetBirthRate() << endl;
    cout << "Death Rate: " << pop.GetDeathRate() << endl;
    return 0;
}

