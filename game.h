#include "Player.h"
#include <memory>

class Game {
private:
    std::unique_ptr<Player> player1;
    std::unique_ptr<Player> player2;
    std::vector<std::unique_ptr<Card>> m_deck;

public:
    Game(std::unique_ptr<Player> player1_, std::unique_ptr<Player> player2_)
    {
        player1 = std::move(player1_);
        player2 = std::move(player2_);
    }
    ~Game()
    {
    }
    void chooseHero(std::unique_ptr<Hero> hero, int player)
    {
        if (player == 1)
        {
            player1->addHero(std::move(hero));
        }
        else
        {
            player2->addHero(std::move(hero));
        }
    }
    void startGame();
    void deckPhase();
    void battlePhase();
    void endGame();
};