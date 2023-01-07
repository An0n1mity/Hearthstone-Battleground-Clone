#include "../GameLogicManager.h"

int main(int, char **)
{
	// Create a game logic manager
	GameLogicManager game = GameLogicManager();
	while(true)
	{
	    game.recruitementPhase();
	    game.battlePhase();
	}
	return 0;
}
