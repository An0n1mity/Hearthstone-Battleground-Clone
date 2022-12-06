#ifndef CARDS_H
#define CARDS_H

#include <iostream>
#include <string>

class Card
{
public:
    Card() {}
    virtual ~Card() {}
    virtual void printType() const = 0;
    virtual void printName() const = 0;
    void print() const
    {
        std::cout << "{Card type: ";
        printType();
        std::cout << "; Card name: ";
        printName();
    }
};

#endif