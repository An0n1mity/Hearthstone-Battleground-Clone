#include <iostream>
//#include "Player.h"
#include "shop.h"

int main(int, char **)
{
    Player player = Player("Player 1", 1);

    Shop shop;
    shop.createDeck();
    shop.chooseCard(player);
    std::cout << player << '\n';

    // Create a Card AlleyCat
    /*std::unique_ptr<Card> abomination_card = std::unique_ptr<Card>(new AlleyCat());
    // Create a Card DeckSwabbie
    std::unique_ptr<Card> deck_swabbie_card = std::unique_ptr<Card>(new DeckSwabbie());

    // Add heroe to the player
    player.addHero(std::unique_ptr<Hero>(new Rafaam()));

    // Add the card to the deck of the player
    player.addCardToDeck(std::move(abomination_card));
    player.addCardToDeck(std::move(deck_swabbie_card));
    std::cout << player << '\n';*/

    return 0;
}
