#include "game.h"

void Game::mode_raw(int activer)
{
    static struct termios cooked;
    static int raw_actif = 0;

    if (raw_actif == activer)
        return;

    if (activer)
    {
        struct termios raw;

        tcgetattr(STDIN_FILENO, &cooked);

        raw = cooked;
        cfmakeraw(&raw);
        tcsetattr(STDIN_FILENO, TCSANOW, &raw);
    }
    else
        tcsetattr(STDIN_FILENO, TCSANOW, &cooked);

    raw_actif = activer;
}

void Game::startGame()
{
    std::srand(std::time(nullptr));
    m_shop->createDeck();
    m_shop->shuffleDeck(); 
    m_running = true;
    while (m_running){
        m_player1->setGolds(max_gold);
        m_player2->setGolds(max_gold);
        deckPhase();
        if (m_player1->getGolds() == 0) m_running = false;
        //battlePhase();
        //endGame();
        if(max_gold < 10) max_gold++;
        if(max_gold == 10) m_running = false;
    }  
}


void Game::threadDeckPhase(std::future<void> futureObj)
{
    char input;
    m_shop->drawCards(*m_player1);
    while (futureObj.wait_for(std::chrono::milliseconds(1)) == std::future_status::timeout)
    {
        std::cout << "Press b to buy a card" << std::endl;
        std::cout << "Press s to sell a card" << std::endl;
        std::cout << "Press p to put a card on the board" << std::endl;
        std::cin >> input;
        if (input == 'b'){
            m_shop->displayCards();
            std::string cardChoice;
            std::cin >> cardChoice;
            std::cout << cardChoice << std::endl;
            if (cardChoice == "1" || cardChoice == "2" || cardChoice == "3"){
                m_shop->buyCard(std::stoi(cardChoice) - 1, *m_player1);
                std::cout << '\n' << *m_player1 << '\n';
            }
            std::cout << '\n';
        }
        else if (input == 's'){

        }
        else if (input == 'p'){

        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    std::cout << "Thread End" << std::endl;
}

int Game::deckPhase()
{
    /*m_shop->chooseCard(*m_player1);
    std::cout << *m_player1 << '\n';
    m_shop->chooseCard(*m_player2);
    std::cout << *m_player2 << '\n';*/


    // Create a std::promise object
    std::promise<void> exitSignal;
    //Fetch std::future object associated with promise
    std::future<void> futureObj = exitSignal.get_future();
    // Starting Thread & move the future object in lambda function by reference
    std::thread th(&Game::threadDeckPhase, this, std::move(futureObj));
    //Wait for 10 sec
    std::this_thread::sleep_for(std::chrono::seconds(30));
    std::cout << "Asking Thread to Stop" << std::endl;
    //Set the value in promise
    exitSignal.set_value();
    //Wait for thread to join
    th.join();
    std::cout << "Exiting Main Function" << std::endl;
    return 0;
}