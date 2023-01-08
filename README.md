# Hearthstone-Battleground-Clone-CLI
A Simple HearthStone Battleground clone to demonstrate OOP concepts 

## Class diagram 📊

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

### Building the project 
#### Clone the repo
```
git clone https://github.com/An0n1mity/Hearthstone-Battleground-Clone
```
#### Build from sources using CMake
```
mkdir build && cd build
cmake ..
```
#### Run the binary
```
./hearthstone-battle-ground-cli
```



