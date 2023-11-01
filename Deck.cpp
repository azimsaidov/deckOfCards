#include <iostream>
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>    // std::random_shuffle
using namespace std;

#include "Deck.h"

//vector card theDeck
//vector card dealtCards

Deck::Deck() {
    vector<char> suitLib(4);

    suitLib.at(0) = 's';
    suitLib.at(1) = 'h';
    suitLib.at(2) = 'd';
    suitLib.at(3) = 'c';

    for (int i = 0; i < 4; i++) {
        for (int j = 13; j > 0; j--) {
            Card newCard(suitLib.at(i), j);
            theDeck.push_back(newCard);
        }
    }
}

Card Deck::dealCard() {
    Card topCard = theDeck.back();
    dealtCards.push_back(topCard);
    theDeck.pop_back();
    return topCard;
}

void Deck::shuffleDeck(){
    //theDeck.insert(theDeck.end(), dealtCards.begin(), dealtCards.end());
    for (unsigned int i = 0; i < dealtCards.size(); i++) {
        theDeck.push_back(dealtCards.at(i));
    }
    dealtCards.clear();

    /*std:: random_device rd;
    std::mt19937 gen(2222);
    std::shuffle(theDeck.begin(), theDeck.end(), rd);
    */

    random_shuffle(theDeck.begin(), theDeck.end());

}

unsigned Deck::deckSize() const {
    return theDeck.size();
}




