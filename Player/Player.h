//
// Created by AmirS on 31/03/2021.
//

#ifndef DECKEDARRAY_PLAYER_H
#define DECKEDARRAY_PLAYER_H

#include "../Card/Card.h"
#include "../Deck/Deck.h"

class Player{

public:
    vector<Card> hand;
    string name;
    int score;

};
#endif //DECKEDARRAY_PLAYER_H
