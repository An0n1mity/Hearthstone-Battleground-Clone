#include <iostream>
#include "Player.h"
#include "Shop.h"

int main(int, char **)
{
    // Create a shop
    Shop shop = Shop();

    // Create a board
    std::shared_ptr<Board> board = std::shared_ptr<Board>(new Board());

    // Create 2 players
    Player player = Player("Player 1");
    Player player2 = Player("Player 2");

    // Give gold to the players
    shop.giveGold(player, 10);
    // Draw 3 cards from the shop
    shop.drawCards(player);
    // Display the cards
    shop.displayCards();

    // Player 1 buy a card
    int choice = 0;
    shop.buyCard(choice, player);
    // Sell the card to the shop
    player.sellCardFromHand(choice, &shop);

    // Link the board to the players
    player.linkBoard(board);
    player2.linkBoard(board);

    // Create a Card AlleyCat
    std::unique_ptr<Card> alleycat = std::unique_ptr<Card>(new AlleyCat());
    // Create a Card DeckSwabbie
    std::unique_ptr<Card> deckswabbie = std::unique_ptr<Card>(new DeckSwabbie());

    // Add the card to the deck of the player
    player.addCardToHand(alleycat);
    player2.addCardToHand(deckswabbie);

    std::cout << player << '\n';
    std::cout << player2 << '\n';

    player.moveCardFromHandToBoard(0);
    player2.moveCardFromHandToBoard(0);

    // Get the cards of the player on the board
    std::vector<std::weak_ptr<Card>> player_cards = board->getPlayerCards(&player);
    for (auto &card : player_cards)
    {
        // Convert to a shared pointer
        std::shared_ptr<Card> card_ptr = card.lock();
        // Print the card
        card_ptr->print();
    }

    std::vector<std::weak_ptr<Card>> player2_cards = board->getPlayerCards(&player2);
    for (auto &card : player2_cards)
    {

        // Convert to a shared pointer
        std::shared_ptr<Card> card_ptr = card.lock();
        // Print the card
        card_ptr->print();
    }

    // Print the card on the board
    board->printCards();

    return 0;
}
