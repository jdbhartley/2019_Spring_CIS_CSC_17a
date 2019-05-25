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
    
    Date() {
        month = 1;
        day = 3;
        year = 2019;
    }
    
    Date& operator++(int) {
        this->day++;
        if (this->day == 32) {
            this->day = 1;
        }
        return *this;
    }
    Date& operator--(int) {
        this->day--;
        if (this->day == 0) {
            this->day = 31;
        }
        return *this;
    }
    Date operator-(const Date& nd) const{
        Date solution;
        solution.day = this->day - nd.day; 
        solution.month = this->month - nd.month;
        solution.year = this->year;
        return solution;
    }

    
    void SetDate() {
        cout << "Enter Month 1-12:" << endl;
        cin >> month;
        cout << endl << "Enter Day 1-31:" << endl;
        cin >> day;
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
    
    string PrintDate4() {
        return MonthToText(month) + " " + to_string(day) + ", " + to_string(year);
    }
};

std::ostream& operator<<(std::ostream& stream, Date& date) {
    stream << date.PrintDate4();
    return stream;
}

istream& operator>>(istream &input,Date& date)
{
    date.SetDate();
    return input;
}

int main(int argc, char** argv) {
    Date date;
    
    cin >> date;
    
    cout << endl;
    
    cout << date;
    
    cout << "Incrementing..." << endl;
    date++;
    cout << date;
    cout << "Decrementing..." << endl;
    date--;
    cout << date;
    
    
    return 0;
}

