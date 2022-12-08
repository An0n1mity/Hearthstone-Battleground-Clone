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
        // Activate when the card is damaged
        UNTIL_DAMAGE,
    };
    Effect(enum ActivationPhase_e activation_phase, void (*effect_function)(void)) : m_activation_phase(activation_phase), m_effect_function(effect_function) {}
    virtual ~Effect() {}

    void activate() const { m_effect_function(); }

protected:
    enum ActivationPhase_e m_activation_phase;
    // Pointer to the function that will be called when the effect is activated
    void (*m_effect_function)(void);
};

class Battlecry : public Effect
{
public:
    Battlecry(void (*effect_function)(void)) : Effect(ON_HAND, effect_function) {}
    virtual ~Battlecry() {}
};

class Taunt : public Effect
{
public:
    Taunt(void (*effect_function)(void)) : Effect(UNTIL_DEATH, effect_function) {}
    virtual ~Taunt() {}
};

class Deathrattle : public Effect
{
public:
    Deathrattle(void (*effect_function)(void)) : Effect(ON_DEATH, effect_function) {}
    virtual ~Deathrattle() {}
};

class DivineShield : public Effect
{
public:
    DivineShield(void (*effect_function)(void)) : Effect(UNTIL_DAMAGE, effect_function) {}
    virtual ~DivineShield() {}
};
