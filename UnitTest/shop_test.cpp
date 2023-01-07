#include "../CLI.h"
#include "../Shop.h"
#include "../Player.h"

int main(int, char **)
{
	Shop shop = Shop();
	Player player1 = Player("Player 1");

	shop.giveGold(player1, 10);

	CLI cli = CLI();
	while(true){
	    shop.giveChoice(player1);
	    cli.drawChoices(player1);
	    cli.drawHand(player1);
	    std::cout << "PLAYER GOLD: " << player1.getGolds() << '\n';
	    CLI::cli_input player_input = cli.getInput(player1);
	    if(player_input.choice == CLI::EXIT){
	        break;
	    }
	        
	    // If buy card 
	    if (player_input.choice == CLI::BUY)
	    {
	       player1.selectCardFromChoices(player_input.card, shop);
	    }
	    else if(player_input.choice == CLI::SELL){
	        player1.sellCardFromHand(player_input.card, shop);
	    }
	    player1.resetChoices();
	    cli.drawHand(player1);
	}

	


	return 0;
}
