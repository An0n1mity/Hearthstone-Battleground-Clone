#include "Board.h"
#include "Player.h"
#include <algorithm>
// Class to render the game on the command line
class CLI
{
    public:
    enum cli_choice 
    {
	BUY,
	SELL,
	UPGRADE,
	PLAY,
	BATTLE,
	EXIT,
	INVALID
    };
    struct cli_input
    {
	enum cli_choice choice;
	int card;
    };	
	// Refresh the terminal
	void clear();
	// Draw the player and bot cards on the board
	void drawBoard(const Board &board, const Player &player, const Player &bot);
	// Convert the card to a string
	std::string cardToString(const Card &card);
	// Draw a card 
	void drawCards(std::vector<std::reference_wrapper<Card>> &cards);
	// Draw the shop cards choices for the player 
	void drawChoices(const Player& player);
	// Draw the hand of the player 
	void drawHand(const Player& player);
	// Get the input from the Player
	cli_input getInput(const Player& player);
	// Draw players stats 
	void drawStats(const Player& player);
};
