/*********************************************************************
 ** Program name: Project4
 ** Author: James Scanlon
 ** Date: March 3, 2019
 ** Description: Implementation for the Vampire class.  Inherits from character and has a 50% chance to charm the opponent and take no damage.
 *********************************************************************/

#include <cstdlib>
#include "Character.hpp"
#include "Vampire.hpp"
#include <iostream>
using namespace std;

Vampire::Vampire() : Character::Character(){
    attackValue = 12;
    defenseValue = 6;
    armor = 1;
    strength = 18;
    attackDice = 1;
    defendDice = 1;
    type = "Vampire";
    specialMessage = false;
}

int Vampire::attack(){
    
    int damage = 0;
    
    for (int i = 0; i < attackDice; i++)
    {
        damage += ((rand() % attackValue) + 1);
    }
    currentAttack = damage;
    return damage;
}

void Vampire::defense(int damage)
{
    int charmChance = rand() % 2;
    
    if (charmChance)                        // 50% of the time Vampire will have 99 defend via "charm"
    {
        currentDefend = 99;
        specialMessage = true;          // enables special message when charm hits
    }
    
    else
    {
        int roll = 0;
        
        for (int i = 0; i < defendDice; i++)
        {
            roll += ((rand() % defenseValue) + 1);
        }
        
        if (damage > (roll + armor))
        {
            strength -= (damage - roll - armor);
            
            if (strength < 0)
            {
                strength = 0;
            }
        }
        currentDefend =  roll;

    }
}

void Vampire::recovery()
{
    strength += .5 * (baseStrength - strength);
}

void Vampire::specialNotice(){                                      // charm message; resets bool after invoked
    if (specialMessage){
        cout << "Vampire used charm to defend itself!" << endl;
        specialMessage = false;
    }
}

Vampire::~Vampire()
{
    
}
