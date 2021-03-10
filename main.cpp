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
enum Rank { ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };
enum Suit { HEARTS, DIAMOND, SPADES, CLUBS };

struct Card {   //Own data type of Card
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

void initialise(Deck &);
void print_deck(const Deck &);
void print_card(const Card &);
void shuffle(Deck &);
void deal_cards(Game &);
void print_hand(const vector<Card> &);   //Consted - not changing the hand in the function.
void initialise(Game &);
void add_player(Game &game);

int main() {
    Game game;
    initialise(game);
    deal_cards(game);
    print_game(game);

    //Maybe Work on a initialiser such as game object, which calls all of these functions.
    //Will make the main look better, as it will just have a game object called.??? Think about it.
    //Looking inside the main, realising that all above are components of the game, I would like to declare a single variable for the card game to be called.
}

void initialise(Deck &deck) {
    Card card;
    for (int suit = 0; suit < card.num_suits; suit++) {
        for (int rank = 0; rank < card.num_rank; rank++) {
            card.suit = Suit(suit); //(Suit/Rank is casted from ENUM type (changes int into value of enum))
            card.rank = Rank(rank);
            deck.cards.push_back(card); //Declaring a new card and adding it to the deck
        }
    }
}

void print_deck(const Deck &deck) {
    for (Card c : deck.cards) // cards is member of deck. So referred to as cards and not card
    {
        print_card(c);
    }
}

void print_card(const Card &card) {
    cout << "Rank " << card.rank << " of " << "Suit " << card.suit << '\n';     //can i make this a pointer for each card that has been dealt??
}

void shuffle(Deck &deck) {
    Deck shuffled;
    while (!deck.cards.empty()) {   // validation to check if there are still cards within the deck. If no
        size_t random = rand() % deck.cards.size(); //unsigned int [name] = rand() of remaining deck card size.
        shuffled.cards.push_back(deck.cards[random]); //add to the vector in shuffled deck. Taking deck.cards and randomising the index. (randomly selecting an index and adding it to the shuffled cards)
        deck.cards.erase(deck.cards.begin() + random);
    }
    deck = shuffled;
}

void deal_cards(Game& game)
{
    for (int card = 0; card < game.num_of_cards_per_hand; card++)
    {
      for (int player = 0; player < game.num_players; player++)
      {
          game.players[player].hand.push_back(game.deck.cards[0]);
          game.deck.cards.erase(game.deck.cards.begin());
          //Same line of code as before, just simpler. Instead of having two hands the player and the dealer.
          // the line above adds the number of cards to the hands of number of players.
          // [107-108] adding top level shuffled card to hand of player in game object, per player.
      }
    }
}

void print_hand(const vector<Card> &hand) {
    for (Card c : hand) {
        print_card(c);
    }
}

void welcomeMessage(){
    cout <<  "Welcome to the Decked Out card game!" << endl;
}

void initialise(Game& game){
    welcomeMessage();

    initialise(game.deck);
    shuffle(game.deck);
    add_player(game);
}

void add_player(Game &game) {
// for loop? to add player to vector of player in Game?
// if player is < game.num_players; player++
    for (int player = 0; player < game.num_players; player++)
    {
        Player new_player;
        game.players.push_back(new_player);
    }
}
