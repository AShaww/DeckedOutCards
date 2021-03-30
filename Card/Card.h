//
// Created by AmirS on 30/03/2021.
//

#ifndef DECKEDARRAY_CARD_H
#define DECKEDARRAY_CARD_H

#include <iostream>
#include <vector>

using namespace std;
enum Rank {
    ACE=1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
};

enum Suit {
    HEARTS, DIAMONDS, SPADES, CLUBS
};

class Card{

public:
//    int getValue() const;

    int getNumOfRank() const{
        return num_rank;
    }
    int getNumOfSuit() const{
        return num_suit;
    }
    static void printCard(Card&);
    static void printHand(const vector<Card>&);
    Rank rank;
    Suit suit;
private:
    int num_rank = 14;
    int num_suit = 4;
};

//
//int Card::getValue() const {
//    //if a cards is face down, its value is 0
//    int value = 0;
//    if (true)
//    {
//        //value is number showing on card
//        value = rank;
//        // value is 10 for face cards
//        if (value > 10)
//            value = 10;
//    }
//    return value;
//}

#endif //DECKEDARRAY_CARD_H
