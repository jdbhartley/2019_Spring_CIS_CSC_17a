#include <iostream>

using namespace std;

class Person {
private:
    string name, address, phone;
    int age;
    
public:
    Person(string n, string a, string p, int ag) {
        name = n; address = a; phone = p; age = ag;
    }
    
    string GetName() {
        return name;
    }
    string GetAddress() {
        return address;
    }
    string GetPhone() {
        return phone;
    }
    int GetAge() {
        return age;
    }
    void SetName(string n) {
        name = n;
    }
    void SetAddress(string a) {
        address = a;
    }
    void SetPhone(string p) {
        phone = p;
    }
    void SetAge(int a) {
        age = a;
    }
    void PrintInfo() {
        cout << "Name: " << name << endl << "Address: " << address << endl; 
        cout << "Age: " << age << endl << "Phone Number: " << phone << endl << endl;
    }
};
int main(int argc, char** argv) {
    Person myself("James", "15020 Marcolesco St.", "951-256-6921", 29);
    Person friend1("Craig", "123 Fake St.", "951-234-4567", 29);
    Person friend2("Mike", "321 NotFake St.", "951-123-3456", 28);
    
    myself.PrintInfo();
    friend1.PrintInfo();
    friend2.PrintInfo();
    
    return 0;
}

