/* 
 * Purpose:  Searching for multiple occurrence of patterns
 * Note:  cout proceeds to null terminator, cin reads to end of line
 *        for character arrays
 * 
 */

//System Libraries Here
#include <iostream>//cin,cout,getline()
#include <cstring> //strlen()
#include <vector>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//PI, e, Gravity, or conversions

//Function Prototypes Begins Here
//srch1 utility function Input->start position, Output->position found or not
//srch1 is a simple linear search function, repeat in srchAll till all found
//srch1 Input->sentence, pattern, start position Output-> position found
//Remember arrays start at index/position 0
//srchAll Input->sentence, pattern Output->position array
vector<int>  srch1(const char [],const char []);//Search for 1 occurrence
void srchAll(const char [],const char [],int []);//Search for all occurrences
void print(const char []);//Print the character arrays
void print(const vector<int>); //Print the array of indexes where the pattern found

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int LINE=81;               //Size of sentence or pattern to find
    char sntnce[LINE],pattern[LINE]; //80 + null terminator
    int match[LINE];                 //Index array where pattern was found
    vector<int> positions;          //Vector for positions matched.
    
    //Input a sentence and a pattern to match
    cout<<"Match a pattern in a sentence."<<endl;
    cout<<"Input a sentence"<<endl;
    cin.getline(sntnce,LINE);
    cout<<"Input a pattern."<<endl;
    cin.getline(pattern,LINE);
    
    //Search for the pattern
    //Input the sentence and pattern, Output the matching positions
    //Remember, indexing starts at 0 for arrays.
    positions = srch1(sntnce, pattern);
    //srchAll(sntnce,pattern,match);
    
    //Display the inputs and the Outputs
    cout<<endl<<"The sentence and the pattern"<<endl;
    print(sntnce);
    print(pattern);
    cout<<"The positions where the pattern matched"<<endl;
    if (positions.size() == 0) {
        cout << "None" << endl;
    }
    else {
      print(positions);  
    }
    
    
    //Exit
    return 0;
}

vector<int> srch1(const char sentance[],const char pattern[]) { //Search for 1 occurrence
    int tmpMatch = 0;
    vector<int> pos;
    
    for (int i = 0; i < strlen(sentance); i++) { //We found first occurence.
        if (sentance[i] == pattern[0]) { //Now to check if the rest the chars match with the pattern
            for (int j = 0; j < strlen(pattern); j++) {
                if (sentance[i+j] != pattern[j]) {
                    
                }
                else {
                    tmpMatch = i;
                    if (pos.size() == 0) {
                        pos.push_back(tmpMatch);

                    }
                    else if (pos[pos.size()-1] != tmpMatch) {
                        pos.push_back(tmpMatch);

                    }
                }
            }
        }
    }

    return pos;
} 
void srchAll(const char sentance[],const char pattern[],int matches[]) { //Search for all occurrences
    
}
void print(const char a[]) { //Print the character arrays
    for (int i = 0; i < strlen(a); i++) {
        cout << a[i];
    }
    cout << endl;
}
void print(const vector<int> ia) { //Print the array of indexes where the pattern found
    for (int i = 0; i <= ia.size()-1; i++) {
        cout << ia[i] << endl;
    }
} 