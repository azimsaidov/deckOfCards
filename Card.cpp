#include <iostream>
#include <string>
using namespace std;
#include "Card.h"

// char suit 
// int rank

Card::Card() {
    rank = 2;
    suit = 'c';
}

Card::Card(char s, int r) {
    suit = tolower(s);
    rank = r;

}

char Card::getSuit() const {

    return suit;
}

int Card::getRank() const {
    return rank;
}

ostream & operator<<(ostream &out, const Card &card) {
    string rank, suit;
     /* Outputs a Card in the following format: Rank of Suit
       For example, if the rank is 3 and the suit is h: 3 of Hearts
       Or, if the rank is 1 and the suit is d: Ace of Diamonds
       Or, if the rank is 12 and the suit is c: Queen of Clubs
       etc.
    */

    // Convert the rank and suit to strings
    switch (card.getRank()) {
        case 1:
            rank = "Ace";
            break;
        case 11:
            rank = "Jack";
            break;
        case 12:
            rank = "Queen";
            break;
        case 13:
            rank = "King";
            break;
        default:
            rank = to_string(card.getRank());
            break;
    }
    switch (card.getSuit()) {
        case 'h':
            suit = "Hearts";
            break;
        case 'd':
            suit = "Diamonds";
            break;
        case 'c':
            suit = "Clubs";
            break;
        case 's':
            suit = "Spades";
            break;
    }

    // Output the rank and suit to the output stream
    out << rank << " of " << suit;

    return out;
}