#include <iostream>
#include "Player.h"

int main(int, char **)
{
    // Create a board
    std::shared_ptr<Board> board = std::shared_ptr<Board>(new Board());

    // Create 2 players
    Player player = Player("Player 1");
    Player player2 = Player("Player 2");

    // Link the board to the players
    player.linkBoard(board);
    player2.linkBoard(board);

    // Create a Card AlleyCat
    std::unique_ptr<Card> alleycat = std::unique_ptr<Card>(new AlleyCat());
    // Create a Card DeckSwabbie
    std::unique_ptr<Card> deckswabbie = std::unique_ptr<Card>(new DeckSwabbie());

    // Add the card to the deck of the player
    player.addCardToHand(std::move(alleycat));
    player2.addCardToHand(std::move(deckswabbie));

    std::cout << player << '\n';
    std::cout << player2 << '\n';

    player.moveCardFromHandToBoard(0);
    player2.moveCardFromHandToBoard(0);

    // Get the cards of the player on the board
    std::vector<std::shared_ptr<Card>> player_cards = board->getPlayerCards(&player);
    for (auto &card : player_cards)
    {
        card->print();
    }

    std::vector<std::shared_ptr<Card>> player2_cards = board->getPlayerCards(&player2);
    for (auto &card : player2_cards)
    {
        card->print();
    }

    // Print the card on the board
    board->printCards();

    return 0;
}
