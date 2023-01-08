#include "../GameLogicManager.h"

int main(int, char **)
{
	// Create a game logic manager
	GameLogicManager game = GameLogicManager();
	while(true)
	{
	    CLI::cli_input input = game.recruitementPhase();
	    if(input.choice == CLI::EXIT)
			break;
	    input = game.battlePhase();
		if(input.choice == CLI::EXIT)
			break;
	}
	return 0;
}
