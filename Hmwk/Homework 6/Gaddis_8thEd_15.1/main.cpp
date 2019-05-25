#include <iostream>

using namespace std;

class Employee {
private:
    std::string _name, _hireDt;
    int _empNum;
    
public:
    Employee(std::string name, std::string hireDt, int empNum) {
        _name = name;
        _hireDt = hireDt;
        _empNum = empNum;
    }
    
    std::string GetName() { return _name; }
    std::string GetHireDate() { return _hireDt; }
    int GetEmpNum() { return _empNum; }
};

class ProductionWorker : public Employee {
private:
    int _shift;
    double _hrRate;
    
public:
    ProductionWorker(int shift, double hrRate, std::string name, std::string hireDt, int empNum) 
    : Employee(name, hireDt, empNum) {
        _shift = shift;
        _hrRate = hrRate;
    }
    
    int GetShift() { return _shift; }
    double GetHourlyRate() { return _hrRate; }
};

int main(int argc, char** argv) {
    ProductionWorker* worker = new ProductionWorker(1, 12.50, "James", "01/06/2018", 11015);
    
    cout << worker->GetEmpNum() << " " << worker->GetName() << endl << "Hired: " << worker->GetHireDate() << endl;
    cout << "Shift: " << worker->GetShift() << " Hourly Rate: " << worker->GetHourlyRate() << endl;
    
    delete worker;
    return 0;
}

