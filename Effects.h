#ifndef EFFECTS_H
#define EFFECTS_H

#include <vector>
#include <memory>
#include <iostream>

class Card;

class Effect
{

public:
    enum ActivationPhase_e
    {
        // Activate when the card is played from hand
        ON_HAND,
        // Up until the card is dead
        UNTIL_DEATH,
        // Activate when the card is dead
        ON_DEATH,
	    // Activate while the card is not damaged
	    UNTIL_DAMAGE,
        // Activate when the card is damaged
        ON_DAMAGE,
        // Activate when the card attack
        ON_ATTACK,
        // Activate when the shop is upgrade
        ON_UPGRADE,
        // Activate when the card gain attaque
        ON_GAIN_ATTACK,
        // Activate when an other card is played and is a Deathrattle
        ON_FRIENDLY_DEATHRATTLE
    };
    Effect(enum ActivationPhase_e activation_phase, void (*effect_function)(Card *), Card *card = nullptr) : m_activation_phase(activation_phase), m_effect_function(effect_function), m_card(card) {}
    virtual ~Effect() {}

    enum ActivationPhase_e getActivationPhase() const { return m_activation_phase; }
    void activate() const { m_effect_function(m_card); }

    // Test function
    void test() const { std::cout << "Effect activated!\n"; }

protected:
    // The card link to the effect
    Card *m_card;
    enum ActivationPhase_e m_activation_phase;
    // Pointer to the function that will be called when the effect is activated
    void (*m_effect_function)(Card *card);
};

class Battlecry : public Effect
{
public:
    Battlecry(void (*effect_function)(Card *), Card *card = nullptr) : Effect(ON_HAND, effect_function, card) {}
    virtual ~Battlecry() {}
};

class Taunt : public Effect
{
public:
    Taunt(void (*effect_function)(Card *), Card *card) : Effect(ON_DAMAGE, effect_function, card) {}
    virtual ~Taunt() {}
};

class Deathrattle : public Effect
{
public:
    Deathrattle(void (*effect_function)(Card *), Card *card) : Effect(ON_DEATH, effect_function, card) {}
    virtual ~Deathrattle() {}
};

class DivineShield : public Effect
{
public:
    DivineShield(void (*effect_function)(Card *), Card *card) : Effect(UNTIL_DAMAGE, effect_function, card) {}
    virtual ~DivineShield() {}
};

class Attack : public Effect
{
public:
    Attack(void (*effect_function)(Card *), Card *card) : Effect(ON_ATTACK, effect_function, card) {}
    virtual ~Attack() {}
};

class Upgrade : public Effect
{
public:
    Upgrade(void (*effect_function)(Card *), Card *card) : Effect(ON_UPGRADE, effect_function, card) {}
    virtual ~Upgrade() {}
};

class GainAttack : public Effect
{   
public:
    GainAttack(void (*effect_function)(Card *), Card *card) : Effect(ON_GAIN_ATTACK, effect_function, card) {}
    virtual ~GainAttack() {}
};

class FriendlyDeathrattle : public Effect
{   
public:
    FriendlyDeathrattle(void (*effect_function)(Card *), Card *card) : Effect(ON_FRIENDLY_DEATHRATTLE, effect_function, card) {}
    virtual ~FriendlyDeathrattle() {}
};

#endif
