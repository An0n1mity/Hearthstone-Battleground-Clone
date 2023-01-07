#include "../Bot.h"
#include "../Shop.h"

int main()
{
    // Create a shop
    Shop shop = Shop();
    // Create a board
    std::unique_ptr<Board> board = std::unique_ptr<Board>(new Board());
    // Create a player
    Player player = Player("Player 1");
    Bot bot = Bot("Bot 1");

    // Link the board to the players
    player.linkBoard(std::experimental::make_observer(board.get()));
    bot.linkBoard(std::experimental::make_observer(board.get()));

    std::cout << player << '\n';
    // Give gold to the player
    shop.giveGold(player, 3);
    shop.giveGold(bot, 3);
    // Draw 3 cards from the shop
    shop.giveChoice(player);

    std::cout << player << '\n';
    // Player select a card
    int choice = 0;
    player.selectCardFromChoices(choice, shop);
    std::cout << player << '\n';

    // Player sell a card from his hand
    int card = 0;
    player.sellCardFromHand(card, shop);
    player.resetChoices();

    std::cout << player << '\n';

    shop.giveChoice(player);

    std::cout << player << '\n';

    bot.playTurn(shop);

    std::cout << bot << '\n';

    return 0;
}