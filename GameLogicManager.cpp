#include "GameLogicManager.h"
#define GAMELOGICMANAGER_DEBUG
#include <chrono>
#include <thread>

// Create the two players that will battle
void GameLogicManager::createPlayers()
{
#ifdef GAMELOGICMANAGER_DEBUG
    std::cout << "[GAMELOGICMANAGER DEBUG]: Called from " << __FILE__ << " at line " << __LINE__ << " GameLogicManager::createPlayers" << std::endl;
#endif
    m_player1 = std::make_unique<Player>("Player 1");
    m_bot = std::make_unique<Bot>("Bot");
}

// Create the board that will manage the cards
void GameLogicManager::createBoard()
{
#ifdef GAMELOGICMANAGER_DEBUG
    std::cout << "[GAMELOGICMANAGER DEBUG]: Called from " << __FILE__ << " at line " << __LINE__ << " GameLogicManager::createBoard" << std::endl;
#endif
    m_board = std::make_unique<Board>();
    std::experimental::observer_ptr<Board> board_ptr = std::experimental::make_observer(m_board.get());
    m_player1->linkBoard(board_ptr);
    m_bot->linkBoard(board_ptr);
}

// Create the shop where players will buy and sell cards
void GameLogicManager::createShop()
{
#ifdef GAMELOGICMANAGER_DEBUG
    std::cout << "[GAMELOGICMANAGER DEBUG]: Called from " << __FILE__ << " at line " << __LINE__ << " GameLogicManager::createShop" << std::endl;
#endif
    m_shop = std::make_unique<Shop>();
}

void GameLogicManager::createCLI()
{
#ifdef GAMELOGICMANAGER_DEBUG
	std::cout << "[GAMELOGICMANAGER DEBUG]: Called from " << __FILE__ << " at line " << __LINE__ << " GameLogicManager::createCLI" << std::endl;
#endif
	std::cout << "Creating CLI..." << std::endl;
	m_cli = std::make_unique<CLI>();
}

CLI::cli_input GameLogicManager::recruitementPhase()
{
#ifdef GAMELOGICMANAGER_DEBUG
    std::cout << "[GAMELOGICMANAGER DEBUG]: Called from " << __FILE__ << " at line " << __LINE__ << " GameLogicManager::recruitementPhase" << std::endl;
#endif
    // Give gold to the players based on the turn
    m_shop->giveGold(*m_player1, m_turn);
    m_shop->giveGold(*m_bot, m_turn);

    // Draw 3 cards from the shop
    m_shop->giveChoice(*m_player1);

    // Get the input from the players 
    CLI::cli_input input;
    do{
	// Clear 
	m_cli->clear();
	// Draw the board 
	m_cli->drawBoard(*m_board, *m_player1, *m_bot);
	// Draw the choices 
	m_cli->drawChoices(*m_player1);
	// Draw the hand 
	m_cli->drawHand(*m_player1);
	// Draw the player stats 
    m_cli->drawStats(*m_bot);
	m_cli->drawStats(*m_player1);
	input = m_cli->getInput(*m_player1);
	switch (input.choice)
	{
	    case CLI::BUY:
            m_player1->selectCardFromChoices(input.card, *m_shop);
            break;
	    case CLI::SELL:
            m_player1->sellCardFromHand(input.card, *m_shop);
            break;
	    case CLI::PLAY:
            m_player1->moveCardFromHandToBoardLeft(input.card);
            break;
        case CLI::EXIT:
	    std::cout << "Exiting..." << std::endl;
	    return {CLI::EXIT, 0};
	}
    }while(input.choice != CLI::BATTLE);
    m_player1->resetChoices();
    // bot phase
    m_shop->giveChoice(*m_bot);
    m_bot->playTurn(*m_shop);
    m_cli->drawHand(*m_bot);
    m_bot->resetChoices();
    return input;
}

void GameLogicManager::battlePhase()
{
#ifdef GAMELOGICMANAGER_DEBUG
    std::cout << "[GAMELOGICMANAGER DEBUG]: Called from " << __FILE__ << " at line " << __LINE__ << " GameLogicManager::battlePhase" << std::endl;
#endif 
    m_cli->drawBoard(*m_board, *m_player1, *m_bot);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    // Randomly choose a player to start
    int player_to_start = rand() % 2;
    // Select the player that will start
    Player &player = (player_to_start == 0) ? *m_player1 : *m_bot;
    // Select the player that will wait
    Player &player2 = (player_to_start == 0) ? *m_bot : *m_player1;

    // Get player cards on board
    std::vector<std::reference_wrapper<Card>> player_cards = m_board->getPlayerCardsView(player);
    std::vector<std::reference_wrapper<Card>> player2_cards = m_board->getPlayerCardsView(player2);
    
    // For each card of the attacking player
    for (auto card : player_cards)
    {
	// If the enemy has no cards on board, attack the enemy directly 
	if (player2_cards.size() == 0)
	{
	    Minion* minion = dynamic_cast<Minion*>(&card.get());
	    minion->attackEnemy(player2);
	    continue;
	}
        // Select a random card of the defending player
        int card_to_attack = rand() % player2_cards.size();
        // Dynamic cast to minion
        Minion *minion = dynamic_cast<Minion *>(&card.get());
        Minion *minion2 = dynamic_cast<Minion *>(&player2_cards[card_to_attack].get());
        // Attack the card
        minion->attackEnemy(*minion2);
        // Update if some cards died
        player2_cards = m_board->getPlayerCardsView(player2);

	m_cli->clear();
	m_cli->drawBoard(*m_board, *m_player1, *m_bot);
	std::this_thread::sleep_for(std::chrono::seconds(3));
    }

    // For each card of the defending player
    for (auto card : player2_cards)
    {
	// If the enemy has no cards on board, attack the enemy directly 
	if (player_cards.size() == 0)
	{
	    Minion* minion = dynamic_cast<Minion*>(&card.get());
	    minion->attackEnemy(player);
	    continue;
	}
        // Select a random card of the attacking player
        int card_to_attack = rand() % player_cards.size();
        // Dynamic cast to minion
        Minion *minion = dynamic_cast<Minion *>(&card.get());
        Minion *minion2 = dynamic_cast<Minion *>(&player_cards[card_to_attack].get());
        // Attack the card
        minion->attackEnemy(*minion2);
        // Update if some cards died
        player_cards = m_board->getPlayerCardsView(player);

	m_cli->clear();
	m_cli->drawBoard(*m_board, *m_player1, *m_bot);
	std::this_thread::sleep_for(std::chrono::seconds(3));
    }
}
