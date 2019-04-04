/*********************************************************************
 ** Program name: Project4
 ** Author: James Scanlon
 ** Date: March 3, 2019
 ** Description: Interface for the Barbarian class.
 *********************************************************************/

#include "Character.hpp"

#ifndef Barbarian_hpp
#define Barbarian_hpp

#include <stdio.h>
class Barbarian:public Character
{
private:
    int baseStrength = 12;
public:
    Barbarian();
    int attack();
    void defense(int damage);
    void specialNotice() {};
    void recovery();
    ~Barbarian();
};

#endif /* Barbarian_hpp */
