#include "../Player.h"
#include "../Shop.h"

int main()
{
    // Create a shop
    Shop shop = Shop();
    // Create a player
    Player player = Player("Player 1");
    std::cout << player << '\n';
    // Give gold to the player
    shop.giveGold(player, 3);
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

    return 0;
}