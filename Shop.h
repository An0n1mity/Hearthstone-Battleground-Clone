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
    std::vector<std::shared_ptr<Card>> m_deck;
    // Card presented to the player
    std::vector<std::shared_ptr<Card>> m_choices;

public:
    Shop()
    {
        createDeck();
        shuffleDeck();
    }
    ~Shop() {
        for (auto &card : m_deck)
        {
            card->printName();
        }
        for (auto &card : m_choices)
        {
            card->printName();
        }
        
        m_deck.clear();
        m_choices.clear();
    }
    void createDeck();
    // Shuffle the deck of cards
    void shuffleDeck();
    // Draw 3 cards from the deck
    void drawCards(Player &player);
    void displayCards();
    void buyCard(int index, Player &player);
    void putCardBack();
    void sellCard(std::shared_ptr<Card> &card, Player *player);
    // Give gold to the player
    void giveGold(Player &player, unsigned int golds);
    void reDrawCards(Player &player);
};
