#ifndef PLAYER_H
#define PLAYER_H

#include "Heroes.h"
#include "MinionsCards.h"
#include "Board.h"
#include "Shop.h"
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
    // Player level
    unsigned int m_level = 1;
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
    // Get the golds of the player
    unsigned int getGolds() const { return m_golds; }
    // Set the golds of the player
    void setGolds(unsigned int golds) { m_golds = golds; }
    // Get level of player
    unsigned int getLevel() const { return m_level; }
    // Set level of player
    void setLevel(unsigned int level) { m_level = level; }
    // operator overloading for std::cout << player
    friend std::ostream &operator<<(std::ostream &os, Player &player);

    // Friend function to give gold to the player
    friend void Shop::giveGold(Player &player, unsigned int golds);

    // Give a card to the shop
    void sellCardFromHand(int index, Shop *shop);

    // Allow Game to access private members of Player, because game manages the players
    friend class Game;

    // give a card from the board to shop
    void giveCardFromBoard(int index, Shop *shop);
};

#endif