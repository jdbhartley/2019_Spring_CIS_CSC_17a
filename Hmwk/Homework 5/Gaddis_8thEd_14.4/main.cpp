#include <iostream>
#include <string>

using namespace std;

class NumDays {
private:
    float hours;
    float days;
    
public:
    NumDays operator+(const NumDays& nd) const {
        NumDays solution;
        solution.hours = nd.hours + this->hours;
        solution.days = nd.days + this->days;
        return solution;
    }
    
    NumDays operator-(const NumDays& nd) const{
        NumDays solution;
        solution.hours = this->hours - nd.hours; 
        solution.days = this->days - nd.days;
        return solution;
    }
    NumDays& operator++(int) {
        this->hours++;
        this->days = this->hours/8;
        return *this;
    }
    NumDays& operator--(int) {
        this->hours--;
        this->days = this->hours/8;
        return *this;
    }
    
    void SetHours(float hrs) {
        hours = hrs;
        days = hrs/8;
    }
    
    void Print() {
        cout << "Days Worked: " << days << endl;
        cout << "Hours: " << hours << endl;
    }
    
};

int main(int argc, char** argv) {
    cout << "Enter Hours Worked for Employee 1:" << endl;
    int n1;
    cin >> n1;
    
    cout << "Enter Hours Worked for Employee 2:" << endl;
    int n2;
    cin >> n2;
    
    cout << endl << "Employee 1 Days: " << endl;
    NumDays nd1;
    nd1.SetHours(n1);
    nd1.Print();
    
    cout << "Employee 1 + Employee 2: " << endl;
    NumDays nd2;
    nd2.SetHours(n2);
    
    NumDays nd3 = nd1 + nd2;
    
    nd3.Print();
    
    cout << "++ Operator: " << endl;
    nd3++;
    nd3.Print();
    cout << "-- Operator: " << endl;
    nd3--;
    nd3.Print();
    
    cout << "Employee 1 - Employee 2: " << endl;
    nd3 = nd1 - nd2;
    nd3.Print();
    
    return 0;
}

