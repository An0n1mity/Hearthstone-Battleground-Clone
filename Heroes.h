#pragma once
#include "Cards.h"

// Heroes are a type of card
class Hero : public Card
{
    // Heroes have health and attack points
protected:
    std::string m_name;
    unsigned int m_health_points;

public:
    Hero() : Card(0), m_name("Default"), m_health_points(20) {}
    Hero(std::string name) : Card(0), m_name(name), m_health_points(20) {}
    virtual ~Hero() {}

    // Print the type of the card
    virtual void printType() const override { std::cout << "Hero" << std::endl; }
    // Print the name of the hero
    virtual void printName() const override { std::cout << m_name << std::endl; }
};

class Rafaam : public Hero
{
    public:
        Rafaam() : Hero("Arch-Villain Rafaam") {}
        virtual~Rafaam() {}
};

class Brukan : public Hero
{
    public:
        Brukan() : Hero("Bru'kan") {}
        virtual~Brukan() {}
};

class Hooktusk : public Hero
{
    public:
        Hooktusk() : Hero("Captain Hooktusk") {}
        virtual~Hooktusk() {}
};

class Cookie : public Hero
{
    public:
        Cookie() : Hero("Cookie the Cook") {}
        virtual~Cookie() {}
};

class Omu : public Hero
{
    public:
        Omu() : Hero("Forest Warden Omu") {}
        virtual~Omu() {}
};

class Galwing : public Hero
{
    public:
        Galwing() : Hero("Galwing") {}
        virtual~Galwing() {}
};

class Nguyen : public Hero
{
    public:
        Nguyen() : Hero("Master Nguyen") {}
        virtual~Nguyen() {}
};

class Millhouse : public Hero
{
    public:
        Millhouse() : Hero("Millhouse Manastorm") {}
        virtual~Millhouse() {}
};

class Holmes : public Hero
{
    public:
        Holmes() : Hero("Murloc Holmes") {}
        virtual~Holmes() {}
};

class Mutanus : public Hero
{
    public:
        Mutanus() : Hero("Mutanus the Devourer") {}
        virtual~Mutanus() {}
};

class Pyramad : public Hero
{
    public:
        Pyramad() : Hero("Pyramad") {}
        virtual~Pyramad() {}
};

class Silas : public Hero
{
    public:
        Silas() : Hero("Silas Darkmoon") {}
        virtual~Silas() {}
};