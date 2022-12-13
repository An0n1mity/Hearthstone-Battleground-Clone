#include "../Player.h"
#include "../Shop.h"

int main()
{
    unsigned int turn = 0;
    // Create a shop
    Shop shop = Shop();
    // Create a player
    Player player = Player("Player 1");
    std::cout << player << '\n';
    // Give gold to the player
    shop.giveGold(player, turn);
    // Draw 3 cards from the shop
    shop.giveChoice(player);

    std::cout << player << '\n';
    // Give gold to the player
    // Player select a card
    int choice = 0;
    player.selectCardFromChoices(choice, shop);
    std::cout << player << '\n';

    return 0;
}