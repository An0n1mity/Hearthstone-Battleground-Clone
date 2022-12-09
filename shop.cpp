#include "shop.h"

void Shop::createDeck()
{
    m_deck.push_back(std::unique_ptr<Minion>(new DeckSwabbie()));
    m_deck.push_back(std::unique_ptr<Minion>(new DeckSwabbie()));
    m_deck.push_back(std::unique_ptr<Minion>(new DeckSwabbie()));
    m_deck.push_back(std::unique_ptr<Minion>(new AlleyCat()));
    m_deck.push_back(std::unique_ptr<Minion>(new AlleyCat()));
    m_deck.push_back(std::unique_ptr<Minion>(new AlleyCat()));
    m_deck.push_back(std::unique_ptr<Minion>(new Cave_hydra()));
    m_deck.push_back(std::unique_ptr<Minion>(new Cave_hydra()));
    m_deck.push_back(std::unique_ptr<Minion>(new Cave_hydra()));
    m_deck.push_back(std::unique_ptr<Minion>(new Cave_hydra()));
    m_deck.push_back(std::unique_ptr<Minion>(new Cave_hydra()));
    m_deck.push_back(std::unique_ptr<Minion>(new Cave_hydra()));
    m_deck.push_back(std::unique_ptr<Minion>(new Cave_hydra()));
    m_deck.push_back(std::unique_ptr<Minion>(new Cave_hydra()));
}

void Shop::shuffleDeck()
{
    std::random_shuffle(m_deck.begin(), m_deck.end());
}

void Shop::drawCards(Player &player)
{
    shuffleDeck();
    int count = 0;
    for (int i = 0; i < m_deck.size(); i++)
    {
        if (m_deck[i]->getRang() <= player.getLevel())
        {
            m_choices.push_back(std::move(m_deck[i]));
            m_deck.erase(m_deck.begin() + i);
            if(++count == 3)
                break;
        }
    }

}

void Shop::buyCard(int index, Player &player)
{
    if (index < 0 || index >= m_choices.size() || m_choices.empty())
        return;
    if (player.getGolds() >= 3)
    {
        player.setGolds(player.getGolds() - 3);
        m_choices[index]->setOwner(&player);
        player.addCardToHand(std::move(m_choices[index]));
        m_choices.erase(m_choices.begin() + index);
    }
    else
    {
        std::cout << "You don't have enough golds to buy this card\n";
    }
}

void Shop::displayCards(){
    std::cout << "draw cards : \n";
    for (int i = 0; i < m_choices.size(); i++)
    {
        std::cout << "Carte "<< i+1 << " : ";
        m_choices[i]->printName();
        std::cout << "\n";
    }
    std::cout << "Choisissez une carte (Entre 1 et " << m_choices.size() << ") and if you don't want to buy a card enter n : ";
}

void Shop::putCardBack()
{
    int size = m_choices.size();
    for (int i = 0; i < size; i++)
    {
        m_deck.push_back(std::move(m_choices[0]));
    }
    m_choices.clear();
}

void Shop::sellCard(std::unique_ptr<Card> card, Player *player)
{
    // Add the card to the shop
    m_deck.push_back(std::move(card));
    // Add a gold to the player
    player->setGolds(player->getGolds() + 1);
}