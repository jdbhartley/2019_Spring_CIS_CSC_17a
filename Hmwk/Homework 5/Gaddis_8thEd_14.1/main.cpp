#include <iostream>
#include <string>

using namespace std;

class Numbers {
private:
    string ones[20] = {"zero", "one", "two", "three", "four", "five", "six",
        "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen",
        "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    string tens[10] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty",
        "ninety"};
    string hundred = "hundred";
    string thousand = "thousand";
    int number = -1;
    
public:
    Numbers(int n) {
        if (n<10000&&n>0) {
            number = n;
        }
        else {
            cout << "Invalid entry please enter between 1-9999" << endl;
            number = -1;
        }
    }
    
    void Print() {
        if (number>19) {
            number%10000/1000!=0?cout << ones[number%10000/1000] << " " << thousand << " ":cout<<""; 
            number%1000/100!=0?cout<<ones[number%1000/100] << " " << hundred:cout<<"";
            if (number%1000/100!=0&&number%100/10!=0) {
            cout<<" and ";
            }
            number%100/10!=0?cout << tens[number%100/10] << " ":cout<<""; 
            number%10!=0?cout<<ones[number%10]:cout<<"";
        }
        else {
            cout << ones[number%100];
        }
    }
    
    int GetNumber() {
        return number;
    }
    
    void SetNumber(int n) {
        number = n;
    }
    
};
int main(int argc, char** argv) {
    int n;
    
    cout << "Please enter a number between 1-9999" << endl;
    cin >> n;
    
    Numbers num(n);
    
    while (num.GetNumber() == -1) {
        cin >> n;
        num.SetNumber(n);
    }
    
    num.Print();
    return 0;
}

