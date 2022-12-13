#include <iostream>
#include <experimental/memory>
#include "Player.h"
#include "Shop.h"

int main(int, char **)
{
    // Create a shop
    Shop shop = Shop();

    // Create a board
    std::unique_ptr<Board> board = std::unique_ptr<Board>(new Board());

    // Create 2 players
    Player player = Player("Player 1");
    Player player2 = Player("Player 2");

    // Give gold to the players
    shop.giveGold(player, 10);
    // Draw 3 cards from the shop
    shop.giveChoice(player);

    // Player 1 buy a card
    int choice = 0;
    shop.buyCard(choice, player);

    // Sell the card to the shop
    player.sellCardFromHand(choice, shop);

    // shop.reDrawCards(player);
    // shop.buyCard(choice, player);

    // Link the board to the players
    player.linkBoard(std::experimental::make_observer(board.get()));
    player2.linkBoard(std::experimental::make_observer(board.get()));

    // add card to board from hand
    player.moveCardFromHandToBoardLeft(choice);

    // sell card from board
    player.giveCardFromBoard(choice, shop);

    // Create a Card AlleyCat
    std::unique_ptr<Card> alleycat = std::unique_ptr<Card>(new AlleyCat());
    alleycat->linkPlayer(std::experimental::make_observer(&player));
    // Create a Card DeckSwabbie
    std::unique_ptr<Card> deckswabbie = std::unique_ptr<Card>(new DeckSwabbie());
    deckswabbie->linkPlayer(std::experimental::make_observer(&player2));
    // Add the card to the deck of the player
    player.addCardToHand(alleycat);
    player2.addCardToHand(deckswabbie);

    std::cout << player << '\n';
    std::cout << player2 << '\n';

    player.moveCardFromHandToBoardLeft(0);
    player2.moveCardFromHandToBoardLeft(0);

    // Get the cards of the player on the board
    std::vector<std::reference_wrapper<Card>> player_cards = board->getPlayerCardsView(player);
    std::vector<std::reference_wrapper<Card>> player2_cards = board->getPlayerCardsView(player2);

    // Print the card on the board
    board->printCards();
    // shop.putCardBack();

    return 0;
}
