#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

enum Rank {
    ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE
};
enum Suit {
    HEARTS, DIAMOND, SPADES, CLUBS
};

struct Card {   //Own data type of Card
    Rank rank;
    Suit suit;
    int num_suits = 4;
    int num_rank = 13;
};

struct Deck {
    vector<Card> cards;
    string card_back;
    //int max_deck_size = 52; //Sets deck size to 52 (0 - 51) Dont need this as im doing a loop count of 52
    //Own data type of Deck
};

//List of Prototypes
void initialise(Deck &);
void print_deck(const Deck &);
void print_card(const Card &);
void shuffle(Deck &);
void deal_cards(Deck &, vector<Card> &, vector<Card> &, int);
void print_hand(const vector<Card> &);   //Consted - not changing the hand in the function.

int main() {
    Deck my_deck;
    initialise(my_deck);
//  print_deck(my_deck); // Prints out deck in order from 0-12 of enum Value
    shuffle(my_deck);   //Shuffles deck - uncomment above line to see ordered deck. Run this line
//  print_deck(my_deck);    // Uncomment this line to see the shuffled deck.
    vector<Card> dealer_hand;
    vector<Card> player_hand;
    deal_cards(my_deck, dealer_hand, player_hand, 1);
    cout << '\n';
    print_hand(player_hand);
    cout << '\n';
    print_hand(dealer_hand);
    cout << '\n';
    deal_cards(my_deck, dealer_hand, player_hand, 1);
    deal_cards(my_deck, dealer_hand, player_hand, 1);
    //print_deck(my_deck);
    //Maybe Work on a initialiser such as game object, which calls all of these functions.
    //Will make the main look better, as it will just have a game object called.??? Think about it.
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
    cout << "Rank " << card.rank << " of " << "Suit " << card.suit << '\n';     //can i make this a pointer for each card that has been dealt
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

void deal_cards(Deck &deck, vector<Card> &dealer_hand, vector<Card> &player_hand, int num_of_cards) {
    for (int count = 0; count < num_of_cards; count++) {
        dealer_hand.push_back(deck.cards[0]);   //Add a card to the hand [top card]
        deck.cards.erase(deck.cards.begin());
        player_hand.push_back(deck.cards[0]);   //Add a card to the hand [top card]
        deck.cards.erase(deck.cards.begin());
    }
}

void print_hand(const vector<Card> &hand) {
    for (Card c : hand) {
        print_card(c);
    }
}