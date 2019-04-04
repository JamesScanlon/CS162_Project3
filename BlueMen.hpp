/*********************************************************************
 ** Program name: Project4
 ** Author: James Scanlon
 ** Date: March 3, 2019
 ** Description: Interface for the BlueMen class.
 *********************************************************************/


#ifndef BlueMen_hpp
#define BlueMen_hpp

#include <stdio.h>
#include "Character.hpp"

class BlueMen:public Character
{
private:
    int baseStrength = 12;
public:
    BlueMen();
    int attack();
    void defense(int damage);
    void recovery();
    void specialNotice();
    ~BlueMen();
};

#endif /* BlueMen_hpp */
