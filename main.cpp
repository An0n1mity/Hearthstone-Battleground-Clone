#include <iostream>
//#include "Player.h"
#include "game.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <linux/input.h>

/*std::string getString()
{
  std::cout << "# getString() start\n";
  std::cout << "# getString(): Please enter a string. You have 5 seconds...\n";
  std::string input;
  std::getline(std::cin, input);
  std::cout << "# getString() end\n";
  return input;
}*/
/*
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <mutex>
#include <chrono>
#include <atomic>

class Example {
    std::atomic<bool> running;
    std::atomic<bool> renderedText;
    std::mutex inputMutex;
    std::mutex otherThingsMutex;
    std::thread otherThread;
    std::thread inputThread;

    void renderText() {
        if(!renderedText) {
            renderedText = true;
            std::cout << "Please enter a command: " << std::endl;
        }
    }

    static void doSomethingWithInput(const std::string& input) {
        if (input == "magic")
            std::cout << "The answer to life, the universe and everything!" << std::endl;
    }

public:
    Example() : running(true), renderedText(false),
                otherThread(&Example::otherThings, this),
                inputThread(&Example::input, this)
    {
    }

    ~Example() {
        inputThread.join();
        otherThread.join();
    }

    inline void quit() {
        running = false;
    }

    void handleInput() {
        std::string input;
        std::getline(std::cin, input);
        std::cout << "You entered: " << input << std::endl;
        doSomethingWithInput(input);
    }

    static void doOtherTask() {
        std::cout << "I'm doing other work..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }

    void input() {
        while (running) {
            std::lock_guard<std::mutex> locker(inputMutex);
            handleInput();
        }
    }

    void otherThings() {
        while (running) {
            std::lock_guard<std::mutex> locker(otherThingsMutex);
            renderText();
            doOtherTask();
        }
    }
};*/

using namespace std;

int main(int, char **)
{    

    /*std::unique_ptr<Example> test = std::make_unique<Example>();
    return 0;*/


    /*std::cout << "# main() start\n";
    std::cout << "# main(): Starting std::async(getString)\n";

    std::future<std::string> futureString = std::async(std::launch::async, getString);

    std::cout << "# main(): Waiting 5 seconds for input...\n";

    std::chrono::system_clock::time_point five_seconds_passed
            = std::chrono::system_clock::now() + std::chrono::seconds(5);
    std::future_status status = futureString.wait_until(five_seconds_passed);

    if (status == std::future_status::ready)
    {
        auto  result = futureString.get();
        std::cout << "# main(): Input result: " << result << "\n";
    }
    else
    {
        std::cout << "# main(): Timeout reached... \n";
    }

    std::cout << "# main() end" << std::endl;*/

    /*istringstream iss("\n");
    cin.rdbuf(iss.rdbuf());  // This line actually sets cin's input buffer
                             // to the same one as used in iss (namely the
                             // string data that was used to initialize it)
    int num = 0;
    char c;
    while(cin >> c || !cin.eof()) {
        if(cin.fail()) {
            cin.clear();
            string dummy;
            cin >> dummy;
            continue;
        }
        cout << num << ", " << c << endl;
    }
    return 0;*/

    Game game = Game(std::unique_ptr<Player>(new Player("Player 1", 1)), std::unique_ptr<Player>(new Player("Player 2", 1)));
    game.startGame();



    /*Player player = Player("Player 1", 1);

    Shop shop;
    shop.createDeck();
    shop.chooseCard(player);
    std::cout << player << '\n';*/

    /*// Create a Card AlleyCat
    std::unique_ptr<Card> abomination_card = std::unique_ptr<Card>(new AlleyCat());
    // Create a Card DeckSwabbie
    std::unique_ptr<Card> deck_swabbie_card = std::unique_ptr<Card>(new DeckSwabbie());

    // Add heroe to the player
    player.addHero(std::unique_ptr<Hero>(new Rafaam()));

    // Add the card to the deck of the player
    player.addCardToDeck(std::move(abomination_card));
    player.addCardToDeck(std::move(deck_swabbie_card));
    std::cout << player << '\n';*/

    return 0;
}
