#ifndef HEROES_H
#define HEROES_H

#include "Cards.h"

// Heroes are a type of card
class Hero : public Card
{
    // Heroes have health and attack points
private:
    unsigned int m_health_points;

public:
    Hero(unsigned int health_points) : Card(0), m_health_points(health_points) {}
    virtual ~Hero() {}

    // Print the type of the card
    void printType() const override { std::cout << "Hero" << std::endl; }
};

#endif