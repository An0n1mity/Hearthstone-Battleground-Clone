#include "Bot.h"

void Bot::playTurn(Shop &shop)
{
    // Bot will play a random card from his hand
    // If he has no card in his hand, he will draw a card
    int choice;
    if (m_golds >= 5 && m_level < 4)
        choice = rand() % 2;
    else
        choice = 0;
    
    if (choice)
        upgradeLevel();
    else {
        while (m_hand.size() < 6 && m_golds >= 3)
        {
            // Draw a card
            if(m_choices.size() > 0){
                selectCardFromChoices(0, shop);
            }
            else{
                shop.giveAnotherChoice(*this);
            }
        }
        // Select a random card from his hand
        while (m_hand.size() > 0 && m_board->getPlayerCardsView(*this).size() < 4)
        {
            int card = rand() % m_hand.size();
            moveCardFromHandToBoardLeft(card);
        }
    }
        

    // Play the card
}