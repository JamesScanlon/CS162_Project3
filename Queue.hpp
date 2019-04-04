/*********************************************************************
 ** Program name: Project4
 ** Author: James Scanlon
 ** Date: March 3, 2019
 ** Description: Interface of the Queue Class.
********************************************************************/



#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>
#include "Character.hpp"



class Queue{
private:
protected:
    struct characterNode
    {
        friend class Queue;
        Character *character;
        characterNode* next;
        characterNode* prev;
        characterNode(Character* characterInput, characterNode* prevInput = NULL, characterNode* nextInput = NULL){
            character = characterInput;
            next = nextInput;
            prev = prevInput;
        }
    };
        characterNode* head;
        characterNode* tail;
public:
    // constructor
    Queue();
    
    // functions
    bool isEmpty();
    void addBack(Character* characterInput);
    Character* getFront();
    void FighterToBack();
    void removeFront();
    void reversePrint();
    
    // destructer
    ~Queue();
    
};
#endif /* Queue_hpp */
