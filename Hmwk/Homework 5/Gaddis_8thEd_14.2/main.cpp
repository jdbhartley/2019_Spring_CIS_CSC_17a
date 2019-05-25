#include <iostream>
#include <string>

using namespace std;

class DayOfYear {
private:
    int dayofyr;
    int day;
    int month;
    string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    
public:
    DayOfYear(int n) {
        dayofyr = n;
        day = n%30;
    }
    
    DayOfYear(string m, int day) {
            if (m == "January") {
                month = 1;
            }
            if (m == "February") {
                month = 2;
            }
            if (m == "March") {
                month = 3;
            }
            if (m == "April") {
                month = 4;
            }
            if (m == "May") {
                month = 5;
            }
            if (m == "June") {
                month = 6;
            }
            if (m == "July") {
                month = 7;
            }
            if (m == "August") {
                month = 8;
            }
            if (m == "September") {
                month = 9;
            }
            if (m == "October") {
                month = 10;
            }
            if (m == "November") {
                month = 11;
            }
            if (m == "December") {
                month = 12;
            }
        
        dayofyr = ((month-1) * 30) + day+3;
    }
    
    void Print() {
        cout << months[dayofyr/30] << " " << day;
    }
    
};
int main(int argc, char** argv) {
    cout << "Enter Month then Day. ex: January 6" << endl;
    string month;
    int day;
    cin >> month;
    cin >> day;
    DayOfYear year(month, day);
    year.Print();
    return 0;
}

