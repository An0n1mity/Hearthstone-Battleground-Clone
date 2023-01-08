#include <memory>
#include "Bot.h"
#include "Board.h"
#include "Shop.h"
#include "CLI.h"

class GameLogicManager
{
private:
    // Manage which player is playing
    bool m_player1Turn = true;
    std::unique_ptr<Player> m_player1;
    std::unique_ptr<Bot> m_bot;
    std::shared_ptr<Board> m_board;
    std::unique_ptr<Shop> m_shop;
    std::unique_ptr<CLI> m_cli;

    // Number of turns
    size_t m_turn = 3;

public:
    GameLogicManager()
    {
        srand( time( NULL ) );
        createPlayers();
        createBoard();
        createShop();
	createCLI();
    }

    void createPlayers();
    void createBoard();
    void createShop();
    void createCLI();

    Board &getBoard() const { return *m_board; }
    Shop &getShop() const { return *m_shop; }
    Player &getPlayer1() const { return *m_player1; }
    Player &getPlayer2() const { return *m_bot; }

    //void startGame();
    CLI::cli_input recruitementPhase();
    void battlePhase();
    void endPhase();
};
