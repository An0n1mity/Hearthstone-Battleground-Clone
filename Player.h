#pragma once
#include "Heroes.h"
#include "MinionsCards.h"
#include <vector>
#include <string>
#include <iostream>
#include "Board.h"

class Shop;
class Board;

class Player
{
private:
    // Player name
    std::string m_name;
    // Player golds
    unsigned int m_level;
    unsigned int m_golds = 3;
    // Hero of the player
    std::unique_ptr<Hero> m_hero;
    // Player deck the cards on his hand
    std::vector<std::unique_ptr<Card>> m_in_hand;
    // Player board
    std::shared_ptr<Board> m_board;

public:
    Player(std::string name, unsigned int level) : m_name(name), m_level(level) {
        m_board = std::make_shared<Board>();
    }
    ~Player() {}
    //set Board
    void setBoard(std::shared_ptr<Board> board) { m_board = board; }
    // get Board
    std::shared_ptr<Board> getBoard() { return m_board; }
    // Add hero to the player
    void addHero(std::unique_ptr<Hero> hero);
    // Add a battler to the deck of the player
    void addCardToHand(std::unique_ptr<Card> card);
    // Move a battler from the deck to the board
    void moveCardFromDeckToBoard(int index);

    int getLevel() const { return m_level; }
    int getGolds() const { return m_golds; }
    void setGolds(int golds) { m_golds = golds; }

    // Give a card from the hand to the shop
    void giveCardFromHand(int index, Shop *shop);

    // operator overloading for std::cout << player
    friend std::ostream &operator<<(std::ostream &os, Player &player);

    // Allow Game to access private members of Player, because game manages the players
    friend class Game;
};