#ifndef CARDS_H
#define CARDS_H

#include <iostream>
#include <string>

class Card
{

protected:
    const unsigned int m_gold_cost;
    virtual void printType() const = 0;
    virtual void printName() const = 0;

public:
    Card(unsigned int gold_cost) : m_gold_cost(gold_cost) {}
    virtual ~Card() {}
    unsigned int getManaCost() const { return m_gold_cost; }
    void print() const
    {
        std::cout << "{Card type: ";
        printType();
        std::cout << "; Card name: ";
        printName();
        std::cout << "; Card cost: " << m_gold_cost << "}\n";
    }
};

#endif