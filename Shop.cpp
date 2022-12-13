#include "Shop.h"
#include "Player.h"

void Shop::giveCard(std::unique_ptr<Card> &card, Player &player)
{
    player.addCardToHand(card);
}

unsigned int Shop::calculateGold(unsigned int turns) const
{
    // Cap it to 10 golds
    return turns > 10 ? 10 : turns + 3;
}

void Shop::createDeck()
{
    m_deck.push_back(std::make_unique<DeckSwabbie>());
    m_deck.push_back(std::make_unique<DeckSwabbie>());
    m_deck.push_back(std::make_unique<DeckSwabbie>());
    m_deck.push_back(std::make_unique<AlleyCat>());
    m_deck.push_back(std::make_unique<AlleyCat>());
    m_deck.push_back(std::make_unique<AlleyCat>());
}

void Shop::shuffleDeck()
{
    std::random_shuffle(m_deck.begin(), m_deck.end());
}

void Shop::displayCards() const
{
    std::cout << "draw cards : \n";
    for (int i = 0; i < m_choices.size(); i++)
    {
        std::cout << "Carte " << i + 1 << " : ";
        m_choices[i]->printName();
        std::cout << "\n";
    }
    std::cout << "Choisissez une carte (Entre 1 et " << m_choices.size() << ") and if you don't want to buy a card enter n : ";
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

void Shop::buyCard(Player &player, Card &card)
{
    // Get index of the card in the deck
    int index = 0;
    for (auto &c : m_deck)
    {
        if (c->getId() == card.getId())
            break;

        index++;
    }
}

void Shop::putCardBack()
{
    int size = m_choices.size();
    for (int i = 0; i < size; i++)
    {
        m_deck.push_back(std::move(m_choices[i]));
    }
    m_choices.clear();
}

void Shop::sellCard(std::unique_ptr<Card> &card, Player *player)
{
    // Add a gold to the player
    player->setGolds(player->getGolds() + 1);
    // card->setOwner(nullptr);
    //   Add the card to the shop
    m_deck.push_back(std::move(card));
}

void Shop::giveGold(Player &player, unsigned int turns) const
{
    player.m_golds += calculateGold(turns);
}

void Shop::giveCardToPlayer(Player &player, Card &card)
{
    // Get index of the card in the deck
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
    // Give the card to the player
    giveCard(cardToGive, player);
}