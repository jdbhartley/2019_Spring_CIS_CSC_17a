#include <iostream>
#include <iomanip>

using namespace std;

struct drink {
    string name;
    int cost, stock;
};

int main(){
    int earnings = 0;
	drink drinks[5];
	drinks[0].name = "Cola"; drinks[0].cost = 75; drinks[0].stock = 20;
	drinks[1].name = "Root Beer"; drinks[1].cost = 75; drinks[1].stock = 20;
	drinks[2].name = "Lemon-Lime"; drinks[2].cost = 75; drinks[2].stock = 20;
	drinks[3].name = "Grape Soda"; drinks[3].cost = 80; drinks[3].stock = 20;
	drinks[4].name = "Cream Soda"; drinks[4].cost = 80; drinks[4].stock = 20;
        
	string input;
	while (input != "Quit") {
	    
	    int money, index;
	    for (int i = 0; i < 5; i++) {
	        cout << setw(11) << left << drinks[i].name << drinks[i].cost << right << setw(4) << drinks[i].stock << endl;
	    }
	    cout << "Quit" << endl;
	    
	    getline(cin, input);
            if (input == "Quit") {
                cout << earnings << endl;
                return 0;
            }
	    cin >> money;
            cin.ignore();
	    
	  for (int i = 0; i < 5; i++) {
	       if (drinks[i].name == input) {
	           index = i;
	       }
	    }
	    
	    if (money > drinks[index].cost) {
	        drinks[index].stock --;
	        cout << money - drinks[index].cost << endl;
	        earnings += drinks[index].cost;
	    }
	}
	
	return 0;
}