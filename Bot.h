#include "Player.h"

class Card;
class Player;

class Bot : public Player
{
public : 
    Bot() : Player("Bot", 0) {}
    ~Bot() {}
    void playTurn();
};