#include "game.h"

void Game::startGame()
{
    m_shop->createDeck();
    m_shop->shuffleDeck();   
}

void Game::deckPhase()
{
    m_shop->chooseCard(*m_player1);
    std::cout << *m_player1 << '\n';
    m_shop->chooseCard(*m_player2);
    std::cout << *m_player2 << '\n';
}