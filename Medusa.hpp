/*********************************************************************
 ** Program name: Project4
 ** Author: James Scanlon
 ** Date: March 3, 2019
 ** Description: Interface for the Medusa class.
 *********************************************************************/


#ifndef Medusa_hpp
#define Medusa_hpp

#include <stdio.h>
#include "Character.hpp"
class Medusa:public Character
{
private:
    int baseStrength = 8;
public:
    Medusa();
    int attack();
    void defense(int damage);
    void recovery();
    void specialNotice();
    ~Medusa();
};
#endif /* Medusa_hpp */
