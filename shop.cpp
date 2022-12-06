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
        player.addCardToDeck(std::move(m_choices[index]));
        m_choices.erase(m_choices.begin() + index);
    }
}

void Shop::chooseCard(Player &player)
{
    int index;
    drawCards(player);
    for (int i = 0; i < m_choices.size(); i++)
    {
        std::cout << "Carte "<< i+1 << " : ";
        m_choices[i]->printName();
        std::cout << "\n";
    }
    std::cout << "Choisissez une carte (Entre 1 et 3): ";
    std::cin >> index;
    buyCard(index-1, player);
    std::cout << '\n';
    for(int i = 0; i < m_choices.size(); i++)
    {
        m_deck.push_back(std::move(m_choices[i]));
    }
}