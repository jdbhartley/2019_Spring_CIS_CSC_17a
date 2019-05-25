#include <iostream>

using namespace std;

class Date {
    
    
private:
    int month, day, year;
    
    string MonthToText(int m) {
        switch (m) {
            case 1: return "January"; break;
            case 2: return "February"; break;
            case 3: return "March"; break;
            case 4: return "April"; break;
            case 5: return "May"; break;
            case 6: return "June"; break;
            case 7: return "July"; break;
            case 8: return "August"; break;
            case 9: return "September"; break;
            case 10: return "October"; break;
            case 11: return "November"; break;
            case 12: return "December"; break;
            default: return "Invalid"; break;
        }
    }
    
public:
    class InvalidDay{};
    class InvalidMonth{};
    Date() {
        month = 1;
        day = 3;
        year = 2019;
    }
    
    void SetDate() {
        cout << "Enter Month 1-12:" << endl;
        cin >> month;
        if (month <1 || month > 12) {
            throw InvalidMonth();
        }
        cout << endl << "Enter Day 1-31:" << endl;
        cin >> day;
        if (day <1 || day > 31) {
            throw InvalidDay();
        }
        cout << endl << "Enter Year:" << endl;
        cin >> year;
    }\

    void PrintDate() {
        cout << month << "/" << day << "/" << year << endl;
    }
    
    void PrintDate2() {
        cout << MonthToText(month) << " " << day << ", " << year << endl;
    }
    
    void PrintDate3() {
        cout << day << " " << MonthToText(month) << " " << year << endl;
    }
};
int main(int argc, char** argv) {
    Date date;

    bool pass = false;
    while (pass == false) {
        try {
            date.SetDate();
            pass = true;
        } catch (Date::InvalidMonth) {
            cout << "Invalid Month Entered, Please enter 1-12\n";
        } catch (Date::InvalidDay) {
            cout << "Invalid Day Entered, Please enter 1-31\n";
        }
    }
    
    cout << endl;
    
    date.PrintDate();
    date.PrintDate2();
    date.PrintDate3();
    
    return 0;
}

