cmake_minimum_required(VERSION 3.0.0)
project(HearthStoneClone VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(HearthStoneClone main.cpp Player.cpp game.cpp Minions.cpp shop.cpp Board.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
