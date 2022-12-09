#include "Cards.h"
#include "Player.h"
void Card::print() const
{
    std::cout << "{Card type: ";
    printType();
    std::cout << "; Card name: ";
    printName();
    std::cout << "; Card cost: " << m_gold_cost;
    // If owner is not null, print the owner's name
    if (m_owner)
        std::cout << "; Owner: " << m_owner->getName() << "}\n";
    else
        std::cout << "; Owner: None}\n";
}
