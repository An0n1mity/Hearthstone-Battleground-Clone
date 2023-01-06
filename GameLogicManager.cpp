#include "GameLogicManager.h"

// Create the two players that will battle
void GameLogicManager::createPlayers()
{
    std::cout << "Creating players..." << std::endl;
    m_player1 = std::make_unique<Player>("Player 1");
    m_player2 = std::make_unique<Player>("Player 2");
}

// Create the board that will manage the cards
void GameLogicManager::createBoard()
{
    std::cout << "Creating board..." << std::endl;
    m_board = std::make_unique<Board>();
    std::experimental::observer_ptr<Board> board_ptr = std::experimental::make_observer(m_board.get());
    m_player1->linkBoard(board_ptr);
    m_player2->linkBoard(board_ptr);
}

// Create the shop where players will buy and sell cards
void GameLogicManager::createShop()
{
    std::cout << "Creating shop..." << std::endl;
    m_shop = std::make_unique<Shop>();
}

void GameLogicManager::recruitementPhase()
{
    std::cout << "Recruitement phase..." << std::endl;
    // Give gold to the players based on the turn
    m_shop->giveGold(*m_player1, m_turn);
    m_shop->giveGold(*m_player2, m_turn);

    // Draw 3 cards from the shop
    m_shop->giveChoice(*m_player1);
    m_shop->giveChoice(*m_player2);

}

void GameLogicManager::battlePhase()
{
    std::cout << "Battle phase..." << std::endl;
    // Randomly choose a player to start
    int player_to_start = rand() % 2;
    // Select the player that will start
    Player &player = (player_to_start == 0) ? *m_player1 : *m_player2;
    // Select the player that will wait
    Player &player2 = (player_to_start == 0) ? *m_player2 : *m_player1;

    // Get player cards on board
    std::vector<std::reference_wrapper<Card>> player_cards = m_board->getPlayerCardsView(player);
    std::vector<std::reference_wrapper<Card>> player2_cards = m_board->getPlayerCardsView(player2);
    // For each card of the attacking player
    for (auto card : player_cards)
    {
        // Select a random card of the defending player
        int card_to_attack = rand() % player2_cards.size();
        // Dynamic cast to minion
        Minion *minion = dynamic_cast<Minion *>(&card.get());
        Minion *minion2 = dynamic_cast<Minion *>(&player2_cards[card_to_attack].get());
        // Attack the card
        std::cout << player.getName() << " attacks with " << minion->getName() << " "
                  << minion2->getName() << " of " << player2.getName() << std::endl;
        std::cout << "Before attack: " << minion2->getHealth() << std::endl;
        minion->attackEnemy(*minion2);
	std::cout << "After attack: " << minion2->getHealth() << std::endl;
    }

    // For each card of the defending player
    for (auto card : player2_cards)
    {
        // Select a random card of the attacking player
        int card_to_attack = rand() % player_cards.size();
        // Dynamic cast to minion
        Minion *minion = dynamic_cast<Minion *>(&card.get());
        Minion *minion2 = dynamic_cast<Minion *>(&player_cards[card_to_attack].get());
        // Attack the card
        minion->attackEnemy(*minion2);
    }
}
