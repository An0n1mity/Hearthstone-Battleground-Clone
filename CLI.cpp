#include "CLI.h"
#include <string>

void CLI::clear()
{
    // Clear the screen
    std::cout << "\033[2J\033[1;1H";
}

std::string formatString(const std::string& s, size_t lineLength) {
  std::string output;
  size_t start = 0, end = lineLength;
  while (end < s.length()) {
    output += s.substr(start, end - start);
    for (size_t i = s.substr(start, end - start).length(); i < lineLength; i++) {
      output += " ";
    }
    output += "|\n|";
    start = end;
    end += lineLength;
  }
  output += s.substr(start);
  for (size_t i = s.substr(start).length(); i < lineLength; i++) {
    output += " ";
  }
  return output;
}

void CLI::drawBoard(const Board &board, const Player &player, const Player &bot)
{
    std::cout << "Board cards: " << std::endl;
    std::vector<std::reference_wrapper<Card>> player_cards = board.getPlayerCardsView(player);
    std::vector<std::reference_wrapper<Card>> bot_cards = board.getPlayerCardsView(bot);

    std::cout << "Bot cards: " << std::endl;
    drawCards(bot_cards);
    std::cout << "Player cards: " << std::endl;
    drawCards(player_cards);
}

void CLI::drawChoices(const Player &player)
{
    std::cout << "Choices: " << std::endl;
    std::vector<std::reference_wrapper<Card>> choices = player.getChoicesView();
    drawCards(choices);
}

void CLI::drawHand(const Player &player)
{
	std::cout << "Hand: " << std::endl;
	std::vector<std::reference_wrapper<Card>> hand = player.getHandView();
	drawCards(hand);
}

std::string CLI::cardToString(const Card &card)
{
    const Minion *minion = dynamic_cast<const Minion *>(&card);
    int cost = minion->getGoldCost();
    std::string name = minion->getName();
    int health = minion->getHealth();
    int health_len = std::to_string(health).length();
    int attack = minion->getAttack();
    int attack_len = std::to_string(attack).length();
    std::string effect_description = minion->getEffectDescription();
    // Calculate the width of the card based on the longest statistic
    int width = 20;
    // Create the top and bottom borders of the card
    std::string border(width, '-');
	std::string left_border = "| ";
	std::string right_border = " |\033[0m\n";
	// If state of card is attacking or defending
	if (minion->getState() == Minion::State::ATTACKING)
	{
	border = "\033[0;31m" + border + "\033[0m";
	left_border = "\033[0;31m" + left_border + "\033[0m";
	right_border = "\033[0;31m" + right_border;
	}
	else if (minion->getState() == Minion::State::DEFENDING)
	{
	border = "\033[0;32m" + border + "\033[0m";
	left_border = "\033[0;32m" + left_border + "\033[0m";
	right_border = "\033[0;32m" + right_border;
	}
	std::string spaces(width, ' ');
	std::string output = left_border + border + right_border;

	// Add the name statistic to the card
	output += left_border + name + std::string(width - name.length(), ' ') + right_border;

	for (int i = 0; i < 2; i++)
	{
	output += left_border + spaces + right_border;
	}

	std::string formated = formatString(effect_description, width + 1);
	output += left_border + formated + right_border;

	for (int i = 0; i < 2; i++)
	{
	output += left_border + spaces + right_border;
	}

	// Add the health/attack statistic to the card
	output += left_border + "\033[0;33m" + std::to_string(attack) + "\033[0m" + std::string(width - std::to_string(health).length() - std::to_string(attack).length(), ' ') + "\033[1;31m" + std::to_string(health) + "\033[0m" + right_border;

	// Add the bottom border of the card
	output += left_border + border + right_border;

	return output;
}

void CLI::drawCards(std::vector<std::reference_wrapper<Card>> &cards_)
{
	std::vector<std::string> cards;
	for (auto &card : cards_)
	{
	cards.push_back(cardToString(card));
	}
	// Split the cards into lines
	std::vector<std::vector<std::string>> lines(cards.size());
	for (int c = 0; c < cards.size(); c++)
	{
	size_t start = 0, end = cards[c].find('\n');
	while (end != std::string::npos)
	{
	  lines[c].push_back(cards[c].substr(start, end - start));
	  start = end + 1;
	  end = cards[c].find('\n', start);
	}
	} // Combine the lines of the cards
	std::string output;
	for (int i = 0; i < 10; i++)
	{
	for (int c = 0; c < cards.size(); c++)
	{
	  output += lines[c][i];
	  if (c < cards.size() - 1)
	  {
		  output += "  ";
	  }
	}
	output += "\n";
	}
	std::cout << output;
	// Reset the colour
	std::cout << "\033[0m";
}

CLI::cli_input CLI::getInput(const Player& player)
{
	std::string input;
	std::cout << "CHOICES" << std::endl;
	std::cout << "1 BUY" << std::endl;
	std::cout << "2 SELL" << std::endl;
	std::cout << "3 PLAY CARD" << std::endl;
	std::cout << "4 BATTLE" << std::endl;
	std::cout << "5 EXIT" << std::endl;

	while(true){ 
	    std::cout << "Enter your choice: ";
	    std::cin >> input;

	    if (input == "1")
	    {
		// Get the player card choices 
		std::vector<std::reference_wrapper<Card>> choices = player.getChoicesView();
		if (choices.size() == 0)
		{
		    std::cout << "No cards to buy" << std::endl;
		    continue;
		}
		while(true)
		{
		    std::cout << "CARD TO BUY : ";
		    std::cin >> input;
		    int input_i = std::stoi(input);

		    if(input_i > 0 && input_i <= choices.size())
			return {BUY, input_i-1};
		    
		}
	    }
	    else if (input == "2")
	    {
		// Get the player hand 
		std::vector<std::reference_wrapper<Card>> hand = player.getHandView();
		if (hand.size() == 0)
		{
		    std::cout << "No cards to sell" << std::endl;
		    continue;
		}
		while(true){
		    std::cout << "CARD TO SELL : ";
		    std::cin >> input;
		    int input_i = std::stoi(input);

		    if(input_i > 0 && input_i <= hand.size()) 
			return {SELL, input_i-1};
		}
	    }
	    else if (input == "3")
	    {
		// Get the player hand 
		std::vector<std::reference_wrapper<Card>> hand = player.getHandView();
		if (hand.size() == 0)
		{
		    std::cout << "No cards to play" << std::endl;
		    continue;
		}
		while(true){
		    std::cout << "CARD TO PLAY : ";
		    std::cin >> input;
		    int input_i = std::stoi(input);

		    if(input_i > 0 && input_i <= hand.size())
			return {PLAY, input_i-1};
		}
	    }
	    else if (input == "4")
	    {
		return {BATTLE, 0};
	    }

	    else if (input == "5")
	    {
		return {EXIT, std::stoi(input)};
	    }
	}
}


void CLI::drawStats(const Player &player)
{
    std::cout << "PLAYER STATS : " << player.getName() << " " <<  player.getHealth() << " HP" << std::endl;
}
