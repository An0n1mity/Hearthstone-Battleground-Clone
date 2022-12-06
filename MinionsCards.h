#include "MinionsTribes.h"

class AlleyCat : public Beast
{
private:
    static void Summon1_1Cat()
    {
        std::cout << "Summoning a 1/1 Cat" << std::endl;
    }

public:
    AlleyCat() : Beast(1, 1)
    {
        // Create a battle cry effect that have a pointer to the function Summon1_1Cat
        Effect *battlecry = new Battlecry(Summon1_1Cat);
        // Add the effect to the vector of effects
        m_effects.push_back(std::unique_ptr<Effect>(battlecry));
    }
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