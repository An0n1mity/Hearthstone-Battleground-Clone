#include "../Player.h"
#include "../Board.h"
#include "../Shop.h"

#include "../CLI.h"

int main(int, char **)
{
	// Create a shop
	Shop shop = Shop();

	// Create a board
	Board board = Board();

	// Create a player 
	Player player = Player("Player 1");
	Player bot = Player("Bot");
	// Give gold to the players
	shop.giveGold(player, 10);

	// Link the board to the players
	player.linkBoard(std::experimental::make_observer(&board));


	CLI cli = CLI();
	CLI::cli_input input;
	bool end = false;
	while(!end)
	{
	    // Draw the Board
	    cli.drawBoard(board, player, bot);
	    // Give the choice to the player 
	    shop.giveChoice(player);
	    // Draw the choices 
	    cli.drawChoices(player);
	    // Draw the hand of the player 
	    cli.drawHand(player);
	    // Get player's input 
	    input = cli.getInput(player);
	    switch(input.choice)
	    {
		case CLI::BUY:
		    player.selectCardFromChoices(input.card, shop); 
		    break;
		case CLI::SELL:
		    player.sellCardFromHand(input.card, shop);
		    break;
		case CLI::PLAY:
		    player.moveCardFromHandToBoardLeft(input.card);
		    break;
		case CLI::EXIT:
		    end = true;
		    break;
	    }
	    // Clear choices 
	    player.resetChoices();

	}


	return 0;
}
