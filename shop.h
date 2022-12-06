#include "Player.h"
#include <algorithm>
#include <ctime>  

class Shop {
    private:
        std::vector<std::unique_ptr<Minion>> m_deck;
    public:
        Shop() {}
        ~Shop() {}
        void createDeck();
        void shuffleDeck();
        void drawCards(Player &player);
        void buyCard(int index, Player &player);
};
