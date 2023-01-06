#include "../GameLogicManager.h"

int main(int, char **)
{
	// Create a game logic manager
	GameLogicManager game = GameLogicManager();

	for (size_t i = 0; i < 3; i++)
	{
		game.recruitementPhase();
		game.battlePhase();
	}
	return 0;
}
