/*********************************************************************
 ** Program name: Project4
 ** Author: James Scanlon
 ** Date: March 3, 2019
 ** Description: Interface for the Vampire class.
 *********************************************************************/

#include "Character.hpp"

#ifndef Vampire_hpp
#define Vampire_hpp

#include <stdio.h>
class Vampire:public Character
{
private:
    int baseStrength = 18;
public:
    Vampire();
    int attack();
    void defense(int damage);
    void recovery();
    void specialNotice();
    ~Vampire();
};

#endif /* Vampire_hpp */
