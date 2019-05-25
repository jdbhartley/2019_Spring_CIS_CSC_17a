#include <iostream>

using namespace std;

class Car {
private:
    int yearModel, speed;
    string make;
    
public:
    Car(int yr, string mk) {
        yearModel = yr; make = mk; speed = 0;
    }
    
    int GetYear() {
        return yearModel;
    }
    string GetMake() {
        return make;
    }
    int GetSpeed() {
        return speed;
    }
    
    void Accelerate() {
        speed += 5;
    }
    void Brake() {
        speed -= 5;
    }

};
int main(int argc, char** argv) {
    Car supra(1990, "Toyota Supra");
    
    for (int i = 0; i < 5; i++) {
        supra.Accelerate();
        cout << "Accelerating..." << endl;
        cout << "Current Speed: " << supra.GetSpeed() << endl;
    }
    
    cout << endl;
    
    for (int i = 0; i < 5; i++) {
        supra.Brake();
        cout << "Braking..." << endl;
        cout << "Current Speed: " << supra.GetSpeed() << endl;
    }
    
    return 0;
}

