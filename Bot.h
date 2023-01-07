#ifndef BOT_H
#define BOT_H

#include "Player.h"

class Bot : public Player
{
public:
    Bot(std::string name) : Player(name) {}
    virtual ~Bot() {}
    void playTurn(Shop &shop);
};

#endif