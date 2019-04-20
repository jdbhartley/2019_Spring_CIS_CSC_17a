#include <iostream>
#include <iomanip>

using namespace std;
struct month {
    string name;
    float rain, hTemp, lTemp, avgTemp;
};

int main(){
    month months[12];
    
    //Get Data
	for (int i = 0; i < 12; i++) {
	    cin >> months[i].name;
	    cin >> months[i].rain;
	    cin >> months[i].lTemp;
	    cin >> months[i].hTemp;
	    months[i].avgTemp = (months[i].hTemp + months[i].lTemp) / 2;
	}
	
	float avgRain = 0, avgTemp = 0;
	int lTempIndx = 0, hTempIndx = 0;
	
	//Check Data
	for (int i = 0; i < 12; i++) {
	    avgRain += months[i].rain;
	    avgTemp += months[i].avgTemp;
	    
	    if (months[i].hTemp > months[hTempIndx].hTemp) {
	        hTempIndx = i;
	    } 
	    if (months[i].lTemp < months[lTempIndx].lTemp) {
	        lTempIndx = i;
	    }
	}
	
	avgRain /= 12;
	avgTemp = avgTemp / 12 + 0.5;
	
	avgRain += 0.05;
	
	cout << "Average Rainfall " << fixed << setprecision(1) << avgRain << " inches/month" << endl;
	cout << "Lowest  Temperature " << fixed << setprecision(0) << months[lTempIndx].name << "  " << months[lTempIndx].lTemp << " Degrees Fahrenheit" << endl;
	cout << "Highest Temperature " << months[hTempIndx].name << "  " << months[hTempIndx].hTemp << " Degrees Fahrenheit" << endl;
	cout << "Average Temperature for the year " << avgTemp << " Degrees Fahrenheit" << endl;
	
	return 0;
}