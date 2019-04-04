/*********************************************************************
 ** Program name: Project4
 ** Author: James Scanlon
 ** Date: March 3, 2019
 ** Description: Implementation of the Character class.  Serves as a parent function for the character types to inherit from.
 *********************************************************************/


#include <cstdlib>
#include "Character.hpp"

// default constructor
Character::Character(){
    type = "none";
}

// get functions
int Character::getStrength(){
    return strength;
}

int Character::getCurrentAttack(){
    return currentAttack;
}

int Character::getCurrentDefend(){
    return currentDefend;
}

int Character::getArmor()
{
    return armor;
}
string Character::getType(){
    return type;
}

bool Character::getSpecialMessage()
{
    return specialMessage;
}

string Character::getName()
{
    return name;
}

// Set functions
void Character::setName(string input)
{
    name = input;
}


// destructor
Character::~Character(){
    
}
