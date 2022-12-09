#ifndef PLAYER_H
#define PLAYER_H

#include "Heroes.h"
#include "MinionsCards.h"
#include "Board.h"
#include <vector>
#include <memory>
#include <string>
#include <iostream>

class Player
{
private:
    // Player name
    std::string m_name;
    // Player golds
    unsigned int m_golds = 0;
    // Hero of the player
    std::unique_ptr<Hero> m_hero;
    // Player deck the cards on his hand
    std::vector<std::unique_ptr<Card>> m_hand;
    // Link to the board
    std::weak_ptr<Board> m_board;

public:
    Player(std::string name) : m_name(name) {}
    ~Player() {}
    // Add a battler to the deck of the player
    void addCardToHand(std::unique_ptr<Card> &card);
    // Move a battler from the deck to the board
    void moveCardFromHandToBoard(int index);

    void linkBoard(std::weak_ptr<Board> board);
    // Get board
    std::weak_ptr<Board> getBoard() { return m_board; }
    // Get the name of the player
    std::string getName() const { return m_name; }
    // operator overloading for std::cout << player
    friend std::ostream &operator<<(std::ostream &os, Player &player);

    // Allow Game to access private members of Player, because game manages the players
    friend class Game;
};

#endif