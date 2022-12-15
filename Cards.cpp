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
    // Aquire the lock on the weak pointer
    std::experimental::observer_ptr<Player> player_ptr = m_owner;
    if (player_ptr)
        std::cout << "; Owner: " << player_ptr->getName() << "}\n";
    else
        std::cout << "; Owner: None}\n";
}
