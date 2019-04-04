/*********************************************************************
 ** Program name: Project4
 ** Author: James Scanlon
 ** Date: March 3, 2019
 ** Description: Implementation for the Barbarian class.  Inherits from character and has no special conditions.
 *********************************************************************/

#include <cstdlib>
#include "Character.hpp"
#include "Barbarian.hpp"
Barbarian::Barbarian() : Character::Character(){
    attackValue = 6;
    defenseValue = 6;
    armor = 0;
    strength = 12;
    attackDice = 2;
    defendDice = 2;
    type = "Barbarian";
    specialMessage = false;
}

int Barbarian::attack(){
    
    int damage = 0;
    
    for (int i = 0; i < attackDice; i++)
    {
        damage += ((rand() % attackValue) + 1);
    }
    currentAttack = damage;
    return damage;
}

void Barbarian::defense(int damage){
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

void Barbarian::recovery()
{
    strength += .5 * (baseStrength - strength);
}

Barbarian::~Barbarian()
{
    
}
