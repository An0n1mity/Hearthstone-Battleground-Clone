#include "Minions.h"

class Murlock : public Minion
{
public:
    Murlock(unsigned int health_points, unsigned int attack_points, std::vector<std::unique_ptr<Effect>> effects = {}) : Minion(health_points, attack_points, std::move(effects)) {}
    virtual ~Murlock() {}
    virtual void printType() const override { std::cout << "Murlock"; }
};

class Beast : public Minion
{
public:
    Beast(unsigned int health_points, unsigned int attack_points, std::vector<std::unique_ptr<Effect>> effects = {}) : Minion(health_points, attack_points, std::move(effects)) {}
    virtual ~Beast() {}
    virtual void printType() const override { std::cout << "Beast"; }
};

class Mech : public Minion
{
public:
    Mech(unsigned int health_points, unsigned int attack_points, std::vector<std::unique_ptr<Effect>> effects = {}) : Minion(health_points, attack_points, std::move(effects)) {}
    virtual ~Mech() {}
    virtual void printType() const override { std::cout << "Mech"; }
};

class Demon : public Minion
{
public:
    Demon(unsigned int health_points, unsigned int attack_points, std::vector<std::unique_ptr<Effect>> effects = {}) : Minion(health_points, attack_points, std::move(effects)) {}
    virtual ~Demon() {}
    virtual void printType() const override { std::cout << "Demon"; }
};

class Dragon : public Minion
{
public:
    Dragon(unsigned int health_points, unsigned int attack_points, std::vector<std::unique_ptr<Effect>> effects = {}) : Minion(health_points, attack_points, std::move(effects)) {}
    virtual ~Dragon() {}
    virtual void printType() const override { std::cout << "Dragon"; }
};

class Pirate : public Minion
{
public:
    Pirate(unsigned int health_points, unsigned int attack_points, std::vector<std::unique_ptr<Effect>> effects = {}) : Minion(health_points, attack_points, std::move(effects)) {}
    virtual ~Pirate() {}
    virtual void printType() const override { std::cout << "Pirate"; }
};

class Elemental : public Minion
{
public:
    Elemental(unsigned int health_points, unsigned int attack_points, std::vector<std::unique_ptr<Effect>> effects = {}) : Minion(health_points, attack_points, std::move(effects)) {}
    virtual ~Elemental() {}
    virtual void printType() const override { std::cout << "Elemental"; }
};

class Quilboar : public Minion
{
public:
    Quilboar(unsigned int health_points, unsigned int attack_points, std::vector<std::unique_ptr<Effect>> effects = {}) : Minion(health_points, attack_points, std::move(effects)) {}
    virtual ~Quilboar() {}
    virtual void printType() const override { std::cout << "Quilboar"; }
};

class Menagerie : public Minion
{
public:
    Menagerie(unsigned int health_points, unsigned int attack_points, std::vector<std::unique_ptr<Effect>> effects = {}) : Minion(health_points, attack_points, std::move(effects)) {}
    virtual ~Menagerie() {}
    virtual void printType() const override { std::cout << "Menagerie"; }
};
