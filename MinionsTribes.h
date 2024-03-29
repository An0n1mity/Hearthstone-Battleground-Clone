#ifndef MINIONSTRIBES_H
#define MINIONSTRIBES_H

#include "Minions.h"

class Murlock : public Minion
{
public:
    Murlock(const unsigned int rank, unsigned int health_points, unsigned int attack_points, std::vector<std::unique_ptr<Effect>> effects = {}) : Minion(rank, health_points, attack_points, std::move(effects)) {}
    virtual ~Murlock() {}
    virtual void printType() const override { std::cout << "Murlock"; }
    virtual std::string getType() const override { return "Murlock"; }
};

class Beast : public Minion
{
public:
    Beast(const unsigned int rank, unsigned int health_points, unsigned int attack_points, std::vector<std::unique_ptr<Effect>> effects = {}) : Minion(rank, health_points, attack_points, std::move(effects)) {}
    virtual ~Beast() {}
    virtual void printType() const override { std::cout << "Beast"; }
    virtual std::string getType() const override { return "Beast"; }
};

class Mech : public Minion
{
public:
    Mech(const unsigned int rank, unsigned int health_points, unsigned int attack_points, std::vector<std::unique_ptr<Effect>> effects = {}) : Minion(rank, health_points, attack_points, std::move(effects)) {}
    virtual ~Mech() {}
    virtual void printType() const override { std::cout << "Mech"; }
    virtual std::string getType() const override { return "Mech"; }
};

class Demon : public Minion
{
public:
    Demon(const unsigned int rank, unsigned int health_points, unsigned int attack_points, std::vector<std::unique_ptr<Effect>> effects = {}) : Minion(rank, health_points, attack_points, std::move(effects)) {}
    virtual ~Demon() {}
    virtual void printType() const override { std::cout << "Demon"; }
    virtual std::string getType() const override { return "Demon"; }
};

class Dragon : public Minion
{
public:
    Dragon(const unsigned int rank, unsigned int health_points, unsigned int attack_points, std::vector<std::unique_ptr<Effect>> effects = {}) : Minion(rank, health_points, attack_points, std::move(effects)) {}
    virtual ~Dragon() {}
    virtual void printType() const override { std::cout << "Dragon"; }
    virtual std::string getType() const override { return "Dragon"; }
};

class Pirate : public Minion
{
public:
    Pirate(const unsigned int rank, unsigned int health_points, unsigned int attack_points, std::vector<std::unique_ptr<Effect>> effects = {}) : Minion(rank, health_points, attack_points, std::move(effects)) {}
    virtual ~Pirate() {}
    virtual void printType() const override { std::cout << "Pirate"; }
    virtual std::string getType() const override { return "Pirate"; }
};

class Elemental : public Minion
{
public:
    Elemental(const unsigned int rank, unsigned int health_points, unsigned int attack_points, std::vector<std::unique_ptr<Effect>> effects = {}) : Minion(rank, health_points, attack_points, std::move(effects)) {}
    virtual ~Elemental() {}
    virtual void printType() const override { std::cout << "Elemental"; }
    virtual std::string getType() const override { return "Elemental"; }
};

class Quilboar : public Minion
{
public:
    Quilboar(const unsigned int rank, unsigned int health_points, unsigned int attack_points, std::vector<std::unique_ptr<Effect>> effects = {}) : Minion(rank, health_points, attack_points, std::move(effects)) {}
    virtual ~Quilboar() {}
    virtual void printType() const override { std::cout << "Quilboar"; }
    virtual std::string getType() const override { return "Quilboar"; }
};

class Naga : public Minion
{
public:
    Naga(const unsigned int rank, unsigned int health_points, unsigned int attack_points, std::vector<std::unique_ptr<Effect>> effects = {}) : Minion(rank, health_points, attack_points, std::move(effects)) {}
    virtual ~Naga() {}
    virtual void printType() const override { std::cout << "Naga"; }
    virtual std::string getType() const override { return "Naga"; }
};
#endif
