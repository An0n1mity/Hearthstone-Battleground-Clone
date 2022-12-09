#include "shop.h"
#include "Board.h"
#include <memory>
#include <thread>
#include <future>
#include <chrono>
#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include <string>

class Game {
private:
    std::unique_ptr<Player> m_player1;
    std::unique_ptr<Player> m_player2;
    std::unique_ptr<Shop> m_shop;
    std::shared_ptr<Board> m_board;
    bool m_running = false;
    int max_gold = 3;
    char m_input;

public:
    Game(std::unique_ptr<Player> player1_, std::unique_ptr<Player> player2_)
    {
        m_player1 = std::move(player1_);
        m_player2 = std::move(player2_);
        m_shop = std::make_unique<Shop>();
        m_board = std::make_unique<Board>();
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
    void getInput();
};