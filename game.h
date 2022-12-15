#include "Player.h"
#include <memory>

class Game {
private:
    std::unique_ptr<Player> player1;
    std::unique_ptr<Player> player2;

public:
    Game(std::unique_ptr<Player> player1_, std::unique_ptr<Player> player2_)
    {
        player1 = std::move(player1_);
        player2 = std::move(player2_);
    }
    ~Game()
    {
    }
    void startGame();
    void deckPhase();
    void battlePhase();
    void endGame();
};