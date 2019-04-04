/*********************************************************************
 ** Program name: Project4
 ** Author: James Scanlon
 ** Date: March 3, 2019
 ** Description: Implementation for the Medusa class.  Inherits from character and deals 99 damage whenever a 12 is rolled, but the 99 damage does not beat Harry or Vampire abilities. *********************************************************************/


#include "Medusa.hpp"
#include <cstdlib>
#include "Character.hpp"
#include <iostream>

using namespace std;

Medusa::Medusa() : Character::Character(){
    attackValue = 6;
    defenseValue = 6;
    armor = 3;
    strength = 8;
    attackDice = 2;
    defendDice = 1;
    type = "Medusa";
    specialMessage = false;
}

int Medusa::attack(){
    
    int damage = 0;
    
    for (int i = 0; i < attackDice; i++)
    {
        damage += ((rand() % attackValue) + 1);
    }
    if (damage == 12)                               // glare ability
    {
        damage = 99;
        specialMessage = true;
    }
    
    currentAttack = damage;
    return damage;
}

void Medusa::defense(int damage){
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

void Medusa::recovery()
{
    strength += .5 * (baseStrength - strength);
}

// glare special message
void Medusa::specialNotice(){
    if (specialMessage){
        cout << "Medusa used glare to turn the opponent to stone!" << endl;
        specialMessage = false;
    }
}

Medusa::~Medusa()
{
    
}
