#include "shop.h"
#include <memory>

class Game {
private:
    std::unique_ptr<Player> m_player1;
    std::unique_ptr<Player> m_player2;
    std::vector<std::unique_ptr<Card>> m_deck;
    std::vector<std::unique_ptr<Card>> m_choices;
    std::unique_ptr<Shop> m_shop;

public:
    Game(std::unique_ptr<Player> player1_, std::unique_ptr<Player> player2_)
    {
        m_player1 = std::move(player1_);
        m_player2 = std::move(player2_);
        m_shop = std::make_unique<Shop>();
    }
    ~Game()
    {
    }
    void startGame();
    void deckPhase();
    void battlePhase();
    void endGame();
};