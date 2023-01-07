cmake_minimum_required(VERSION 3.0.0)
project(HearthStoneClone VERSION 0.1.0)

include(CTest)
enable_testing()


add_executable(game_logic_manager Bot.cpp Player.cpp Board.cpp Minions.cpp Cards.cpp Shop.cpp MinionsCards.cpp CLI.cpp GameLogicManager.cpp UnitTest/game_logic_manager_test.cpp)
add_executable(shop_test Player.cpp Bot.cpp Board.cpp Minions.cpp Cards.cpp Shop.cpp MinionsCards.cpp GameLogicManager.cpp CLI.cpp UnitTest/shop_test.cpp)
add_executable(board_test Player.cpp Bot.cpp Board.cpp Minions.cpp Cards.cpp Shop.cpp MinionsCards.cpp GameLogicManager.cpp CLI.cpp UnitTest/board_test.cpp)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_test(NAME game_logic_manager_test COMMAND valgrind --leak-check=full --error-exitcode=1 ./game_logic_manager)
add_test(NAME memory_check COMMAND valgrind --leak-check=full --error-exitcode=1 ./HearthStoneClone)
