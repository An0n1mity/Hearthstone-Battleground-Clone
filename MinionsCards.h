#include "MinionsTribes.h"

class AlleyCat : public Beast
{
public:
    AlleyCat() : Beast(1, 1) {}
    virtual ~AlleyCat() {}
    virtual void printName() const override { std::cout << "AlleyCat"; }
};

class DeckSwabbie : public Pirate
{
public:
    DeckSwabbie() : Pirate(2, 2) {}
    virtual ~DeckSwabbie() {}
    virtual void printName() const override { std::cout << "DeckSwabbie"; }
};