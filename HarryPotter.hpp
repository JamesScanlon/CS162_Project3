/*********************************************************************
 ** Program name: Project4
 ** Author: James Scanlon
 ** Date: March 3, 2019
 ** Description: Interface for the Harry Potter class.
 *********************************************************************/


#ifndef HarryPotter_hpp
#define HarryPotter_hpp

#include <stdio.h>
#include "Character.hpp"

class HarryPotter:public Character
{
private:
    bool hogwartsLeft;
    int baseStrength = 10;
public:
    HarryPotter();
    int attack();
    void defense(int damage);
    void recovery();
    void specialNotice();
    ~HarryPotter();
};
#endif /* HarryPotter_hpp */
