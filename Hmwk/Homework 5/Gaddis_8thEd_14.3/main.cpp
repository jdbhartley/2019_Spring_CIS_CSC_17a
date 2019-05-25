#include <iostream>
#include <string>

using namespace std;

class DayOfYear {
private:
    int dayofyr;
    int day;
    string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    
public:
    DayOfYear(int n) {
        dayofyr = n;
        day = n%30;
    }
    
    void Print() {
        cout << months[dayofyr/30] << " " << day;
    }
    
};
int main(int argc, char** argv) {
    cout << "Enter day of the year" << endl;
    int n;
    cin >> n;
    DayOfYear year(n);
    year.Print();
    return 0;
}

