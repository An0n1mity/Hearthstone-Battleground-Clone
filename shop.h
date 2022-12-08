#pragma once
#include "Player.h"
#include <algorithm>
#include <ctime>
#include <future>
#include <thread>

class Shop {
    private:
        std::vector<std::unique_ptr<Card>> m_deck;
        std::vector<std::unique_ptr<Card>> m_choices;

    public:
        Shop() {}
        ~Shop() {}
        void createDeck();
        void shuffleDeck();
        void drawCards(Player &player);
        void displayCards();
        void buyCard(int index, Player &player);
        void putCardBack();
        void sellCard(std::unique_ptr<Card> card, Player *player)
        {
            // Add the card to the shop
            m_deck.push_back(std::move(card));
            // Add a gold to the player
            player->setGolds(player->getGolds() + 1);
        }
        void sellCard(int index, Player &player);
};
