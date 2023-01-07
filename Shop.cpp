#include "Shop.h"
#include "Player.h"


#define SHOP_DEBUG 1

void Shop::giveCard(std::unique_ptr<Card> &card, Player &player)
{
#if SHOP_DEBUG
    std::cout << "[SHOP DEBUG]: Called from " << __FILE__ << " line " << __LINE__ << " Shop::giveCard " << '\n';
#endif
    // Remove the gold cost of the card from the player
    unsigned int player_gold = player.getGolds();
    player.setGolds(player_gold - card->getGoldCost());

    card->linkPlayer(std::experimental::make_observer(&player));
    player.addCardToHand(card);
}

unsigned int Shop::calculateGold(unsigned int turns) const
{
    // Cap it to 10 golds
    return turns > 10 ? 10 : turns + 3;
}

void Shop::createDeck()
{
#if SHOP_DEBUG
    std::cout << "[SHOP DEBUG]: Called from " << __FILE__ << " line " << __LINE__ << " Shop::createDeck " << '\n';
#endif
    m_deck.push_back(std::make_unique<DeckSwabbie>());
    m_deck.push_back(std::make_unique<DeckSwabbie>());
    m_deck.push_back(std::make_unique<DeckSwabbie>());
    m_deck.push_back(std::make_unique<AlleyCat>());
    m_deck.push_back(std::make_unique<AlleyCat>());
    m_deck.push_back(std::make_unique<AlleyCat>());
}

void Shop::shuffleDeck()
{
#if SHOP_DEBUG
    std::cout << "[SHOP DEBUG]: Called from " << __FILE__ << " line " << __LINE__ << " Shop::shuffleDeck" << '\n';
#endif
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
#if SHOP_DEBUG
    std::cout << "[SHOP DEBUG]: Called from " << __FILE__ << " line " << __LINE__ << " Shop::giveChoice " << '\n';
#endif
    shuffleDeck();
    int count = 0;
    for (int i = 0; i < m_deck.size(); i++)
    {
        if (m_deck[i]->getRang() <= player.getLevel() && m_deck[i]->getGoldCost() <= player.getGolds())
        {
	    std::cout << "Gold cost : " << m_deck[i]->getGoldCost() << '\n';
	    std::cout << "Player golds : " << player.getGolds() << '\n';
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
#if SHOP_DEBUG
    std::cout << "[SHOP DEBUG]: Called from " << __FILE__ << " line " << __LINE__ << " Shop::giveGold " << '\n';
#endif
    player.m_golds += calculateGold(turns);
}

void Shop::giveCardToPlayer(Player &player, Card &card)
{
#if SHOP_DEBUG
    std::cout << "[SHOP DEBUG]: Called from " << __FILE__ << " line " << __LINE__ << " Shop::giveCardToPlayer " << '\n';
#endif
    // Get index of the card in the deck
    int index = 0;
    for (auto &c : m_deck)
    {
        if (c->getId() == card.getId())
            break;

        index++;
    }

    if (index >= m_deck.size())
        throw std::runtime_error("Card not found in the deck");
    // Get the card
    std::unique_ptr<Card>
        cardToGive = std::move(m_deck[index]);
    // Remove the card from the deck
    m_deck.erase(m_deck.begin() + index);
    // Give the card to the player
    giveCard(cardToGive, player);
}

std::vector<std::reference_wrapper<const Card>> Shop::getChoicesView() const
{
	std::vector<std::reference_wrapper<const Card>> choices;
	for (auto &c : m_choices)
	{
		choices.push_back(std::cref(*c));
	}
	return choices;
}
