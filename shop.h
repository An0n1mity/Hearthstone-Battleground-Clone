#include "Player.h"
#include <algorithm>
#include <ctime>
#include <future>
#include <thread>

class Shop {
    private:
        std::vector<std::unique_ptr<Minion>> m_deck;
        std::vector<std::unique_ptr<Minion>> m_choices;
    public:
        Shop() {}
        ~Shop() {}
        void createDeck();
        void shuffleDeck();
        void drawCards(Player &player);
        void displayCards();
        void chooseCard(Player &player);
        void buyCard(int index, Player &player);
};
