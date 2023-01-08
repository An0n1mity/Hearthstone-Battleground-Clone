<p align="center">
  <img src="https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white">
  <img src="https://img.shields.io/github/license/an0n1mity/Hearthstone-Battleground-Clone">
</p>
<p align="center">
  <img src="https://pbs.twimg.com/media/DjIndZsX4AAzV_S?format=jpg&name=900x900" width=10% height=auto/>
</p>

# Hearthstone-Battleground-Clone-CLI
A Simple HearthStone Battleground clone to demonstrate OOP concepts 

## Class diagram 📊
<p align="center">
  <img src="https://github.com/An0n1mity/Hearthstone-Battleground-Clone/blob/main/image.png" width=100% height=auto/>
</p>
## Design pattern
The goal of this project was to try learn basic of design pattern for OOP using C++.  
1. Uses of smart pointers : Better aggregation and composition relationship than with raw pointers.
2. Abstract classes : Polymorphism, Interfaces, Generics.
3. Factory pattern : Create cards in a flexible and modular way.

## Gameplay 🎮
Turn based game consisting of two phases : *recruitement* and *battle*.  
The game end when one of the player has lost all of his HP.  
* **RECRUITEMENT** :
  Player can choose betwen 4 actions : buy, sell, play a card, start battle.
* **BATTLE** :
  First player with most cards start the attack, minions attacking goes from left to right order and target a random enemy.
## Card effects 🪄
* **BATTLECRY** : Activate when card is played.
* **TAUNT** : Force the card to be attacked by the opponent. Activate on damage.

### Building the project 🔨
#### Clone the repo
```
git clone https://github.com/An0n1mity/Hearthstone-Battleground-Clone
```
#### Build from sources
```
g++ -o hearthstone-battle-ground-cli *.c++ (Linux)
x86_64-w64-mingw32-g++-posix -std=c++2a -lwinpthread ../*.cpp (Windows)
```
#### Run the binary
```
./hearthstone-battle-ground-cli
```
( An executable was already compiled for windows with mingw, you need to launch it from a terminal )



