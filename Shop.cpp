#include "Shop.h"
#include "MinionsCards.h"
#include "Player.h"

unsigned int Shop::calculateGold(unsigned int turns) const
{
    // Cap it to 10 golds
    return turns > 10 ? 10 : turns ++;
}

void Shop::createDeck()
{
    // Beasts
    m_deck.push_back(std::make_unique<AlleyCat>());
    m_deck.push_back(std::make_unique<AlleyCat>());
    m_deck.push_back(std::make_unique<AlleyCat>());
    m_deck.push_back(std::make_unique<AlleyCat>());
    m_deck.push_back(std::make_unique<Scavenging_Hyena>());
    m_deck.push_back(std::make_unique<Scavenging_Hyena>());
    m_deck.push_back(std::make_unique<Scavenging_Hyena>());
    m_deck.push_back(std::make_unique<Scavenging_Hyena>());
    m_deck.push_back(std::make_unique<Leapfrogger>());
    m_deck.push_back(std::make_unique<Leapfrogger>());
    m_deck.push_back(std::make_unique<Leapfrogger>());
    m_deck.push_back(std::make_unique<Rabid_Saurolisk>());
    m_deck.push_back(std::make_unique<Rabid_Saurolisk>());
    m_deck.push_back(std::make_unique<Rabid_Saurolisk>());
    m_deck.push_back(std::make_unique<HoundMaster>());
    m_deck.push_back(std::make_unique<HoundMaster>());
    m_deck.push_back(std::make_unique<HoundMaster>());
    m_deck.push_back(std::make_unique<Monstrous_macow>());
    m_deck.push_back(std::make_unique<Monstrous_macow>());
    m_deck.push_back(std::make_unique<Monstrous_macow>());
    m_deck.push_back(std::make_unique<Cave_Hydra>());
    m_deck.push_back(std::make_unique<Cave_Hydra>());
    m_deck.push_back(std::make_unique<Reanimating_Rattler>());
    m_deck.push_back(std::make_unique<Reanimating_Rattler>());

    // Pirates
    m_deck.push_back(std::make_unique<DeckSwabbie>());
    m_deck.push_back(std::make_unique<DeckSwabbie>());
    m_deck.push_back(std::make_unique<DeckSwabbie>());
    m_deck.push_back(std::make_unique<DeckSwabbie>());
    m_deck.push_back(std::make_unique<Scallywag>());
    m_deck.push_back(std::make_unique<Scallywag>());
    m_deck.push_back(std::make_unique<Scallywag>());
    m_deck.push_back(std::make_unique<Scallywag>());
    m_deck.push_back(std::make_unique<Freedealing_Gambler>());
    m_deck.push_back(std::make_unique<Freedealing_Gambler>());
    m_deck.push_back(std::make_unique<Freedealing_Gambler>());
    m_deck.push_back(std::make_unique<Southsea_Captain>());
    m_deck.push_back(std::make_unique<Southsea_Captain>());
    m_deck.push_back(std::make_unique<Southsea_Captain>());
    m_deck.push_back(std::make_unique<Salty_Looter>());
    m_deck.push_back(std::make_unique<Salty_Looter>());
    m_deck.push_back(std::make_unique<Salty_Looter>());
    m_deck.push_back(std::make_unique<Southsea_Captain>());
    m_deck.push_back(std::make_unique<Southsea_Captain>());
    m_deck.push_back(std::make_unique<Southsea_Captain>());
    m_deck.push_back(std::make_unique<Peggy_Brittlebone>());
    m_deck.push_back(std::make_unique<Peggy_Brittlebone>());
    m_deck.push_back(std::make_unique<Ripsnarl_Captain>());
    m_deck.push_back(std::make_unique<Ripsnarl_Captain>());

    // Dragons
    m_deck.push_back(std::make_unique<DozyWhelp>());
    m_deck.push_back(std::make_unique<DozyWhelp>());
    m_deck.push_back(std::make_unique<DozyWhelp>());
    m_deck.push_back(std::make_unique<DozyWhelp>());
    m_deck.push_back(std::make_unique<Glyph_Guardian>());
    m_deck.push_back(std::make_unique<Glyph_Guardian>());
    m_deck.push_back(std::make_unique<Glyph_Guardian>());
    m_deck.push_back(std::make_unique<Whelp_Smuggler>());
    m_deck.push_back(std::make_unique<Whelp_Smuggler>());
    m_deck.push_back(std::make_unique<Whelp_Smuggler>());
    m_deck.push_back(std::make_unique<Amber_Guardian>());
    m_deck.push_back(std::make_unique<Amber_Guardian>());
    m_deck.push_back(std::make_unique<Amber_Guardian>());
    m_deck.push_back(std::make_unique<Bronze_Warden>());
    m_deck.push_back(std::make_unique<Bronze_Warden>());
    m_deck.push_back(std::make_unique<Bronze_Warden>());
    m_deck.push_back(std::make_unique<Atramedes>());
    m_deck.push_back(std::make_unique<Atramedes>());
    m_deck.push_back(std::make_unique<Drakonid_Enforcer>());
    m_deck.push_back(std::make_unique<Drakonid_Enforcer>());
}

void Shop::shuffleDeck()
{
    std::random_shuffle(m_deck.begin(), m_deck.end());
}

void Shop::giveChoice(Player &player)
{
    shuffleDeck();
    int count = 0;
    for (int i = 0; i < m_deck.size(); i++)
    {
        if (m_deck[i]->getRang() <= player.getLevel())
        {
            player.addCardToChoices(*m_deck[i]);
            if (++count == 3)
                break;
        }
    }
}

void Shop::giveAnotherChoice(Player &player)
{
    shuffleDeck();
    if (player.getGolds() < 1)
        return;
    player.setGolds(player.getGolds() - 1);
    player.resetChoices();
    int count = 0;
    for (int i = 0; i < m_deck.size(); i++)
    {
        if (m_deck[i]->getRang() <= player.getLevel())
        {
            player.addCardToChoices(*m_deck[i]);
            if (++count == 3)
                break;
        }
    }
}

void Shop::sellCard(std::unique_ptr<Card> &card, Player *player)
{
    // Add a gold to the player
    player->setGolds(player->getGolds() + card->getGoldSell());
    // card->setOwner(nullptr);
    //   Add the card to the shop
    m_deck.push_back(std::move(card));
}

void Shop::giveGold(Player &player, unsigned int turns) const
{
    player.m_golds = calculateGold(turns);
}

void Shop::giveCardToPlayer(Player &player, Card &card)
{
    // Get index of the card in the deck
    if (player.getGolds() < 3){
        std::cout << "You don't have enough golds to buy card" << std::endl;
        return;
    }
    
    int index = 0;
    for (auto &c : m_deck)
    {
        if (c->getId() == card.getId())
            break;

        index++;
    }

    // Get the card
    std::unique_ptr<Card> cardToGive = std::move(m_deck[index]);
    // Remove the card from the deck
    m_deck.erase(m_deck.begin() + index);
    // Remove the gold cost of the card from the player
    player.setGolds(player.getGolds() - 3);

    cardToGive->linkPlayer(std::experimental::make_observer(&player));
    player.addCardToHand(cardToGive);
}
