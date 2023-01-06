#pragma once

#include <algorithm>
#include <ctime>
#include <future>
#include <thread>
#include "Cards.h"

class Player;

class Shop
{
private:
    // Shop is managing the cards tp buy
    std::vector<std::unique_ptr<Card>> m_deck;

    // Calculate number of gold to give to the player base on number of turns
    unsigned int calculateGold(unsigned int turns) const;

public:
    Shop()
    {
        createDeck();
        shuffleDeck();
    }
    ~Shop() {
        m_deck.clear();
    }
    void createDeck();
    // Shuffle the deck of cards
    void shuffleDeck();
    // Draw 3 cards from the deck
    void giveChoice(Player &player);
    void giveCardToPlayer(Player &player, Card &card);
    void sellCard(std::unique_ptr<Card> &card, Player *player);
    // Give gold to the player
    void giveGold(Player &player, unsigned int turns) const;
};
