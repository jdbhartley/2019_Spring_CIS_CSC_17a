#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

class Payroll {
private:
    float hrRate;
    float hrsWrkd;
    float gross;
    
public:
    void Init(float hrR, float hrsW) {
        hrRate = hrR;
        hrsWrkd = hrsW;
        
        if (hrsWrkd > 60) {
            cout << "Hours Worked Invalid, enter 1-60" << endl;
            hrsWrkd = 60;
        }
    }
    
    float GetGross() {
        return hrsWrkd * hrRate;
    }
    
};

int main(int argc, char** argv) {
    Payroll pr[7];
    
    for (int i = 0; i < 7; i++) {
        float hrsWrkd, hrRate;
        cout << "Enter Hours Worked for Employee: " << i+1 << endl;
        cin >> hrsWrkd;
        cout << "Enter Hourly Rate: " << endl;
        cin >> hrRate;
    
        pr[i].Init(hrsWrkd, hrRate);
    }
    
    cout << "Displaying gross pay for employees: " << endl;
    for (int i = 0; i < 7; i++) {
        cout << "Employee " << i+1 << "'s gross pay: " << pr[i].GetGross() << endl;
    }
    
    return 0;
}

