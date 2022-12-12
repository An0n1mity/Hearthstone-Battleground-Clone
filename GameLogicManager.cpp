#include "GameLogicManager.h"

void GameLogicManager::createPlayers()
{
    m_player1 = std::make_unique<Player>("Player 1");
    m_player2 = std::make_unique<Player>("Player 2");
}

void GameLogicManager::createBoard()
{
    m_board = std::make_unique<Board>();
}

void GameLogicManager::createShop()
{
    m_shop = std::make_unique<Shop>();
}

void GameLogicManager::recruitementPhase()
{
    // Give gold to the players based on the turn
    m_shop->giveGold(*m_player1, m_turn);
    m_shop->giveGold(*m_player2, m_turn);

    // Draw 3 cards from the shop
    std::vector<std::reference_wrapper<Card>> cards = m_shop->drawCards(*m_player1);
    std::vector<std::reference_wrapper<Card>> cards2 = m_shop->drawCards(*m_player2);
}
