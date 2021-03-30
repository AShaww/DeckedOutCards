//
// Created by AmirS on 30/03/2021.
//
#ifndef DECKEDARRAY_DECK_H
#define DECKEDARRAY_DECK_H

#include "../Card/Card.h"
#include "../Deck/Deck.h"

class Deck {
public:
    void initialiseDeck(Deck &);
    void printDeck(Deck&);
    void shuffle(Deck&);
    vector<Card> cards;
};


#endif //DECKEDARRAY_DECK_H
