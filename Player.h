#include "Heroes.h"
#include "MinionsCards.h"
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
    unsigned int m_level;
    unsigned int m_golds = 3;
    // Hero of the player
    std::unique_ptr<Hero> m_hero;
    // Player deck the cards on his hand
    std::vector<std::unique_ptr<Card>> m_in_hand;
    // Player board the cards on the board
    std::vector<std::shared_ptr<Card>> m_on_board;

public:
    Player(std::string name, unsigned int level) : m_name(name), m_level(level) {}
    ~Player() {}
    // Add hero to the player
    void addHero(std::unique_ptr<Hero> hero);
    // Add a battler to the deck of the player
    void addCardToHand(std::unique_ptr<Card> card);
    // Move a battler from the deck to the board
    void moveCardFromDeckToBoard(int index);

    int getLevel() const { return m_level; }
    int getGolds() const { return m_golds; }
    void setGolds(int golds) { m_golds = golds; }

    // operator overloading for std::cout << player
    friend std::ostream &operator<<(std::ostream &os, Player &player);

    // Allow Game to access private members of Player, because game manages the players
    friend class Game;
};