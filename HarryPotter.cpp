/*********************************************************************
 ** Program name: Project4
 ** Author: James Scanlon
 ** Date: March 3, 2019
 ** Description: Implementation for the HarryPotter class.  Inherits from character and when his health hits 0, he comes back at 20 strength one time.
 *********************************************************************/

#include <cstdlib>
#include "HarryPotter.hpp"
#include <iostream>

using namespace std;


HarryPotter::HarryPotter() : Character::Character(){
    attackValue = 6;
    defenseValue = 6;
    armor = 0;
    strength = 10;              // regens to 20
    attackDice = 2;
    defendDice = 2;
    type = "Harry Potter";
    hogwartsLeft = true;
    specialMessage = false;
}

int HarryPotter::attack(){
    
    int damage = 0;
    
    for (int i = 0; i < attackDice; i++)
    {
        damage += ((rand() % attackValue) + 1);
    }
    currentAttack = damage;
    return damage;
}

void HarryPotter::defense(int damage)
{
    int roll = 0;
    
    for (int i = 0; i < defendDice; i++)
    {
        roll += ((rand() % defenseValue) + 1);
    }
    
    if (damage > (roll - armor))
    {
        strength -= (damage - roll - armor);
        
        if (strength <= 0)
        {
            if (hogwartsLeft)                       // hogwarts ability check
            {
                strength = 20;
                specialMessage = true;
                hogwartsLeft = false;
            }
            else
            {
                strength = 0;
            }
        }
    }
    currentDefend =  roll;
}

void HarryPotter::recovery()
{
    if (strength > baseStrength)
    {
        strength += .5 * (2 * baseStrength - strength);
    }
    else
    {
        strength += .5 * (baseStrength - strength);
    }
}

//hogwarts special message
void HarryPotter::specialNotice()
{
    if (specialMessage){
        cout << "Harry Potter revived himself with Hogwarts! He now has 20 strength." << endl;
        specialMessage = false;
    }
}

HarryPotter::~HarryPotter()
{
    
}
