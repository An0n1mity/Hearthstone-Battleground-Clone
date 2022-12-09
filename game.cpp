#include "game.h"

void Game::mode_raw(int activer)
{
    /*static struct termios cooked;
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

    raw_actif = activer;*/
}

void Game::startGame()
{
    std::srand(std::time(nullptr));
    m_player1->setBoard(m_board);
    m_shop->createDeck();
    m_shop->shuffleDeck(); 
    m_running = true;
    while (m_running){
        m_player1->setGolds(max_gold);
        deckPhase();
        //battlePhase();
        //endGame();
        if(max_gold < 10) max_gold++;
        if(max_gold == 10) m_running = false;
    }  
}

void Game::getInput()
{
    std::cin >> m_input;
}

void Game::threadDeckPhase(std::future<void> futureObj)
{
    char input;
    m_shop->drawCards(*m_player1);
    std::cout << "Thread Start" << std::endl;
    std::cout << "Press b to buy a card" << std::endl;
    std::cout << "Press s to sell a card" << std::endl;
    std::cout << "Press p to put a card on the board" << std::endl;
    std::cout << "Input: ";
    while (futureObj.wait_for(std::chrono::milliseconds(1)) == std::future_status::timeout)
    {
        std::cin >> m_input;
        //std::thread t(&Game::getInput, this);
        if (m_input == 'b'){
            m_shop->displayCards();
            std::string cardChoice;
            std::cin >> cardChoice;
            if (cardChoice == "1" || cardChoice == "2" || cardChoice == "3"){
                m_shop->buyCard(std::stoi(cardChoice) - 1, *m_player1);
                std::cout << '\n' << *m_player1 << '\n';
            }
            std::cout << '\n';
            std::cout << "Press b to buy a card" << std::endl;
            std::cout << "Press s to sell a card" << std::endl;
            std::cout << "Press p to put a card on the board" << std::endl;
            std::cout << "Input: ";
        }
        else if (m_input == 's'){
            if (m_board->getPlayerCards(m_player1.get()).size() == 0 && m_player1->m_in_hand.size() == 0){
                std::cout << "You have no cards to sell" << std::endl;
            }
            else {
                if (m_board->getPlayerCards(m_player1.get()).size() > 0){
                    std::cout << "Cards on board : " << std::endl;
                    for(int i = 0; i < m_board->getPlayerCards(m_player1.get()).size(); i++){
                        std::cout << "Card " << i + 1 << " : ";
                        m_board->getPlayerCards(m_player1.get())[i]->printName();
                    }
                }
                if (m_player1->m_in_hand.size() > 0){
                    std::cout << "Cards in your hand : " << std::endl;
                    for(int i = 0; i < m_player1->m_in_hand.size(); i++){
                        std::cout << "Card " << i + 1 << " : ";
                        m_player1->m_in_hand[i]->printName();
                    }
                }
                std::cout << "\nIf you want to sell card from your board enter the number 1 and if you want to sell card from your hand enter the number 2" << std::endl;
                std::cout << "Input: ";
                std::string cardChoice;
                std::cin >> cardChoice;
                if (std::stoi(cardChoice) == 1){
                    std::cout << "Enter the number of the card you want to sell" << std::endl;
                    std::cout << "Input: ";
                    std::string cardNumber;
                    std::cin >> cardNumber;
                    m_board->giveCardFromBoard(std::stoi(cardNumber) - 1, m_shop.get(), m_player1.get());
                }
                else if (std::stoi(cardChoice) == 2){
                    std::cout << "Enter the number of the card you want to sell" << std::endl;
                    std::cout << "Input: ";
                    std::string cardNumber;
                    std::cin >> cardNumber;
                    m_player1->giveCardFromHand(std::stoi(cardNumber) - 1, m_shop.get());
                }
                else std::cout << "Wrong input" << std::endl;
            }
            std::cout << *m_player1 << '\n';
            std::cout << "Press b to buy a card" << std::endl;
            std::cout << "Press s to sell a card" << std::endl;
            std::cout << "Press p to put a card on the board" << std::endl;
            std::cout << "Input: ";
        }
        else if (m_input == 'p'){
            if (m_player1->m_in_hand.size() > 0){
                std::cout << "Cards in your hand : " << std::endl;
                for(int i = 0; i < m_player1->m_in_hand.size(); i++){
                    std::cout << "Card " << i + 1 << " : ";
                    m_player1->m_in_hand[i]->printName();
                }
            }
            std::cout << "\nEnter the number of the card you want to put on the board : " << std::endl;
            std::cout << "Input: ";
            std::string cardChoice;
            std::cin >> cardChoice;
            m_board->addCard(std::move(m_player1->m_in_hand[std::stoi(cardChoice) - 1]));
            m_player1->m_in_hand.erase(m_player1->m_in_hand.begin() + std::stoi(cardChoice) - 1);
            std::cout << *m_player1 << '\n';
            std::cout << "Press b to buy a card" << std::endl;
            std::cout << "Press s to sell a card" << std::endl;
            std::cout << "Press p to put a card on the board" << std::endl;
            std::cout << "Input: ";
        }
        //t.join();
        //std::cout << "Ending thread getchar" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    m_shop->putCardBack();
    std::cout << "Thread End" << std::endl;
    return;
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
    std::this_thread::sleep_for(std::chrono::seconds(10));
    std::cout << "Asking Thread to Stop" << std::endl;
    //Set the value in promise
    exitSignal.set_value();
    std::cout << "Waiting for Thread to join" << std::endl;
    //Wait for thread to join
    /*std::istringstream iss("\n");
    std::streambuf *cinbuf;
    cinbuf = std::cin.rdbuf();
    std::cin.rdbuf(iss.rdbuf());
    std::string input;
    std::cin >> input;*/

    /*std::cin.fail();

    std::istringstream iss("adzada");
    std::cin.rdbuf(iss.rdbuf());  // This line actually sets cin's input buffer
                             // to the same one as used in iss (namely the
                             // string data that was used to initialize it)
    int num = 0;
    char c;
    while(std::cin >> c || !std::cin.eof()) {
        if(std::cin.fail()) {
            std::cin.clear();
            std::string dummy;
            std::cin >> dummy;
            continue;
        }
        std::cout << num << ", " << c << std::endl;
    }*/

    th.join();
    std::cout << "Exiting Main Function" << std::endl;
    return 0;
}