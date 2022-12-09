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
    std::unique_ptr<Player> m_player;
    std::unique_ptr<Bot> m_bot;
    std::unique_ptr<Shop> m_shop;
    std::shared_ptr<Board> m_board;
    bool m_running = false;
    int max_gold = 3;
    char m_input;

public:
    Game(std::unique_ptr<Player> player, std::unique_ptr<Bot> bot)
    {
        m_player = std::move(player);
        m_bot = std::move(bot);
        m_shop = std::make_unique<Shop>();
        m_board = std::make_unique<Board>();
    }
    ~Game()
    {
    }
    void startGame();
    int deckPhase();
    void threadDeckPhase(std::future<void> futureObj);
    void battlePhase();
    void endGame();
    void mode_raw(int activer);
    void getInput();
};