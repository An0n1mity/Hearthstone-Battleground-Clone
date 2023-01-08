#ifndef MINIONSCARDS_H
#define MINIONSCARDS_H

#include "MinionsTribes.h"
#include "Board.h"

//
// Beast minions
//

class AlleyCat : public Beast
{

public:
    static void Summon1_1Cat(Card *card)
    {
        Minion::summonMinion<AlleyCat>(card->getBoard(), card);
    }

    AlleyCat() : Beast(1, 1, 1)
    {
	
	// Effect description 
	m_effect_description = "Battlecry: Summon a 1/1 Cat";
        // Create a battle cry effect that have a pointer to the function Summon1_1Cat
        Effect *battlecry = new Battlecry(Summon1_1Cat, this);
        // Add the effect to the vector of effects
        m_effects.push_back(std::unique_ptr<Effect>(battlecry));
    }
    virtual ~AlleyCat() {}
    virtual void printName() const override { std::cout << "AlleyCat"; }
    virtual const std::string getName() const override { return "AlleyCat"; }
};

class Scavenging_Hyena : public Beast
{

public:
    Scavenging_Hyena() : Beast(1, 2, 2){
	// Effect description 
	m_effect_description = "Whenever a friendly Beast dies, gain +2/+1";
    }
    virtual ~Scavenging_Hyena() {}
    virtual void printName() const override { std::cout << "Scavenging Hyena"; }
    virtual const std::string getName() const override { return "Scavenging Hyena"; }
};

class Leapfrogger : public Beast
{

public:
    Leapfrogger() : Beast(2, 3, 3){
	// Effect description 
	m_effect_description = "Deathrattle: Give a friendly beast +1/+1 and this Deathrattle";
    }
    virtual ~Leapfrogger() {}
    virtual void printName() const override { std::cout << "Leapfrogger"; }
    virtual const std::string getName() const override { return "Leapfrogger"; }
};

class Rabid_Saurolisk : public Beast
{

public:
    Rabid_Saurolisk() : Beast(2, 2, 3){
	// Effect description 
	m_effect_description = "After you play a minion with Deathrattle, gain +1/+2";
    }
    virtual ~Rabid_Saurolisk() {}
    virtual void printName() const override { std::cout << "Rabid Saurolisk"; }
    virtual const std::string getName() const override { return "Rabid Saurolisk"; }
};

class HoundMaster : public Beast
{

public:
    HoundMaster() : Beast(3, 3, 4){
	// Effect description 
	m_effect_description = "Battlecry: Give a friendly Beast +2/+2 and Taunt";
    }
    virtual ~HoundMaster() {}
    virtual void printName() const override { std::cout << "HoundMaster"; }
    virtual const std::string getName() const override { return "HoundMaster"; }
};

class Monstrous_macow : public Beast
{

public:
    Monstrous_macow() : Beast(3, 3, 5){
	// Effect description 
	m_effect_description = "After this attacks, trigger another friendly minion's Deathrattle";
    }
    virtual ~Monstrous_macow() {}
    virtual void printName() const override { std::cout << "Monstrous Macow"; }
    virtual const std::string getName() const override { return "Monstrous Macow"; }
};

class Cave_Hydra : public Beast
{

public:
    Cave_Hydra() : Beast(4, 4, 2){
	// Effect description 
	m_effect_description = "Also damages the minions next to whomever this attacks";
    }
    virtual ~Cave_Hydra() {}
    virtual void printName() const override { std::cout << "Cave Hydra"; }
    virtual const std::string getName() const override { return "Cave Hydra"; }
};

class Reanimating_Rattler : public Beast
{

public:
    Reanimating_Rattler() : Beast(4, 3, 5){
	// Effect description 
	m_effect_description = "Battlecry: Give a friendly Beast Reborn";
    }
    virtual ~Reanimating_Rattler() {}
    virtual void printName() const override { std::cout << "Reanimating Rattler"; }
    virtual const std::string getName() const override { return "Reanimating Rattler"; }
};

//
// Pirate minions
//

class DeckSwabbie : public Pirate
{
public:
    DeckSwabbie() : Pirate(1, 2, 2) {
	// Effect description 
	m_effect_description = "Battlecry: Give your weapon +1 Attack";
    }
    virtual ~DeckSwabbie() {}
    virtual void printName() const override { std::cout << "DeckSwabbie"; }
    virtual const std::string getName() const override { return "DeckSwabbie"; }
};

class Scallywag : public Pirate
{
public:
    Scallywag() : Pirate(1, 1, 3) {
	// Effect description 
	m_effect_description = "Deathrattle: Summon a 1/1 Pirate. It attacks immediately";
    }
    virtual ~Scallywag() {}
    virtual void printName() const override { std::cout << "Scallywag"; }
    virtual const std::string getName() const override { return "Scallywag"; }
};

// Summon of Scallywag
class PirateSummon : public Pirate
{
public:
    PirateSummon() : Pirate(1, 1, 1) {
	// Effect description 
	m_effect_description = "Battlecry: Attack immediately";
    }
    virtual ~PirateSummon() {}
    virtual void printName() const override { std::cout << "Pirate"; }
    virtual const std::string getName() const override { return "Pirate"; }
};

class Freedealing_Gambler : public Pirate
{
public:
    Freedealing_Gambler() : Pirate(2, 3, 3) {
    setGoldSell(3);
	// Effect description 
	m_effect_description = "The minion sells for 3 Gold";
    }
    virtual ~Freedealing_Gambler() {}
    virtual void printName() const override { std::cout << "Freedealing Gambler"; }
    virtual const std::string getName() const override { return "Freedealing Gambler"; }
};

class Southsea_Captain : public Pirate
{
public:
    Southsea_Captain() : Pirate(2, 3, 3) {
	// Effect description 
	m_effect_description = "Your other Pirates have +1/+1";
    }
    virtual ~Southsea_Captain() {}
    virtual void printName() const override { std::cout << "Southsea Captain"; }
    virtual const std::string getName() const override { return "Southsea Captain"; }
};

class Salty_Looter : public Pirate
{
public:
    Salty_Looter() : Pirate(3, 5, 4) {
	// Effect description 
	m_effect_description = "Whenever you play a Pirate, gain +1/+1";
    }
    virtual ~Salty_Looter() {}
    virtual void printName() const override { std::cout << "Salty Looter"; }
    virtual const std::string getName() const override { return "Salty Looter"; }
};

class Southsea_Strongarm : public Pirate
{
public:
    Southsea_Strongarm() : Pirate(3, 3, 4) {
	// Effect description 
	m_effect_description = "Battlecry: Give Give a friendly Pirate +1/+1. Repeat for each Pirate you bought this turn";
    }
    virtual ~Southsea_Strongarm() {}
    virtual void printName() const override { std::cout << "Southsea Strongarm"; }
    virtual const std::string getName() const override { return "Southsea Strongarm"; }
};

class Peggy_Brittlebone : public Pirate
{
public:
    Peggy_Brittlebone() : Pirate(4, 5, 6) {
	// Effect description 
	m_effect_description = "After a card is added to your hand, give another friendly Pirate +1/+1";
    }
    virtual ~Peggy_Brittlebone() {}
    virtual void printName() const override { std::cout << "Peggy Brittlebone"; }
    virtual const std::string getName() const override { return "Peggy Brittlebone"; }
};

class Ripsnarl_Captain : public Pirate
{
public:
    Ripsnarl_Captain() : Pirate(4, 6, 4) {
	// Effect description 
	m_effect_description = "Whenever another friendly Pirate attacks, give it +2/+2";
    }
    virtual ~Ripsnarl_Captain() {}
    virtual void printName() const override { std::cout << "Ripsnarl Captain"; }
    virtual const std::string getName() const override { return "Ripsnarl Captain"; }
};

//
// Dragon minions
//

class DozyWhelp : public Dragon
{
public:
    static void Gain1AttackPoint(Card *card)
    {
	Minion::buffAttackPoint(card, 1);
    }
    DozyWhelp() : Dragon(1, 3, 0)
    {
	Effect *taunt = new Taunt(Gain1AttackPoint, this);
	m_effect_description = "Taunt: Whenether attacked, gain +1 Attack";
	m_effects.push_back(std::unique_ptr<Effect>(taunt));
    }
    virtual ~DozyWhelp() {}
    virtual void printName() const override { std::cout << "DozyWhelp"; }
    virtual const std::string getName() const override { return "DozyWhelp"; }
};

class Evolving_Chromawing : public Dragon
{
public:
    Evolving_Chromawing() : Dragon(1, 4, 1)
    {
	m_effect_description = "After you upgrade your Tavern Tier, gain +1 Attack for each friendly Dragon";
    }
    virtual ~Evolving_Chromawing() {}
    virtual void printName() const override { std::cout << "Evolving Chromawing"; }
    virtual const std::string getName() const override { return "Evolving Chromawing"; }
};

class Glyph_Guardian : public Dragon
{
public:
    Glyph_Guardian() : Dragon(2, 4, 2)
    {
	m_effect_description = "Whenever this attacks, double its Attack";
    }
    virtual ~Glyph_Guardian() {}
    virtual void printName() const override { std::cout << "Glyph Guardian"; }
    virtual const std::string getName() const override { return "Glyph Guardian"; }
};

class Whelp_Smuggler : public Dragon
{
public:
    Whelp_Smuggler() : Dragon(2, 5, 2)
    {
	m_effect_description = "After a friendly Dragon gain Attack, give it +1 Health";
    }
    virtual ~Whelp_Smuggler() {}
    virtual void printName() const override { std::cout << "Whelp Smuggler"; }
    virtual const std::string getName() const override { return "Whelp Smuggler"; }
};

class Amber_Guardian : public Dragon
{
public:
    Amber_Guardian() : Dragon(3, 2, 3)
    {
	m_effect_description = "Start of Combat: Give another friendly dragon +2/+2 and Divine Shield";
    }
    virtual ~Amber_Guardian() {}
    virtual void printName() const override { std::cout << "Amber Guardian"; }
    virtual const std::string getName() const override { return "Amber Guardian"; }
};

class Bronze_Warden : public Dragon
{
public:
    Bronze_Warden() : Dragon(3, 1, 2)
    {
	m_effect_description = "Divine Shield / Reborn";
    }
    virtual ~Bronze_Warden() {}
    virtual void printName() const override { std::cout << "Bronze Warden"; }
    virtual const std::string getName() const override { return "Bronze Warden"; }
};

class Atramedes : public Dragon
{
public:
    Atramedes() : Dragon(4, 6, 3)
    {
	m_effect_description = "Whenever this attacks, deal 3 damage to the target and its neighbors";
    }
    virtual ~Atramedes() {}
    virtual void printName() const override { std::cout << "Atramedes"; }
    virtual const std::string getName() const override { return "Atramedes"; }
};

class Drakonid_Enforcer : public Dragon
{
public:
    Drakonid_Enforcer() : Dragon(4, 7, 3)
    {
	m_effect_description = "After a friendly minion loses Divine Shield, gain +2/+2";
    }
    virtual ~Drakonid_Enforcer() {}
    virtual void printName() const override { std::cout << "Drakonid Enforcer"; }
    virtual const std::string getName() const override { return "Drakonid Enforcer"; }
};

#endif
