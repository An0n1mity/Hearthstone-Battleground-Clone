#include <iostream>
#include "Player.h"

int main(int, char **)
{
    Player player = Player("Player 1");

    // Create a Card AlleyCat
    std::unique_ptr<Card> alleycat = std::unique_ptr<Card>(new AlleyCat());
    // activate the effect of the card
    alleycat->applyEffects();
    // Add the card to the deck of the player
    player.addCardToDeck(std::move(alleycat));

    std::cout << player << '\n';

    return 0;
}
