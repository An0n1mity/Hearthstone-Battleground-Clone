#include "GameLogicManager.h"
#include "Minions.h"
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
        case CLI::UPGRADE:
            m_player1->upgradeLevel();
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
    // Player with the most cards on the board attacks first 
    int player_nb_cards = m_board->getNumberOfCards(*m_player1);
    int bot_nb_cards = m_board->getNumberOfCards(*m_bot);

    Player* attacker = (player_nb_cards > bot_nb_cards) ? m_player1.get() : m_bot.get();
    Player* defender = (player_nb_cards > bot_nb_cards) ? m_bot.get() : m_player1.get();

    // If same number of cards, random
    if (player_nb_cards == bot_nb_cards)
	{
		int random = rand() % 2;
		// Switch attacker and defender
		if (random == 0)
		{
			Player* temp = attacker;
			attacker = defender;
			defender = temp;
		}
	}

    // Get player cards on board
    std::vector<std::reference_wrapper<Card>> player_cards = m_board->getPlayerCardsView(*attacker);
    std::vector<std::reference_wrapper<Card>> player2_cards = m_board->getPlayerCardsView(*defender);
   

    // For each card of the attacking player
    for (auto card : player_cards)
    {
	// If the minion has no atack point 
	Minion* minion = dynamic_cast<Minion*>(&card.get());
	if (minion->getAttack() == 0)
	    continue;
	// If the enemy has no cards on board, attack the enemy directly 
	if (player2_cards.size() == 0)
	{
	    minion->attackEnemy(*defender);

	    m_cli->clear();
	    m_cli->drawBoard(*m_board, *m_player1, *m_bot);
	    std::cout << minion->getName() << " attacks " << defender->getName() << std::endl;
	    std::this_thread::sleep_for(std::chrono::seconds(3));

	    minion->setState(Minion::State::IDLING);
	    continue;
	}
    // Get enemy cards with taunt
    std::vector<std::reference_wrapper<Card>> taunt_cards = m_board->getPlayerCardsViewWithTaunt(*defender);
    // Select a random card of the defending player
    int card_to_attack = rand() % player2_cards.size();
    // Dynamic cast to minion
    // If the enemy has taunt cards, attack a random taunt card
    if (taunt_cards.size() > 0)
    {
	card_to_attack = rand() % taunt_cards.size();
        // Get index of the taunt card
        card_to_attack = m_board->getCardIndex(taunt_cards[card_to_attack].get());

    }
    Minion *minion2 = dynamic_cast<Minion *>(&player2_cards[card_to_attack].get());
    // Attack the card if the minion is alive

    m_cli->clear();
    if (minion->getHealth() > 0)
    {
        minion->attackEnemy(*minion2);
        std::cout << minion->getName() << " attacks " << minion2->getName() << std::endl;
    }
    m_cli->drawBoard(*m_board, *m_player1, *m_bot);
    std::this_thread::sleep_for(std::chrono::seconds(3));

    minion->setState(Minion::State::IDLING);
    minion2->setState(Minion::State::IDLING);

    m_board->destroyCards();
    player2_cards = m_board->getPlayerCardsView(*defender);

    m_cli->clear();
	m_cli->drawBoard(*m_board, *m_player1, *m_bot);
	std::this_thread::sleep_for(std::chrono::seconds(3));
    }

    // For each card of the defending player
    for (auto card : player2_cards)
    {
	// If the minion has no atack point
	Minion* minion = dynamic_cast<Minion*>(&card.get());
	if (minion->getAttack() == 0)
	    continue;
	// If the enemy has no cards on board, attack the enemy directly 
	if (player_cards.size() == 0)
	{
	    minion->attackEnemy(*attacker);

	    m_cli->clear();
	    m_cli->drawBoard(*m_board, *m_player1, *m_bot);
	    std::cout << minion->getName() << " attacks " << attacker->getName() << std::endl;
	    std::this_thread::sleep_for(std::chrono::seconds(3));

	    minion->setState(Minion::State::IDLING);
	    continue;
	}
    // Get enemy cards with taunt
    std::vector<std::reference_wrapper<Card>> taunt_cards = m_board->getPlayerCardsViewWithTaunt(*attacker);
    // Select a random card of the attacking player
    int card_to_attack = rand() % player_cards.size();
    // If the enemy has taunt cards, attack a random taunt card
    if (taunt_cards.size() > 0)
    {
        card_to_attack = rand() % taunt_cards.size();
        // Get index of the taunt card
        card_to_attack = m_board->getCardIndex(taunt_cards[card_to_attack].get());
    }
        // Dynamic cast to minion
        Minion *minion2 = dynamic_cast<Minion *>(&player_cards[card_to_attack].get());
        // Attack the card

        m_cli->clear();
        if (minion->getHealth() > 0)
        {
        minion->attackEnemy(*minion2);
        std::cout << minion->getName() << " attacks " << minion2->getName() << std::endl;
        }

        m_cli->drawBoard(*m_board, *m_player1, *m_bot);
        std::this_thread::sleep_for(std::chrono::seconds(3));

        minion->setState(Minion::State::IDLING);
        minion2->setState(Minion::State::IDLING);

        m_board->destroyCards();
        player_cards = m_board->getPlayerCardsView(*attacker);

        m_cli->clear();
        m_cli->drawBoard(*m_board, *m_player1, *m_bot);
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
}
