//
// Created by AmirS on 30/03/2021.
//
#include "Card.h"

void Card::printCard(Card &card) {
    if (card.rank >= 0 && card.rank < card.num_rank) {
        switch (card.rank) {
            case ACE:
                printf("%s of ", " ACE");
                break;
            case TWO:
                printf("%s of ", " TWO");
                break;
            case THREE:
                printf("%s of ", " THREE");
                break;
            case FOUR:
                printf("%s of ", " FOUR");
                break;
            case FIVE:
                printf("%s of ", " FIVE");
                break;
            case SIX:
                printf("%s of ", " SIX");
                break;
            case SEVEN:
                printf("%s of ", " SEVEN");
                break;
            case EIGHT:
                printf("%s of ", " EIGHT");
                break;
            case NINE:
                printf("%s of ", " NINE");
                break;
            case TEN:
                printf("%s of ", " TEN");
                break;
            case JACK:
                printf("%s of ", " JACK");
                break;
            case QUEEN:
                printf("%s of ", " QUEEN");
                break;
            case KING:
                printf("%s of ", " KING");
                break;
        }
    }
    switch (card.suit) {
        case HEARTS:
            puts("HEARTS");
            break;
        case SPADES:
            puts("SPADES");
            break;
        case DIAMONDS:
            puts("DIAMOND");
            break;
        case CLUBS:
            puts("CLUBS");
            break;
    }
}

void Card::printHand(const vector<Card>& hand){
    for(Card c : hand){
        Card::printCard(c);
    }
}
