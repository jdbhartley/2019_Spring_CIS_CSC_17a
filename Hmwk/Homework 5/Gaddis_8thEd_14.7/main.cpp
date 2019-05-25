#include <iostream>
#include <string>

using namespace std;

class Month {
private:
    string name;
    int monthNumber;
    string monthNames[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
public:
    Month() {
        name = "January";
        monthNumber = 1;
    }
    Month(int n) {
        monthNumber = n;
        name = monthNames[n-1];
    }
    Month(string m) {
        SetMonthName(m);
    }
    
    string GetMonthName() const{
        return name;
    }
    int GetMonthNumber() const {
        return monthNumber;
    }
    void SetMonthNumber(int n) {
        monthNumber = n;
        name = monthNames[n-1];
    }
    void SetMonthName(string m) {
        name = m;
                if (m == "January") {
                monthNumber = 1;
            }
            if (m == "February") {
                monthNumber = 2;
            }
            if (m == "March") {
                monthNumber = 3;
            }
            if (m == "April") {
                monthNumber = 4;
            }
            if (m == "May") {
                monthNumber = 5;
            }
            if (m == "June") {
                monthNumber = 6;
            }
            if (m == "July") {
                monthNumber = 7;
            }
            if (m == "August") {
                monthNumber = 8;
            }
            if (m == "September") {
                monthNumber = 9;
            }
            if (m == "October") {
                monthNumber = 10;
            }
            if (m == "November") {
                monthNumber = 11;
            }
            if (m == "December") {
                monthNumber = 12;
            }
    }
    Month& operator++(int) {
        this->monthNumber++;
        if (this->monthNumber == 13) {
            this->monthNumber = 1;
        }
        this->SetMonthNumber(monthNumber);
        return *this;
    }
    Month& operator--(int) {
        this->monthNumber--;
        if (this->monthNumber == 0) {
            this->monthNumber = 12;
        }
        this->SetMonthNumber(monthNumber);
        return *this;
    }

    void Print() {
        cout << "Month Name: " << name << endl;
        cout << "Month Numbner: " << monthNumber << endl;
    }
    
};

std::ostream& operator<<(std::ostream& stream, const Month& mnth) {
    stream << "Month Name: " << mnth.GetMonthName() << endl;
    stream << "Month Numbner: " << mnth.GetMonthNumber() << endl;
    return stream;
}

int main(int argc, char** argv) {
    cout << "Enter Month Number: " << endl;
    Month mnth;
    int n;
    cin >> n;
    mnth.SetMonthNumber(n);
    
    cout << mnth;
    
    cout << "Incrementing by one." << endl;
    mnth++;
    cout << mnth;
    cout << "Decrementing by one." << endl;
    mnth--;
    cout << mnth;
  
    
    return 0;
}

