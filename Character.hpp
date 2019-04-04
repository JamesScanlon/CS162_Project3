/*********************************************************************
 ** Program name: Project4
 ** Author: James Scanlon
 ** Date: March 3, 2019
 ** Description: Interface for the Character class.
 *********************************************************************/


#ifndef Character_hpp
#define Character_hpp

#include <stdio.h>
#include <string>
using namespace std;
class Character{

protected:
    int attackValue;
    int defenseValue;
    int attackDice;
    int defendDice;
    int armor;
    int strength;
    string type;
    string name;
    int currentAttack;
    int currentDefend;
    bool specialMessage;
    
public:
    // default constructor
    Character();
    
    // virtual parent functions
    virtual int attack(){return 0;};
    virtual void defense(int damage) = 0;
    virtual void specialNotice() = 0;
    virtual void recovery() = 0;
    
    // get functions
    int getStrength();
    int getCurrentAttack();
    int getCurrentDefend();
    int getArmor();
    string getType();
    bool getSpecialMessage();
    string getName();
    
    // set functions
    void setName(string inputName);
    
    // destructor
    virtual ~Character();

};
#endif /* Character_hpp */
