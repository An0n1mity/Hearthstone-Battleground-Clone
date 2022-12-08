#include "Board.h"

std::vector<std::shared_ptr<Card>> Board::getPlayerCards(Player *player)
{
    std::vector<std::shared_ptr<Card>> player_cards;
    for (auto card : m_cards)
    {
        if (card->getOwner() == player)
        {
            player_cards.push_back(card);
        }
    }
    return player_cards;
}

void Board::giveCardFromBoard(int index, Shop *shop, Player *player)
{
    // Sanity check
    if (index < 0 || index >= m_cards.size() || m_cards.empty())
        return;

    int counter = 0;
    for(int i = 0; i < m_cards.size(); i++)
    {
        if (m_cards[i]->getOwner() == player)
        {
            counter++;
        }
        if (counter == index)
        {
            counter = i;
            break;
        }
    }

    // Give the card to the shop
    std::unique_ptr<Card> card = std::make_unique<Card>(std::move(m_cards[counter]));
    shop->sellCard(std::move(card), card->getOwner());
}