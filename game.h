#include "shop.h"
#include <memory>
#include <thread>
#include <future>
#include <chrono>
#include <termios.h>
#include <unistd.h>

class Game {
private:
    std::unique_ptr<Player> m_player1;
    std::unique_ptr<Player> m_player2;
    std::unique_ptr<Shop> m_shop;
    bool m_running = false;
    int max_gold = 3;

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
    int deckPhase();
    void battlePhase();
    void threadDeckPhase(std::future<void> futureObj);
    void endGame();
    void mode_raw(int activer);
};