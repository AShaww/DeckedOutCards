//
// Created by AmirS on 30/03/2021.
//

#ifndef DECKEDARRAY_GAME_H
#define DECKEDARRAY_GAME_H
#include "Player/Player.h"
#include "../Card/Card.h"

class Game{
public:
    Deck deck;
    const int getNumOfPlayers(){
        return numOfPlayers;
    }
    const int getCardsPerHand(){
        return numCardPerHand;
    }
    vector<Player> players;
    void dealCards(Game&);
    void initialiseGame(Game&);
    void addPlayer(Game&);
    void displayState(const Game& ,size_t);
    void play(Game&);
    void takeCard(Game&, size_t, Rank);
    bool isBust(const vector <Card> &, Rank);
    Rank getRank(const vector<Card> &hand);
private:
    int numOfPlayers = 2;
    int numCardPerHand = 1;
//    string name;
//    int score;
};

void Game::dealCards(Game& game) {
    for (int card = 0; card < game.getCardsPerHand(); card++) {
        for (int player = 0; player < game.getNumOfPlayers(); player++) {
            game.players[player].hand.push_back(game.deck.cards[0]);
            game.deck.cards.erase(game.deck.cards.begin());
        }
    }
}

void Game::initialiseGame(Game& game) {
    Deck deck;
    deck.initialiseDeck(game.deck);
    deck.shuffle(game.deck);
    addPlayer(game);

}

void Game::addPlayer(Game& game) {
    for (int player = 0; player < game.numOfPlayers; player++) {
        Player newPlayer;
        game.players.push_back(newPlayer);

    }
}
void Game::play(Game& game) {
    initialiseGame(game);
    dealCards(game);

    bool gameOver = false;
    size_t player = 0;

    while (!gameOver) {
        displayState(game, player);
        Rank rank = getRank(game.players[player].hand);
        size_t nextPlayer = (player + 1) % game.numOfPlayers;
        if(isBust(game.players[nextPlayer].hand, rank)) // making sure to pass new element just what is needed to make it perform with only its need.
        {
            takeCard(game, player, rank);
        }
        gameOver = true;
    }
}
void Game::takeCard(Game& game , size_t currentPlayer, Rank chosenRank){
    size_t nextPlayer = (currentPlayer + 1) % game.numOfPlayers;
    bool cardTaken = false;
    size_t cardIndex = 0;
    while (!cardTaken) {
        cardTaken = true;
    }
}
bool Game::isBust(const vector<Card>& hand, Rank chosenRank)
{
    // This here will be where the switch statement goes for if
    bool bust = false;
    for (Card c : hand)
    {
        if (c.rank == chosenRank)
        {
            bust = true;
        }
    }
    return bust;
}
void Game::displayState(const Game& game, size_t player) {
    cout << '\n';
    cout << "Your hand: \n";
    Card::printHand(game.players[player].hand);
    cout << "Your score = " << game.players[player].score << '\n';
    cout << '\n';

    size_t dealer = (player + 1) % game.numOfPlayers;
    cout << "Dealer's Hand: \n";
    Card::printHand(game.players[dealer].hand);
    cout << "Opponent's score: " << game.players[dealer].score << '\n';
    cout << '\n';
}
Rank Game::getRank(const vector<Card>& hand) {
    bool valid = false;
    int rank;
    int score;

    while (!valid) {
        //
        //        cout << "[1] To Stay \n";
        //        cout << "[0] To Hit \n";
        //        function to check response from user, pseudo above.
        cout << "please enter a rank: ";
        cin >> rank;
        for (Card c : hand)
        {
            if (c.rank == Rank(rank))
            {
                valid = true;
            }
        }
    }
    return Rank(rank);
}
#endif //DECKEDARRAY_GAME_H
