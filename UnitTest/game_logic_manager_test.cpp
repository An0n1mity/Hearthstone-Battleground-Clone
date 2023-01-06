#include "../GameLogicManager.h"

int main(int, char **)
{
	// Create a game logic manager
	GameLogicManager game = GameLogicManager();

	game.recruitementPhase();
	game.battlePhase();
	return 0;
}
