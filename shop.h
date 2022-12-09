#pragma once
#include "Bot.h"
#include <algorithm>
#include <ctime>
#include <future>
#include <thread>

class Shop {
    private:
        std::vector<std::unique_ptr<Card>> m_deck;
        std::vector<std::unique_ptr<Card>> m_choices;

    public:
        Shop() {
            createDeck();
            shuffleDeck();
        }
        ~Shop() {}
        void createDeck();
        void shuffleDeck();
        void drawCards(Player &player);
        void displayCards();
        void buyCard(int index, Player &player);
        void putCardBack();
        void sellCard(std::unique_ptr<Card> card, Player *player);
        
};