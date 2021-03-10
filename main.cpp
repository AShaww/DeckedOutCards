/**
 * Simple card game using correct OOP, including Abstraction/Encapsulation.
 * Author: Amir Shaw
 */
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;
/**
 * Decided to go with enum as constants to be used within the game, could have used arrays. Decided to learn and go with enum instead.
 * Can/will change enum to dynamic arrays depending on if not being able to work with them...
 */
enum Rank {
    ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE
};
enum Suit {
    HEARTS, DIAMOND, SPADES, CLUBS
};
/**
 *  ^^^^ Too much work is needed to bring the value of the enum into the string literal of what it is. As i will either need to make a switch of sorts etc.
 *  Might just look at the Moodle examples and see if i can incorporate a dynamic array into this application.
 */


struct Card {
    Rank rank;
    Suit suit;
    int num_suits = 4;
    int num_rank = 13;
};

struct Deck {
    vector<Card> cards;
    string card_back;
};

struct Player {
    vector<Card> hand;
    string name;
    int score;
};

struct Game {
    vector<Player> players;
    Deck deck;
    int num_players = 2;
    int num_of_cards_per_hand = 1;
};

/**
 * Prototypes
 */

void initialiseDeck(Deck &);
void shuffle(Deck &);
void initialiseGame(Game &);
void addPlayer(Game &game);
void dealCards(Game &);
void printCard(const Card &);
void printDeck(const Deck &);
void printHand(const vector<Card> &);
void printGame(const Game &);

void playGame(Game&);

int main() {
    //Gorgeous Main! Nice and clean... :)
    //Everything works so far.
    Game game;
    printGame(game);
    playGame(game);
    // Looking at the main this game will need a 'play function' which the initialise / dealCards / print_game can be abstracted into a play function. This will clean the main up even more!

    //Maybe Work on a initialise such as game object, which calls all of these functions.
    //Will make the main look better, as it will just have a game object called.??? Think about it.
    //Looking inside the main, realising that all above are components of the game, I would like to declare a single variable for the card game to be called.
}

void initialiseDeck(Deck &deck) {
    Card card;
    for( int suit = 0; suit < card.num_suits; suit++ ) {
        for( int rank = 0; rank < card.num_rank; rank++ ) {
            card.suit = Suit(suit); //(Suit/Rank is casted from ENUM type (changes int into value of enum))
            card.rank = Rank(rank);
            deck.cards.push_back(card); //Declaring a new card and adding it to the deck
        }
    }
}

void printDeck(const Deck &deck) {
    for( Card c : deck.cards ) // cards is member of deck. So referred to as cards and not card
    {
        printCard(c);
    }
}

void printCard(const Card &card) {
    cout << "Rank " << card.rank << " of " << "Suit " << card.suit << '\n';     //can i make this a pointer for each card that has been dealt??
}

void shuffle(Deck &deck) {
    Deck shuffled;
    while (!deck.cards.empty()) {   // validation to check if there are still cards within the deck. If no
        size_t random = rand() % deck.cards.size(); // unsigned int [name] = rand() of remaining deck card size.
        shuffled.cards.push_back(  deck.cards[ random ]); // add to the vector in shuffled deck. Taking deck.cards and randomising the index. (randomly selecting an index and adding it to the shuffled cards)

        deck.cards.erase(deck.cards.begin() + random);
    }
    deck = shuffled;
}

void dealCards(Game &game) {
    for( int card = 0; card < game.num_of_cards_per_hand; card++ ) {
        for( int player = 0; player < game.num_players; player++ ) {
            game.players[ player ].hand.push_back(game.deck.cards[ 0 ]);
            game.deck.cards.erase(game.deck.cards.begin());
            // Same line of code as before, just simpler. Instead of having two hands the player and the dealer.
            // the line above adds the number of cards to the hands of number of players.
            // [107-108] adding top level shuffled card to hand of player in game object, per player.
        }
    }
}

void printHand(const vector<Card> &hand) {
    for( Card c : hand ) {
        printCard(c);
    }
}

void welcomeMessage() {
    cout << "Welcome to the Decked Out card game!" << endl << '\n';
}

void initialiseGame(Game &game) {
    welcomeMessage();
    initialiseDeck(game.deck);
    shuffle(game.deck);
    addPlayer(game);
}

void addPlayer(Game &game) {
// for loop? to add player to vector of player in Game?
// if player is < game.num_players; player++
    for( int player = 0; player < game.num_players; player++ ) {
        Player new_player;
        game.players.push_back(new_player);
    }
}

void printGame(const Game &game) {
    for( int player = 0; player < game.num_players; player++ ) {
        printHand(game.players[ player ].hand);
        cout << '\n'; // prints player hand
    }
    cout << "the size of deck " << sizeof(game.deck) << endl;
    printDeck(game.deck);  // prints full deck (cards remaining after cards have been dealt
}

void playGame(Game& game){
    initialiseGame(game);
    dealCards(game);

    bool bust = false;
    size_t player = 0;  //size_t is appropriate here, used for indexing in c++. This variable will be used to alternate hands for drawing a card.

    while (!bust){
        cout << "Your hand: \n";
        printHand(game.players[player].hand);
        cout << "Your current card score = " << game.players[player].score << '\n';
        // if player here = 0, on each deal card, the player + 1 on index of players which will cause on third itertation (player = 3)
        // size_t random = rand() % deck.cards.size(); using this logic and the num_players variable in Game struct
        // if player is 0 then dealer is 1, 0 + 1 is fine as dealer would be 0. but what if player is 1, then the dealer must be 0. this causes issues on iterations.
        // for this to work we need 0 + 1 = 1. 1 + 1 = 0; for this the mod operator as used previously has to be used.
        size_t dealer = (player + 1) % game.num_players;    // player + 1 + 1 then mod it by the number_of_players (2) = 0

        printHand(game.players[dealer].hand);
        cout << "Dealer's score: " << game.players[dealer].score << '\n';
    }
}
