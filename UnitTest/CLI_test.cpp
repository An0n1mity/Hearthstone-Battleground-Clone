#include "../GameLogicManager.h"
#include "../CLI.h"
#include "../Player.h"

int main(int, char **)
{
	// Create a game logic manager
	GameLogicManager game = GameLogicManager();
	Board &board = game.getBoard();
	Shop &shop = game.getShop();
	Player &player1 = game.getPlayer1();
	Player &player2 = game.getPlayer2();

	CLI cli = CLI();
	game.recruitementPhase();
	cli.drawChoices(player1);
	CLI::cli_input player_input = cli.getInput(player1);
	std::cout << "Player input: " << player_input.choice << " " << player_input.card << '\n';
	
	// If buy card 
	if (player_input.choice == CLI::BUY)
	{
	   player1.selectCardFromChoices(player_input.card, shop);
	}
	


	return 0;
}
