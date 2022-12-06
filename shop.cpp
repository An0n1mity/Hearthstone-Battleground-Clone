#include "shop.h"

void Shop::createDeck()
{
    std::srand(std::time(nullptr));
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
    int count = 0;
    for (int i = 0; i < m_deck.size(); i++)
    {
        if (m_deck[i]->getRang() <= player.getLevel())
        {
            m_deck[i]->printName();
            if(++count == 3)
                break;
        }
    }
}