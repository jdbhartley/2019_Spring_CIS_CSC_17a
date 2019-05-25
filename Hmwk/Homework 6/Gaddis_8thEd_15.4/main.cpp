#include <iostream>
#include <Time.h>

using namespace std;

class MilTime : public Time {

};

int main(int argc, char** argv) {
    
    time_t seconds;
    seconds = time(NULL);
    
    cout << seconds;
    
    return 0;
}

