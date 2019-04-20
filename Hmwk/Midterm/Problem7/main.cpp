/* 
 * Author: James Hartley
 * Created on April 20, 2019, 1:24 PM
 * Description: Find all primes of a number
 */

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;



struct Prime{
	int prime;
	unsigned char power;
};
struct Primes{
	Prime *prime;
	unsigned char nPrimes;
};

Primes *factor(int);
void prntPrm(Primes *);
int checkifPrime(int num);

int main(int argc, char** argv) {  
    int num;

    cout << "Enter a positive integer between 1-10000: ";
    cin >> num;
    
    prntPrm(factor(num));
    
    return 0;
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