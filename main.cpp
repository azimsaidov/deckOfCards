#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

#include "Deck.h"
#include "Card.h"

// Returns true if vector of Cards passed in contains at least 2 Cards with the same rank.
bool hasPair(const vector<Card> &hand);

// Sends to output stream a hand of Cards on a single line, 
// each Card separated by a comma.
// If the vector is empty, do not output anything.
// Example (vector size of 3): Ace of Spades, Two of Hearts, King of Clubs 
ostream & operator<<(ostream &, const vector<Card> &);



int main() {
    srand(2222);
    string output;
    bool outputToFile = false;


    cout << "Do you want to output all hands to a file?(Yes/No) ";
    cin >> output;
    cout << endl;


    if (output == "Yes") {
        outputToFile = true;

        
    }

    ofstream fout;
    if (outputToFile) {
        cout << "Enter name of output file: ";
        cin >> output;
        cout << endl;


        fout.open(output);

        if (!fout.is_open()) {
            cout << "Could not open file " << output << " for writing." << endl;
            return 1;
        }
    }


    Deck theDeck;
    theDeck.shuffleDeck();

    cout << "Enter number of cards per hand: ";
    int numCards;
    cin >> numCards;
    cout << endl;

    cout << "Enter number of deals (simulations): ";
    int numDeals;
    cin >> numDeals;
    cout << endl;


    //now we have theDeck, numCards, numDeals, and fout (if it is open for writing)
    //shuffle the deck, deal out numCards per hand for numDeals, and check each hand for a pair

    int numPairs = 0;

    for (int i = 0; i < numDeals; i++) {
        vector<Card> hand;
        for (int j = 0; j < numCards; j++) {
            hand.push_back(theDeck.dealCard());
        }
        //if it is a file
        if (outputToFile) {
            if (hasPair(hand)) {
                fout <<"Found Pair!! ";
                fout << hand;
                numPairs++;

            }
            else {
                fout << "             ";
                fout << hand;
            }

        }
        //if it is not a file
        else {
            if (hasPair(hand)) {
            numPairs++;
        }
            

        }
        if (outputToFile) {
            fout << endl;
        }
       
        theDeck.shuffleDeck();
    }

    double chance = (double) numPairs / numDeals;
    chance *= 100;
    cout << "Chances of receiving a pair in a hand of " << numCards << " cards is: " << chance << "%" << endl;





    return 0;
}


bool hasPair(const vector<Card> &hand) {
    for (unsigned int i = 0; i < hand.size(); i++) {
        for (unsigned int j = i + 1; j < hand.size(); j++) {
            if (hand.at(i).getRank() == hand.at(j).getRank()) {
                return true;
            }
        }
    }
    return false;
}

ostream & operator<<(ostream &out, const vector<Card> &hand) {
    if (hand.size() == 0) {
        return out;
    }
    for (unsigned int i = 0; i < hand.size() - 1; i++) {
        out << hand.at(i) << ", ";
    }
    out << hand.at(hand.size() - 1);
    return out;
}