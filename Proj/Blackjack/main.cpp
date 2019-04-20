/* 
 * Program: Black Jack
 * Author: James Hartley
 * Created on April 3, 2019, 1:08 PM
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

//Other consts
const char MAXNMSZ = 50;
const string SAVEFILE = "save.dat";

//struct that represents a card
struct card {
    char suit;
    char val;
};

//Holds player name and money, used for saving binary file.
struct player {
    char name[MAXNMSZ];
    float money;
};

//Hand structure stores number of cards drawn, hand value
//and holds dynamic array of cards
struct hand {
    int numCrds = 0;
    int sumVal = 0;
    card* cards;
};


//Prototypes
void InitDeck(card[DECKSIZE]);
void PrintDeck(card[DECKSIZE]);
bool CheckForSave(string);
player LoadGame(string, player);
void SaveGame(string, player);
void Draw(card[DECKSIZE], int &, hand&);
void Draw(card[DECKSIZE], int &, hand&, int);
void PrintCard(card);
void PrintHand(hand);
void AddCard(hand&, card);
void CalcVal(hand&);

int main(int argc, char** argv) {
    card deck[DECKSIZE];    //Our deck is an array of cards.
    char menuSel;           //Menu Selection
    bool play;              //Boolean for game is active
    bool bnkrSty = false;   //Does banker stay?
    bool plyrSty = false;   //Does player stay?
    player plyr;            //Holds player information
    int usdIndx = 0;        //Number of cards drawn, used for index.
    float betAmt = 0;       //Amount betting.

    hand plyrHnd, bnkrHnd;  //Player and Banker hands


    //Random seed
    srand(time(NULL));

    //Initialize Deck
    InitDeck(deck);

    //Shuffle Deck with Algorithm
    random_shuffle(deck, deck + DECKSIZE);

    //Print Deck
    PrintDeck(deck);

    //Intro
    cout << "*******************************" << endl;
    cout << "****       Black Jack      ****" << endl;
    cout << "****     The Card Game     ****" << endl;
    cout << "****          By           ****" << endl;
    cout << "****     James Hartley     ****" << endl;
    cout << "*******************************" << endl;
    cout << "         -------------         " << endl;

    //Display Menu
    cout << setfill('.');
    cout << "P" << setw(30) << "Play" << endl;
    cout << "E" << setw(30) << "Exit" << endl;
    cout << "Please input a selection..." << endl;
    cin >> menuSel;
    //Check menu selection
    switch (toupper(menuSel)) {
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
                //Draw a card
                Draw(deck, usdIndx, plyrHnd, 2);
                Draw(deck, usdIndx, bnkrHnd, 2);
                cout << "Player Hand: " << endl;
                PrintHand(plyrHnd);
                cout << endl;
                cout << "Banker Hand: " << endl;
                PrintHand(bnkrHnd);
                cout << endl;

                //Main game loop.
                while (plyrHnd.sumVal < 21 && bnkrHnd.sumVal < 21 && !bnkrSty) {
                    if (!plyrSty) {
                        cout << "Enter H to hit or S to stay" << endl;
                        cin >> menuSel;
                    }
                    if (toupper(menuSel) == 'H') {
                        Draw(deck, usdIndx, plyrHnd);
                        cout << plyr.name << "'s Hand" << endl;
                        PrintHand(plyrHnd);
                        cout << endl;
                    }
                    else {
                        plyrSty = true;
                        if (bnkrHnd.sumVal < 16) {
                            Draw(deck, usdIndx, bnkrHnd);
                            cout << "Banker's Hand:" << endl;
                            PrintHand(bnkrHnd);
                            cout << endl;
                        } else {
                            bnkrSty = true;
                        }
                    }
                }
                
                //Check if won, pushed, or busted.
                if (plyrHnd.sumVal == 21) {
                    cout << endl << plyr.name << " got a Blackjack!" << endl;
                    cout << "Won $" << fixed << setprecision(2) << betAmt * 2;
                    plyr.money += (betAmt * 2);
                } else if (bnkrHnd.sumVal == 21) {
                    cout << endl << "Banker got a Blackjack!" << endl;
                } else if (plyrHnd.sumVal > 21) {
                    cout << endl << "Player BUST" << endl;
                } else if (bnkrHnd.sumVal > 21) {
                    cout << endl << "Banker BUST" << endl;
                    cout << "Won $" << fixed << setprecision(2) << betAmt * 2;
                    plyr.money += (betAmt * 2);
                } else if (plyrHnd.sumVal > bnkrHnd.sumVal) {
                    cout << endl << plyr.name << " Wins!" << endl;
                    cout << "Won $" << fixed << setprecision(2) << betAmt * 2;
                    plyr.money += (betAmt * 2);
                } else if (plyrHnd.sumVal == bnkrHnd.sumVal) {
                    cout << "Push!" << endl;
                    plyr.money += betAmt;
                }else {
                    cout << endl << "Banker Wins!" << endl;
                }


                //Ask to play again
                if (plyr.money > 0) {
                    cout << endl << "Play Again? (Y or N) ";
                } else {
                    cout << endl << "Game Over! You ran out of money.";
                    cout << endl << "Would you like to restart?";
                }

                cin >> menuSel;
                if (toupper(menuSel) == 'N') {
                    play = false;
                    SaveGame(SAVEFILE, plyr);
                } else {
                    //Reset
                    plyr.money<=0?plyr.money=1000:0;
                    delete[] plyrHnd.cards;
                    delete[] bnkrHnd.cards;
                    plyrHnd.numCrds = 0;
                    bnkrHnd.numCrds = 0;
                    plyrHnd.sumVal = 0;
                    bnkrHnd.sumVal = 0;
                    betAmt = 0;
                    plyrSty = bnkrSty = false;
                    //Shuffle Deck with Algorithm
                    random_shuffle(deck, deck + DECKSIZE);
                    usdIndx = 0;
                }
            }
            break;
        case 'E':
            //Exit
            cout << "Goodbye!";
            break;
        default:
            //Exit
            cout << "Goodbye!";
            break;
    }

    return 0;
}

//Draw a single card from the deck.
void Draw(card deck[DECKSIZE], int& usdIndx, hand& hnd) {
    int Indx = usdIndx;

    if (usdIndx == DECKSIZE) {
        cout << endl << "OUT OF CARDS" << endl;
    }

    usdIndx++;
    AddCard(hnd, deck[Indx]);
}

//Draw multiple cards from the deck.
void Draw(card deck[DECKSIZE], int& usdIndx, hand& hnd, int addNum) {
    for (int i = 0; i < addNum; i++) {
        Draw(deck, usdIndx, hnd);
    }
}

//Add a card to the hand
void AddCard(hand& hnd, card crd) {
    //Check if there are cards in hand
    if (hnd.numCrds == 0) {
        hnd.cards = new card[1];
        hnd.cards[0] = crd;
        hnd.numCrds++;
    } else {
        hnd.numCrds++;
        card* tmpHnd = new card[hnd.numCrds];

        for (int i = 0; i < hnd.numCrds - 1; i++) {
            tmpHnd[i] = hnd.cards[i];
        }

        tmpHnd[hnd.numCrds - 1] = crd;

        delete[] hnd.cards;
        hnd.cards = new card[hnd.numCrds];
        memcpy(hnd.cards, tmpHnd, sizeof (card) * hnd.numCrds);
        delete[] tmpHnd;
    }

    CalcVal(hnd);
}

//Calculate hand value.
void CalcVal(hand& hnd) {
    int sum = 0;
    for (int i = 0; i < hnd.numCrds; i++) {
        hnd.cards[i].val > 10 ? sum += 10 : sum += hnd.cards[i].val;
    }

    hnd.sumVal = sum;
}

//Initializes deck
void InitDeck(card deck[DECKSIZE]) {
    for (char i = 0; i < SUITS; i++) {
        for (char j = 0; j < DECKSIZE / SUITS; j++) {
            char index = j + (i * 13);
            deck[index].suit = i;
            deck[index].val = j + 2;
        }
    }
}

//Prints a single card.
void PrintCard(card thsCard) {
    string suit, value;
    switch (thsCard.suit) {
        case 0:
            suit = "Hearts";
            break;
        case 1:
            suit = "Spades";
            break;
        case 2:
            suit = "Clubs";
            break;
        case 3:
            suit = "Diamonds";
            break;
    }
    switch (thsCard.val) {
        case 11:
            value = "Jack";
            break;
        case 12:
            value = "Queen";
            break;
        case 13:
            value = "King";
            break;
        case 14:
            value = "Ace";
            break;
        default:
            value = to_string(thsCard.val);
            break;
    }

    cout << value << " of " << suit << endl;
}

//Prints entire hand
void PrintHand(hand hnd) {
    for (int i = 0; i < hnd.numCrds; i++) {
        PrintCard(hnd.cards[i]);
    }
    cout << "Value: " << hnd.sumVal << endl;
}

//Prints entire deck
void PrintDeck(card deck[DECKSIZE]) {
    for (char i = 0; i < DECKSIZE; i++) {
        PrintCard(deck[i]);
    }
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

