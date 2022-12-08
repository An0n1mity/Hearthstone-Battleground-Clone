#ifndef BOARD_H
#define BOARD_H

#include <memory>
#include <vector>

#include "Cards.h"
#include "shop.h"

class Player;
class Shop;

class Board
{
private:
    // A vector of cards on the board
    std::vector<std::shared_ptr<Card>> m_cards;

public:
    Board(){};
    // Get the cards own by a certain player on the board
    std::vector<std::shared_ptr<Card>> getPlayerCards(Player *player);
    // Add a card to the board
    void addCard(std::unique_ptr<Card> card) { m_cards.push_back(std::move(card)); }

    void giveCardFromBoard(int index, Shop *shop, Player *player);
};

#endif