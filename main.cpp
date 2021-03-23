#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

enum Rank {
    ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
};
enum Suit {
    HEARTS, DIAMONDS, SPADES, CLUBS
};

struct Card {   //Own data type of Card
    Rank rank;
    Suit suit;
    int num_suits = 4;
    int num_rank = 13;
};

struct Deck {
    vector<Card> cards;
};

struct Player{
    vector<Card> hand;
    string * name;
    int score;
};

struct Game{
    vector<Player> players;
    Deck deck;
    int numOfPlayers = 2;
    int numCardPerHand = 7;
};

void initialiseComponent(Deck&);

void printCard(const Card&);
void printHand(const vector<Card>&);   //Consted - not changing the hand in the function.

void shuffle(Deck&);
void printDeck(const Deck&);

void initialiseGame(Game&);
void addPlayer(Game&);
void dealCards(Game&);
void printGame(const Game&);

int main() {
    Game game;
    initialiseGame(game);
    dealCards(game);
    printGame(game);
}

void initialiseComponent(Deck& deck) {
    Card card;
    for (int suit = 0; suit < card.num_suits; suit++) {
        for (int rank = 0; rank < card.num_rank; rank++) {
            card.suit = Suit(suit); //(Suit/Rank is casted from ENUM type (changes int into value of enum))
            card.rank = Rank(rank);
            deck.cards.push_back(card); //Declaring a new card and adding it to the deck
        }
    }
}

void printDeck(const Deck& deck) {
    for (Card c : deck.cards)
    {
        printCard(c);
    }
}

void printCard(const Card& card) {
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

void shuffle(Deck& deck) {
    Deck shuffled;
    while (!deck.cards.empty()) {
        srand(time(NULL));
        size_t random = rand() % deck.cards.size();
        srand(1);
        shuffled.cards.push_back(deck.cards[random]);
        deck.cards.erase(deck.cards.begin() + random);
    }
    deck = shuffled;
}

void dealCards(Game& game) {
    for (int card = 0; card < game.numCardPerHand; card++) {
        for (int player = 0; player < game.numOfPlayers; player++){
            game.players[player].hand.push_back(game.deck.cards[0]);
            game.deck.cards.erase(game.deck.cards.begin());
        }
    }
}

void printHand(const vector<Card>& hand) {
    for (Card c : hand) {
        printCard(c);
    }
}

void initialiseGame(Game& game){
    initialiseComponent(game.deck);
    shuffle(game.deck);
    addPlayer(game);
}

void addPlayer(Game& game){
    for (int player = 0; player < game.numOfPlayers; player++){
        Player newPlayer;
        game.players.push_back(newPlayer);
    }
}

void printGame(const Game& game){
    for(int player = 0; player < game.numOfPlayers; player++) {
        printHand(game.players[player].hand);
        cout << '\n';
    }
    printDeck(game.deck);
}
