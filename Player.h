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
    unsigned int m_golds = 0;
    // Hero of the player
    std::unique_ptr<Hero> m_hero;
    // Player deck the cards on his hand
    std::vector<std::unique_ptr<Card>> m_in_hand;
    // Player board the cards on the board
    std::vector<std::shared_ptr<Card>> m_on_board;

public:
    Player(std::string name) : m_name(name) {}
    ~Player() {}
    // Add hero to the player
    void addHero(std::unique_ptr<Hero> hero);
    // Add a battler to the deck of the player
    void addCardToDeck(std::unique_ptr<Card> card);
    // Move a battler from the deck to the board
    void moveCardFromDeckToBoard(int index);

    // operator overloading for std::cout << player
    friend std::ostream &operator<<(std::ostream &os, Player &player);

    // Allow Game to access private members of Player, because game manages the players
    friend class Game;
};