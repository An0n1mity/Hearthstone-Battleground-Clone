cmake_minimum_required(VERSION 3.0.0)
project(HearthStoneClone VERSION 0.1.0)

include(CTest)
enable_testing()

#set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML COMPONENTS system graphics REQUIRED)

add_executable(HearthStoneClone main.cpp Player.cpp game.cpp Minions.cpp Board.cpp MinionsCards.cpp Cards.cpp Shop.cpp GameLogicManager.cpp)
add_executable(shop Player.cpp Shop.cpp Cards.cpp MinionsCards.cpp Board.cpp UnitTest/shop_test.cpp)
add_executable(board_graphic Graphic.cpp BoardGraphic.cpp CardGraphic.cpp Cards.cpp Minions.cpp MinionsCards.cpp UnitTest/board_graphic_test.cpp)

target_link_libraries(HearthStoneClone sfml-graphics)
target_link_libraries(board_graphic sfml-graphics)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_test(NAME example_test COMMAND valgrind --leak-check=full --error-exitcode=1 ./shop)
add_test(NAME memory_board_graphic COMMAND valgrind --leak-check=full --error-exitcode=1 ./board_graphic)
add_test(NAME memory_check COMMAND valgrind --leak-check=full --error-exitcode=1 ./HearthStoneClone)
