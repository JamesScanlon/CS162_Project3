/*********************************************************************
 ** Program name: Project4
 ** Author: James Scanlon
 ** Date: March 3, 2019
 ** Description: Interface for the Game class.
 *********************************************************************/


#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include "Character.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "Menu.hpp"
#include "Queue.hpp"

class Game{

private:
    Queue* p1Queue;
    Queue* p2Queue;
    Queue* loserQueue;
    Character* currentPlayer1;
    Character* currentPlayer2;
    int numberOfCharacters;
    int p1Damage;
    int p2Damage;
    int roundCount;
    bool p1isDead;
    bool p2isDead;
    bool p1attacksFirst;
    
public:
    Game();
    void characterSelect();
    void run();
    void playAgain();
    void firstAttack();
    void p1Attack();
    void p2Attack();
    ~Game();
};

#endif /* Game_hpp */
