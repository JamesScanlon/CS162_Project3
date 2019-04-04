/*********************************************************************
 ** Program name: Project4
 ** Author: James Scanlon
 ** Date: March 3, 2019
 ** Description: Implementation for the BlueMen class.  Inherits from character and has the amount of defendDice changee with its strength.
 *********************************************************************/


#include "BlueMen.hpp"
#include <cstdlib>
#include "Character.hpp"
#include <iostream>
using namespace std;


BlueMen::BlueMen() : Character::Character(){
    attackValue = 10;
    defenseValue = 6;
    armor = 3;
    strength = 12;
    attackDice = 2;
    defendDice = 3;     // Changes with number of Blue Men
    type = "Blue Men";
    specialMessage = false;
}

int BlueMen::attack(){
    
    int damage = 0;
    
    for (int i = 0; i < attackDice; i++)
    {
        damage += ((rand() % attackValue) + 1);
    }
    currentAttack = damage;
    return damage;
}


void BlueMen::defense(int damage){
    int roll = 0;
    
    for (int i = 0; i < defendDice; i++)
    {
        roll += ((rand() % defenseValue) + 1);
    }
    
    if (damage > (roll + armor))
    {
        strength -= (damage - roll - armor);
        
        if (strength <= 0)
        {
            strength = 0;
        }
        else if (strength <= 4)
        {
            defendDice = 1;                 // only one blue man left
            specialMessage = true;
        }
        else if (strength <= 8)
        {
            defendDice = 2;                 // two blue men left
            specialMessage = true;
        }
        
        
    }
    currentDefend =  roll;
}

void BlueMen::recovery()
{
    strength += .5 * (baseStrength - strength);
    if (strength <= 4)
    {
        defendDice = 1;
    }
    else if (strength <= 8)
    {
        defendDice = 2;
    }
    else
    {
        defendDice = 3;
    }
}

// special message
void BlueMen::specialNotice(){
    if (specialMessage){
        cout << "The mob of blue men has gotten smaller! They now roll with less die for defense." << endl;
        specialMessage = false;
    }
}

BlueMen::~BlueMen()
{
    
}
