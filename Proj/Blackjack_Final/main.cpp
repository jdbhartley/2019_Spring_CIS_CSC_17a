/* 
 * Program: Black Jack
 * Author: James Hartley
 * Created on May 5, 2019, 11:07 PM
 */

#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>

using namespace std;

//Deck constants
const char DECKSIZE = 52;
const char SUITS = 4;

//Const's for Suits
const char HEART = 0;
const char SPADE = 1;
const char CLUB = 2;
const char DIAMOND = 3;

//suit char's unicode
const wchar_t heart[] = L"\u2665";
const wchar_t spade[] = L"\u2660";
const wchar_t clubs[] = L"\u2663";
const wchar_t diamond[] = L"\u2666";

//Other consts
const char MAXNMSZ = 50;
const string SAVEFILE = "save.dat";
//Card class, stores values for our card.

//Holds player name and money, used for saving binary file.
struct player {
    char name[MAXNMSZ];
    float money;
};

template <typename T>
void AddMoney(T amt, player& plyr) {
    plyr.money += amt;
}

//Prototypes
//This function checks if there is a savegame file already
bool CheckForSave(string);

//This function loads the savegame file
player LoadGame(string, player);

//This function saves the game.
void SaveGame(string, player);

//Clears the console. works on unix and windows 10+
void ClearConsole();

//Classes
//This class is a virtual class for inheritance
//requires other classes to implement a print function.
class Printable {
public:
    virtual void Print() = 0;
};

class Card : public Printable {
private:
    char suit;
    char val;
    string desc;
    string asciiSuit;
    string asciiVal;

    void setDesc() {
        //This switch checks value and suit and converts it 
        //into a string description of the card.
        string strSuit, strVal;
        switch (suit) {
            case 0:
                strSuit = "Hearts";
                asciiSuit = "♥";
                break;
            case 1:
                strSuit = "Spades";
                asciiSuit = "♠";
                break;
            case 2:
                strSuit = "Clubs";
                asciiSuit = "♣";
                break;
            case 3:
                strSuit = "Diamonds";
                asciiSuit = "◆";
                break;
        }
        switch (val) {
            case 11:
                strVal = "Jack";
                asciiVal = "J";
                break;
            case 12:
                strVal = "Queen";
                asciiVal = "Q";
                break;
            case 13:
                strVal = "King";
                asciiVal = "K";
                break;
            case 14:
                strVal = "Ace";
                asciiVal = "A";
                break;
            default:
                strVal = to_string(val);
                asciiVal = to_string(val);
                break;
        }
        desc = strVal + " of " + strSuit;
    }

public:
    //This sets the value of the card

    void SetCard(char vl, char st) {
        val = vl;
        suit = st;

        //Set the description from the value.
        setDesc();
    }

    char GetVal() {
        return val;
    }
    
    string GetASCIISuit() {
        return asciiSuit;
    }
    
    string GetASCIIVal() {
        return asciiVal;
    }

    //Prints card description to the screen.

    void Print() {
        cout << desc << endl;
    }
    
    void PrintASCII() {
        //Stores value in string format
        string strVal;
        
        //Check val and assign proper character.
        switch (val) {
            case 11:
                strVal = "J";
                break;
            case 12:
                strVal = "Q";
                break;
            case 13:
                strVal = "K";
                break;
            case 14:
                strVal = "A";
                break;
            default:
                strVal = to_string(val);
                break;
        }
        
        //Print out the card ASCII art.
        cout << " ____ " << endl;
        cout << "|" << strVal; // << "   |" << endl;
        val == 10 ? cout << "  |" << endl : cout << "   |" << endl;
        cout << "| " << asciiSuit << " |" << endl;
        val == 10 ? cout << "|__" : cout << "|___"; 
        cout << strVal << "|" << endl;
    }
};

//Our deck class. holds an array of cards.

class Deck : public Printable {
private:
    Card cards[DECKSIZE];
    int nDrawn = -1;

public:

    Deck() {
        //Initializes deck, does a loop through suits and sets value/suit combo
        for (char i = 0; i < SUITS; i++) {
            for (char j = 0; j < DECKSIZE / SUITS; j++) {
                char index = j + (i * 13);
                cards[index].SetCard(j + 2, i);
            }
        }
        
        Shuffle();
    }

    //Loops through cards and prints to the screen.

    void Print() {
        for (char i = 0; i < DECKSIZE; i++) {
            cards[i].Print();
        }
    }

    //Uses Algorithm to shuffle deck

    void Shuffle() {
        random_shuffle(cards, cards + DECKSIZE);
    }
    
    //Returns a card from the deck, keeps track of total
    //Number of drawn cards.
    Card Draw() {
        if (nDrawn < DECKSIZE) {
            nDrawn++;
            return cards[nDrawn];
        }
        else {
            //Out of cards, shuffle and reset drawn amount
            nDrawn = 0;
            Shuffle();
            return cards[nDrawn];
        }
    }
    
    void Reset() {
        //Set number of drawn to -1 then shuffle the deck.
        nDrawn = -1;
        Shuffle();
    }
};

class Hand : public Printable {
private:
    int numCrds = 0;
    int val = 0;
    Card* cards;

    void CalcVal() {
        int sum = 0;

        //Loop through our cards and get the value of the cards.
        for (int i = 0; i < numCrds; i++) {
            cards[i].GetVal() > 10 ? sum += 10 : sum += cards[i].GetVal();
        }

        val = sum;
    }

public:
    
    //~Hand() {
    //    delete[] cards;
    //}

    void AddCard(Card crd) {
        //Check if there are cards in hand
        if (numCrds == 0) {
            //If theres no cards in hand make our dynamic array 1
            //And add the supplied card to the hand
            cards = new Card[1];
            cards[0] = crd;
            numCrds++;
        } else {
            //Increment number of cards held and re-create cards array
            //with the new value
            numCrds++;

            //Using temporary array which will be deleted.
            Card* tmpHnd = new Card[numCrds];

            //Loop through ignoring the last index and add the old cards to the temp
            //array
            for (int i = 0; i < numCrds - 1; i++) {
                tmpHnd[i] = cards[i];
            }

            //add the given card to the end of the array
            tmpHnd[numCrds - 1] = crd;

            //delete our old array
            delete[] cards;

            //create new array using new value
            cards = new Card[numCrds];

            //copy tmpHand to our main array
            for (int i = 0; i < numCrds; i++) {
                cards[i] = tmpHnd[i];
            }

            //Clear the old array from memory
            delete[] tmpHnd;
        }

        CalcVal();
    }

    //Returns our hand value.

    int GetVal() {
        return val;
    }

    //Prints out the entirety of our hand

    void Print() {
        for (int i = 0; i < numCrds; i++) {
            cards[i].Print();
        }
    }

    void PrintASCII() {
        //Print out the card ASCII art.
        for (int i = 0; i < numCrds; i++) {
           cout << " ____ ";
           cout << "      ";
        }
        cout << endl;
        
        for (int i = 0; i < numCrds; i++) {
            cout << "|" << cards[i].GetASCIIVal();
            cards[i].GetVal() == 10 ? cout << "  |" : cout << "   |";
            cout << "      ";
        }
        cout << endl;
        
        for (int i = 0; i < numCrds; i++) {
           cout << "| " << cards[i].GetASCIISuit() << " |";
           cout << "      ";
        }
        cout << endl;
        
        for (int i = 0; i < numCrds; i++) {
            cards[i].GetVal() == 10 ? cout << "|__" : cout << "|___";
            cout << cards[i].GetASCIIVal() << "|";
            cout << "      ";
        }
        cout << endl;
    }
    
    void Reset() {
        numCrds = 0;
        delete[] cards;
    }
};


//Main Function
int main(int argc, char** argv) {
    //Initialize deck
    Deck deck;
    
    //Char storing selected menu option
    char menuSel;
    
    //Boolean to check if were still playing
    bool play;
    
    //Does banker stay?
    bool bnkrSty = false; 
    
    //Does player stay?wow 
   bool plyrSty = false; 
    
    //Holds player information for saving purposes
    player plyr; 
    
    //Amount betting.
    float betAmt = 0; 

    //Hand for the player
    Hand plyrHnd;
    
    //Hand for the banker
    Hand bnkrHnd;

    //Random seed
    srand(time(NULL));

    //Intro
    cout << "*******************************" << endl;
    cout << "****       Black Jack      ****" << endl;
    cout << "****     The Card Game     ****" << endl;
    cout << "****          By           ****" << endl;
    cout << "****     James Hartley     ****" << endl;
    cout << "*******************************" << endl;
    cout << "         -------------         " << endl;

    //Display Menu
    while (menuSel != 'E') {
    cout << setfill('.');
    cout << "P" << setw(30) << "Play" << endl;
    cout << "E" << setw(30) << "Exit" << endl;
    cout << "T" << setw(30) << "Test" << endl;
    cout << "Please input a selection..." << endl;
    
    cin >> menuSel;
    //Check menu selection
    switch (toupper(menuSel)) {
        case 'T':
        {
            cout << plyr.money;
            AddMoney(100, plyr);
            cout << plyr.money;
            break;
        }
        case 'P':
            play = true;
            cout << fixed << setprecision(2);
            //Check if we have a valid save file
            if (CheckForSave(SAVEFILE)) {
                plyr = LoadGame(SAVEFILE, plyr);
                cout << "Welcome Back " << plyr.name << " you have " << plyr.money << " dollars" << endl;
            } else {
                //Get player name and create save file.
                cout << "Please enter your name: ";
                cin >> plyr.name;
                plyr.money = 1000;
                cout << "Current Money = " << plyr.money << endl;
                SaveGame(SAVEFILE, plyr);
            }

            while (play) {
                //Play the game
                cout << "You have $" << plyr.money << endl;
                cout << "Please enter your bet: ";
                cin >> betAmt;
                plyr.money -= betAmt;
                
                //Draw initial two cards for player
                plyrHnd.AddCard(deck.Draw());
                plyrHnd.AddCard(deck.Draw());
                
                //Draw initial two cards for banker
                bnkrHnd.AddCard(deck.Draw());
                bnkrHnd.AddCard(deck.Draw());

                //Display player hand
                cout << "Player Hand: " << endl;
                plyrHnd.PrintASCII();
                
                //Space it out
                cout << endl << endl;
                
                //Display banker hand
                cout << "Banker Hand: " << endl;
                bnkrHnd.PrintASCII();

                //Main game loop, keep going till someone busts or hits 21
                while (plyrHnd.GetVal() < 21 && bnkrHnd.GetVal() < 21 && !bnkrSty) {
                    
                    //If player is not staying ask if they would like to hit or stay
                    if (!plyrSty) {
                        cout << "Enter H to hit or S to stay" << endl;
                        cin >> menuSel;
                    }
                    
                    //Check the players selection, H=hit S=stay
                    if (toupper(menuSel) == 'H') 
                    {
            
                        //If we are hitting, draw another card
                        plyrHnd.AddCard(deck.Draw());
                        
                        //Display the players hand
                        cout << plyr.name << "'s Hand" << endl;
                        plyrHnd.Print();
                    } 
                    //Player picked stay
                    else 
                    {
                        plyrSty = true;
                        
                        //Perform banker AI. if were under 16 value then
                        //draw another card.
                        if (bnkrHnd.GetVal() < 16) {
                            bnkrHnd.AddCard(deck.Draw());
                            
                            //Display the bankers hand
                            cout << "Banker's Hand:" << endl;
                            bnkrHnd.Print();
                        } 
                        else 
                        {
                            //Banker is above 16, so we stay.
                            bnkrSty = true;
                        }
                    }
                }

                //Check if won, pushed, or busted.
                if (plyrHnd.GetVal() == 21) 
                {
                    //We got a blackjack
                    cout << endl << plyr.name << " got a Blackjack!" << endl;
                    
                    //Win money
                    cout << "Won $" << fixed << setprecision(2) << betAmt * 2;
                    plyr.money += (betAmt * 2);
                } 
                else if (bnkrHnd.GetVal() == 21) 
                {
                    //Banker got a blackjack
                    cout << endl << "Banker got a Blackjack!" << endl;
                } 
                else if (plyrHnd.GetVal() > 21) 
                {
                    //Player busts
                    cout << endl << "Player BUST" << endl;
                }
                else if (bnkrHnd.GetVal() > 21) 
                {
                    //Banker busts
                    cout << endl << "Banker BUST" << endl;
                    
                    //Win money
                    cout << "Won $" << fixed << setprecision(2) << betAmt * 2;
                    plyr.money += (betAmt * 2);
                } 
                else if (plyrHnd.GetVal() > bnkrHnd.GetVal()) 
                {
                    //Player wins with higher hand value
                    cout << endl << plyr.name << " Wins!" << endl;
                    
                    //Win money
                    cout << "Won $" << fixed << setprecision(2) << betAmt * 2;
                    plyr.money += (betAmt * 2);
                } 
                else if (plyrHnd.GetVal() == bnkrHnd.GetVal()) 
                {
                    //Player and Banker ties.
                    cout << "Push!" << endl;
                    
                    //Add back betted amount
                    plyr.money += betAmt;
                } 
                else 
                {
                    //Banker wins.
                    cout << endl << "Banker Wins!" << endl;
                }


                //Ask to play again
                if (plyr.money > 0) 
                {
                    //If we still have money we can play again.
                    cout << endl << "Play Again? (Y or N) ";
                } 
                else 
                {
                    //You ran out of money.
                    cout << endl << "Game Over! You ran out of money.";
                    cout << endl << "Would you like to restart?";
                }

                //Get selection, either play again or reset
                cin >> menuSel;
                
                if (toupper(menuSel) == 'N') 
                {
                    //Set play to false to exit loop
                    play = false;
                    
                    //Save the game
                    SaveGame(SAVEFILE, plyr);
                } 
                else 
                {
                    //Reset. if player money is less than 0 set to 1000.
                    plyr.money <= 0 ? plyr.money = 1000 : 0;
                    
                    //Reset deck
                    deck.Reset();
                    
                    //Reset player and banker hands
                    plyrHnd.Reset();
                    bnkrHnd.Reset();
                            
                    //Set bet amount to 0
                    betAmt = 0;
                    
                    //Set banker and player stay bools to false
                    plyrSty = false;
                    bnkrSty = false;
                }
            }
            break;
        case 'E':
            //Exit
            cout << "Goodbye!";
            return 0;
        default:
            //Exit
            cout << "Goodbye!";
            return 0;
            break;
    }
    }

    return 0;
}

//Save player struct to binary file.
void SaveGame(string fileName, player plyr) {
    fstream fileObject;
    fileObject.open(fileName, ios::out | ios::binary);
    fileObject.write(reinterpret_cast<char *> (&plyr), sizeof (player));
    fileObject.close();
}

bool CheckForSave(string fileName) {
    ifstream myFile(fileName);
    if (myFile.fail()) {
        //File does not exist code here
        return false;
    } else {
        return true;
    }
}

player LoadGame(string fileName, player plyr) {
    fstream fileObject;
    fileObject.open(fileName, ios::in | ios::binary);
    fileObject.read(reinterpret_cast<char *> (&plyr), sizeof (player));
    fileObject.close();

    return plyr;
}

void ClearConsole() {
    //Clears the console.
    printf("\033c");
}

