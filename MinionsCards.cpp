#include "MinionsCards.h"

/*void AlleyCat::Summon1_1Cat(Card *card)
{
    std::cout << "Summoning a 1/1 Cat" << std::endl;
    // Get the card board
    std::weak_ptr<Board> board = card->getBoard();
    // Create a new card
    std::unique_ptr<Card> newCard = std::make_unique<AlleyCat>();
    // Assign the card to the player
    newCard->setOwner(card->getOwner());
    // Add the card to the board
    // Convert the board to a shared pointer
    std::shared_ptr<Board> board_ptr = board.lock();
    board_ptr->addCard(std::move(newCard));
}*/