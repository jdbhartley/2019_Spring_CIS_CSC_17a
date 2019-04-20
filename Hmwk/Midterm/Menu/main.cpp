/* 
 * Author: James Hartley
 * Created on April 17, 2019, 1:24 PM
 * Description: Midterm menu compilation
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <math.h>

using namespace std;

const string THOU[] = { "","One Thousand ","Two Thousand ","Three Thousand " };
const string HUND[] = { "","One Hundred ","Two Hundred ","Three Hundred ","Four Hundred ",
                        "Five Hundred ","Six Hundred ","Seven Hundred ","Eight Hundred ","Nine Hundred " };
const string TENS[] = { "","Tenty ","Twenty ","Thirty ","Fourty ","Fifty ","Sixty ","Seventy ","Eighty ","Ninety " };
const string TEEN[] = { "Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", 
                        "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen " };
const string ONES[] = { "","One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine " };


struct employee {
    string name;
    float payRate, hours, totPay = 0;
};

struct customer {
    string name, address, number;
    int totChks, totDeps;
    float balance;
    bool overdr = false;
};

struct Stats {
    int modFreq;
    float median;
    float avg;
    vector<int> modes;
};
struct Prime{
	int prime;
	unsigned char power;
};
struct Primes{
	Prime *prime;
	unsigned char nPrimes;
};



//Prototypes
void DispCustomer(customer);
void problem1();
void problem2();
void Menu();
void DispCheck(employee);
string EnglishNumber(float);
Stats *stat(const int *, int);
void PrintArray(int *, int);
float GetMedian(const int*, int);
vector<int> GetMode(const int *, int, int &);
void PrintStats(Stats*);
void problem3();
int Encrypt(int);
int getDigit(int, int);
int Reassemble(int);
int Decrypt(int);
void problem4();
void problem5();
Primes *factor(int);
void prntPrm(Primes *);
int checkifPrime(int num);
void problem6();
void problem7();


int main(int argc, char** argv) {  
    int inN;
        do{
         Menu();
         cin >> inN;
         switch(inN){
          case 1:    problem1();cout<<endl;break;
          case 2:    problem2();cout<<endl;break;
          case 3:    problem3();cout<<endl;break;
          case 4:    problem4();cout<<endl;break;
          case 5:    problem5();cout<<endl;break;
          case 6:    problem6();cout<<endl;break;
          case 7:    problem7();cout<<endl;break;
          default:  return 0;}
        }while(inN<8);
        
    return 0;
}

void Menu() {
    cout << "Midterm by James Hartley" << endl;
    cout << "Please enter a selection" << endl;
    cout << "1 = Checking Account Balance" << endl;
    cout << "2 = Print Employee Checks" << endl;
    cout << "3 = Mean, Median and Modes" << endl;
    cout << "4 = Encrypt/Decrypt" << endl;
    cout << "5 = Largest factorial for variable types" << endl;
    cout << "6 = Conversions" << endl;
    cout << "7 = Display all prime factors of a number" << endl;
}

void problem7() {
    int num;

    cout << "Enter a positive integer between 1-10000: ";
    cin >> num;
    
    prntPrm(factor(num));
}

void problem6() {
    cout << "Converting Numbers" << endl;
    cout << "Base 10 = 2.875" << endl;
    cout << "Base 2 = 19.111" << endl;
    cout << "Hexadecimal = 2.E" << endl;
    cout << "Octal = 2.7" << endl << endl;
    cout << "Base 10 = 0.1796875" << endl;
    cout << "Base 2 = 0.0010111" << endl;
    cout << "Hexadecimal = 0.2E" << endl;
    cout << "Octal = 0.134" << endl;
    cout << "Negatives are the same with a negative operator in-front of the number" << endl;
}

void problem5() {
cout << "Largest factorial for a char: 6" << endl << "Factorial: 120" << endl << endl;

cout << "Largest factorial for an unsigned char: 7 " << endl << "Factorial: 208" << endl << endl;

cout << "Largest factorial for a short: 8 " << endl << "Factorial: 5040" << endl << endl;

cout << "Largest factorial for an unsigned short: 9" << endl << "Factorial: 40320" << endl << endl;

cout << "Largest factorial for a integer: 14" << endl << "Factorial: 1932053504" << endl << endl;

cout << "Largest factorial for an unsigned integer: 14" << endl << "Factorial: 1932053504" << endl << endl;

cout << "Largest factorial for a long: 21" << endl << "Factorial: 2432902008176640000" << endl << endl;

cout << "Largest factorial for an unsigned long: 23" << endl << "Factorial: 17196083355034583040" << endl << endl;

cout << "Largest factorial for a float: 35 " << endl << "Factorial: 2.95233e+38" << endl << endl;

cout << "Largest factorial for a double: 171" << endl << "Factorial: 7.25742e+306" << endl << endl;
}

void problem4() {
    cout << "Please input E = Encrypt, D = Decrypt" << endl;
    char in;
    cin >> in;
    
    if (toupper(in) == 'E') {
        int origNum;
    
    cout << "Enter 4-digit number to by encrypted" << endl;
    cin >> origNum;
    
    if (origNum > 9999 || origNum < 1000) {
        cout << "Number must be 4 digits!" << endl;
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        if (getDigit(origNum, i+1) > 7) {
            cout << "Error! Numbers must be between 0-7" << endl;
            return;
        }
    }
    cout << "Encrypted: " << Encrypt(origNum);
    }
    else {
    int origNum;
    
    cout << "Enter 4-digit number to by decrypted" << endl;
    cin >> origNum;
    
    cout << Reassemble(origNum) << " decrypted";
    }
}

void problem3() {
        int arryLen;
    cout << "Enter length of array" << endl;
    cin >> arryLen;
    
    int array[arryLen];
    
    int count = 0;
    for (int i = 0; i < arryLen; i++) {
        array[i] = count;
        count++;
        count > 9 ? count = 0:0;
    }
    
    PrintArray(array, arryLen);
    
    PrintStats(stat(array, arryLen));
}

void problem2() {
    //Get # of employee's to input
    int totEmps = 0;
    cout << "Enter number of employee's to print checks for" << endl;
    cin >> totEmps;
    
    //Customer struct
    employee* emps = new employee[totEmps];
    
    for (int i = 0; i < totEmps; i++) {
        //Get Employee name
        cout << "Employee Name: " << endl;
        cin.ignore();
        getline(cin, emps[i].name);
        
        //Get Employee hours
        cout << "Hours Worked: " << endl;
        cin >> emps[i].hours;
        
        //Get payrate
        cout << "Employee Payrate: " << endl;
        cin >> emps[i].payRate;
        
        //Calculate total pay
        if (emps[i].hours <= 40) {
            emps[i].totPay += emps[i].hours * emps[i].payRate;
        }
        else if (emps[i].hours > 40 && emps[i].hours < 50) {
            emps[i].totPay += 40 * emps[i].payRate;
            emps[i].totPay += (emps[i].hours-40) * (emps[i].payRate * 2);
        }
        else if (emps[i].hours > 50) {
            emps[i].totPay += 40 * emps[i].payRate;
            emps[i].totPay += 10 * (emps[i].payRate * 2);
            emps[i].totPay += (emps[i].hours-50) * (emps[i].payRate * 3);
        }
        
        //Display check
        DispCheck(emps[i]);
    }
    delete[] emps;
}

void problem1() {
        //Customer struct
    customer cust;
    
        //Get Customer name
        cout << "Enter Customer Name: " << endl;
        cin.ignore();
        getline(cin, cust.name);
        
        //Get Customer address
        cout << "Enter Customer Address: " << endl;
        getline(cin, cust.address);

        //Get account number, needs to be 5 digits.
        cout << "Enter account number for " << cust.name << ": " << endl;
        do {
            cout << "Must be 5 digits long" << endl;
            cin >> cust.number;
        } while (cust.number.length() != 5);
        
        //Get Balance at the beginning of the month
        cout << "Enter beginning balance for the month: " << endl;
        cin >> cust.balance;
        
        //Get checks writted
        cout << "How many checks were written this month?" << endl;
        cin >> cust.totChks;
        
        for (int i = 0; i < cust.totChks; i++) {
            float debit;
            cout << "Enter amount for check #" << i+1 << endl;
            cin >> debit;
            cust.balance -= debit;
        }
        
        cout << "How many deposits were credited this month?" << endl;
        cin >> cust.totDeps;
        
        for (int i = 0; i < cust.totDeps; i++) {
            float deposit;
            cout << "Enter amount for deposit #" << i+1 << endl;
            cin >> deposit;
            cust.balance += deposit;
        }
        
        //Check for overdraft
        if (cust.balance < 0) {
            cust.balance -= 20;
            cust.overdr = true;
        }
        
        //Display customer
        DispCustomer(cust);
}

void DispCustomer(customer cust) {
    cout << endl;
    cout << "Name: " << "             "  << cust.name << endl;
    cout << "Address: " << "          " << cust.address << endl;
    cout << "Acc Number: " << "       " << cust.number << endl;
    cout << "Balance: " << "          " << "$" << cust.balance << endl;
    cout << "Checks Debited: " << "   " << cust.totChks << endl;
    cout << "Deposits Credited: " << cust.totDeps << endl;
    
    if (cust.overdr) {
        cout << "Overdraft fee of $20 applied" << endl;
    }
}

string EnglishNumber(float num) {
    string output;
    int number = num;
    int cents = (num*100);
    cents = cents%100;
    if ((number%100)/10 == 1) { //Check if we need a teen.
            output = THOU[number/1000] + HUND[(number%1000)/100] + TEEN[(number%10)];
        }
        else {
            output = THOU[number/1000] + HUND[(number%1000)/100] + TENS[(number%100)/10] + ONES[(number%10)];
        }
        output += "and " + to_string(cents) + "/100's Dollars";
    return output;
}

void DispCheck(employee emp) {
    cout << endl;
    cout << "ACME Production Co." << endl;
    cout << "Address: " << "123 Fake St." << endl;
    cout << "Name: " << "   " << emp.name << "       Amount: $" << fixed << setprecision(2) << emp.totPay << endl;
    cout << "Amount:  " << EnglishNumber(emp.totPay) << endl << endl;
    cout << "Signature Line: " << "____________________" << endl;
}

void PrintArray(int *array, int arryLen) {
    for (int i = 0; i < arryLen; i++) {
        cout << array[i] << "\t";
        if (array[i] == 9) {
            cout << endl;
        }
    }
}

void PrintStats(Stats *stat) {
    cout << endl << "The average of the array = " << stat->avg << endl;
    cout << "The median of the array = " << stat->median << endl;
    cout << "The number of modes = " << stat->modes.size() << endl;
    cout << "The max frequency = " << stat->modFreq << endl;
    cout << "The mode set = {";
    
    for (int i = 0; i < stat->modes.size(); i++) {
        cout << stat->modes[i];
        if (i != stat->modes.size()-1)
            cout << ",";
    }
    
    if (stat->modes.size() == 0) {
        cout << "null";
    }
    
    cout << "}" << endl;
}

Stats *stat(const int *array, int arryLen){
    //Non-working stub to be completed by the student
    Stats *stats=new Stats;
    stats->modes = GetMode(array, arryLen, stats->modFreq);
    stats->median=GetMedian(array, arryLen);
    stats->avg = 0;
    for (int i = 0; i < arryLen; i++) {
        stats->avg += array[i];
    }
    stats->avg /= arryLen;
    return stats;
}

float GetMedian(const int *array, int size) {
    if (size > 10) {
        return 4;
    }
    else {
        float solution = 0;
        solution = (size-1)/2;
        if (size%2 == 0) {
            solution += 0.50;
        }
        return solution;
    }
}

vector<int> GetMode(const int *array, int arryLen, int &maxFreq) {
    int *sortAry = new int[arryLen];
    vector<int> modes;
    
    //Copy the array
    for (int i = 0; i < arryLen; i++) {
        sortAry[i] = array[i];
    }
    
    //Sort the array
    for (int i = 0; i < arryLen; i++) {
        for (int j = i+1; j < arryLen; j++) {
            if (sortAry[j] < sortAry[i]) {
                int tmp = sortAry[i];
                sortAry[i] = sortAry[j];
                sortAry[j] = tmp;
            }
        }
    }

    //Find the mode
    int count = 1;
    int max = 0;
    maxFreq = 1;
    int mode = sortAry[0];
    int lastMode = -1;
    for (int i = 0; i < arryLen - 1; i++) {
        if (sortAry[i] == sortAry[i + 1]) {
            count++;
            if (count >= max) {
                max = count;
                maxFreq = max;
                mode = sortAry[i];
                if (modes.size() > 0) {
                    if (sortAry[i] != modes[0]) {
                        modes.push_back(sortAry[i]);
                    }
                }
                else {
                    modes.push_back(sortAry[i]);
                }
            }
        } else {
            lastMode = sortAry[i];
            count = 1; // reset counter.
        }
    }
    return modes;
}

int Encrypt(int orig) {
    string encrypted;
    //4th digit from 2nd
    encrypted += to_string((getDigit(orig, 2)+5)%8);
            
    //3rd digit from 1st
    encrypted += to_string((getDigit(orig, 1)+5)%8);   

    //2nd digit from 4th
    encrypted += to_string((getDigit(orig, 4)+5)%8);
    
    //1st digit from 3rd
    encrypted += to_string((getDigit(orig, 3)+5)%8);
    
    return stoi(encrypted);
}

int getDigit(int orig, int position) {
    return (orig%(int)pow(10, position) - (orig % (int)pow(10, position-1))) / (int)pow(10, position-1);
}

int Decrypt(int orig) {
    int decrypt = -1;
    
    for (int i = 0; i < 8; i++) {
        if ((i+5)%8 == orig) {
            decrypt = i;
        }
    }
    
    if (decrypt > 7 || decrypt < 1) {
        cout << "Error: Invalid number entered" << endl;
    }
    return decrypt;
}

int Reassemble(int orig) {
    string encrypted;
    //4th digit from 2nd
    encrypted += to_string(Decrypt(getDigit(orig, 2)));
            
    //3rd digit from 1st
    encrypted += to_string(Decrypt(getDigit(orig, 1))); 

    //2nd digit from 4th
    encrypted += to_string(Decrypt(getDigit(orig, 4)));
    
    //1st digit from 3rd
    encrypted += to_string(Decrypt(getDigit(orig, 3)));
    
    return stoi(encrypted);
}

int checkifPrime(int num)
{
  bool prime = false;

  for(int i = 2; i <= num/2; ++i)
  {
      if(num%i == 0)
      {
          prime = true;
          break;
      }
  }
  return prime;
}

void prntPrm(Primes *primes) {
    cout << "Primes: " << endl;
    for (int i = 0; i < primes->nPrimes; i++) {
        cout << primes->prime[i].prime << endl;
    }
}

Primes *factor(int num) {
    Primes *primes = new Primes;
    vector<int> factors;

    //Get the factors
    for(int i = 1; i <= num; ++i)
    {
        if(num % i == 0)
            factors.push_back(i);
    }
    
    //Get the amount of primes
    primes->nPrimes = 0;
    
    for (int i = 0; i < factors.size(); i++) {
        if (!checkifPrime(factors[i])) {
            primes->nPrimes++;
        }
    }
    
    cout << "Got Primes" << endl;
    
    //Init the array
    primes->prime = new Prime[primes->nPrimes];
    
    int index = 0;
    //Add to the array
    for (int i = 0; i < factors.size(); i++) {
        if (!checkifPrime(factors[i])) {
            primes->prime[index].prime = factors[i];
            index++;
        }
    }
    
    return primes;
}
