#include "Player.h"
#include <algorithm>
#include <ctime>  

class Shop {
    private:
        std::vector<std::unique_ptr<Minion>> m_deck;
        std::vector<std::unique_ptr<Minion>> m_choices;
    public:
        Shop() {}
        ~Shop() {}
        void createDeck();
        void shuffleDeck();
        void chooseCard(Player &player);
        void drawCards(Player &player);
        void buyCard(int index, Player &player);
};
