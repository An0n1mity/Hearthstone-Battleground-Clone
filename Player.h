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
    // Payer HP
    unsigned int m_hp = 30;
    // Hero of the player
    std::unique_ptr<Hero> m_hero;
    // Player deck the cards on his hand
    std::vector<std::unique_ptr<Card>> m_hand;
    // Shop cards proposed to the player
    std::vector<std::reference_wrapper<Card>> m_choices;
    // Link to the board
    std::experimental::observer_ptr<Board> m_board;
    // Identifier to know if the player is the first or the second
    int m_id;

public:
    // Update id of the player
    void setId()
    {
        static int id = 0;
        m_id = id++;
    }
    // Get id of the player
    int getId() const { return m_id; }
    Player(std::string name) : m_name(name)
    {
        setId();
    }
    ~Player() {}
    // Add a battler to the deck of the player
    void addCardToHand(std::unique_ptr<Card> &card);
    // Move a battler from the deck to the board
    void moveCardFromHandToBoardLeft(int index);

    void linkBoard(std::experimental::observer_ptr<Board> board);
    // Get board
    std::experimental::observer_ptr<Board> getBoard() { return m_board; }
    // Get the name of the player
    std::string getName() const { return m_name; }
    // Get the golds of the player
    unsigned int getGolds() const { return m_golds; }
    // Get the health points of the player
    unsigned int getHealth() const { return m_hp; }
    // Set the golds of the player
    void setGolds(unsigned int golds) { m_golds = golds; }
    // Set hp of the player 
    void setHealth(unsigned int hp) { m_hp = hp; }
    // Get level of player
    unsigned int getLevel() const { return m_level; }
    // Set level of player
    void setLevel(unsigned int level) { m_level = level; }
    // operator overloading for std::cout << player
    friend std::ostream &operator<<(std::ostream &os, Player &player);

    // Friend function to give gold to the player
    friend void Shop::giveGold(Player &player, unsigned int golds) const;

    // Buy a card from the shop
    void buyCardFromShop(std::vector<std::reference_wrapper<Card>> &cards, int index, Shop &shop);

    // Give a card to the shop
    void sellCardFromHand(int index, Shop &shop);

    // give a card from the board to shop
    void giveCardFromBoard(int index, Shop &shop);

    // Add card to the choices of the player
    void addCardToChoices(Card &card);
    // Get a view on the choices of the player 
    std::vector<std::reference_wrapper<Card>> getChoicesView() const { return m_choices; }
    // Get a view on the hand of the player
    std::vector<std::reference_wrapper<Card>> getHandView() const; 
    // Select a card from the choices
    void selectCardFromChoices(int index, Shop &shop);
    // Reset the choices of the player
    void resetChoices();
    // Print the choices of the player
    void printChoices() const;
};

#endif
