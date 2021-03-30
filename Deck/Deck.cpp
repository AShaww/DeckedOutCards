//
// Created by AmirS on 30/03/2021.
//
#include "Deck.h"

#include <random>

void Deck::initialiseDeck(Deck &deck) {
    Card card;
    for (int suit = 0; suit < card.getNumOfSuit(); suit++) {
        for (int rank = 1; rank < card.getNumOfRank(); rank++) {
            card.suit = Suit(suit); //(Suit/Rank is casted from ENUM type (changes int into value of enum))
            card.rank = Rank(rank);
            deck.cards.push_back(card); //Declaring a new card and adding it to the deck
        }
    }
}
void Deck::printDeck(Deck &deck) {
    for (Card c : deck.cards) {
        Card::printCard(c);
    }
}

void Deck::shuffle(Deck& deck) {
    Deck shuffled;
    while (!deck.cards.empty()){
        srand(time(nullptr));
        size_t rando = rand() % deck.cards.size();
        srand(10);
        shuffled.cards.push_back(deck.cards[rando]);
        deck.cards.erase(deck.cards.begin() + rando);
    }
    deck = shuffled;
}
