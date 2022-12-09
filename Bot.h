#include "Player.h"

class Bot : public Player
{
public : 
    Bot() : Player("Bot", 0) {}
    ~Bot() {}
    void playTurn();
};