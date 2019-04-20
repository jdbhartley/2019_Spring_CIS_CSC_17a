#include <iostream>
#include <cstdlib>

using namespace std;

struct movie {
    string title, director;
    int year, length;
};

void prntMov(movie[], int);

int main(){
	int numMovie;
	
	//Intro
	cout << "This program reviews structures" << endl;
	cout << "Input how many movies, the Title of the Movie, Director, Year Released, and the Running Time in (minutes)." << endl << endl;
	cin >> numMovie;
	movie movies[numMovie];
	
	for (int i = 0; i < numMovie; i++) {
	    string ignore;
	    getline(cin, ignore);
	    getline(cin, movies[i].title);
	    getline(cin, movies[i].director);
	    cin >> movies[i].year;
	    cin >> movies[i].length;
	}
	
	prntMov(movies, numMovie);
	
	return 0;
}

void prntMov(movie movies[], int numMovie) {
    for (int i = 0; i < numMovie; i++) {
        cout << "Title:     " << movies[i].title << endl;
        cout << "Director:  " << movies[i].director << endl;
        cout << "Year:      " << movies[i].year << endl;
        cout << "Length:    " << movies[i].length << endl;
        i!=numMovie-1?cout << endl:cout << "";
    }
}