/*********************************************************************
 ** Program name: Project4
 ** Author: James Scanlon
 ** Date: March 3, 2019
 ** Description: Implementation of the Queue Class.
 ********************************************************************/

#include "Queue.hpp"
#include <iostream>
using namespace std;
// Constructor
Queue::Queue()
{
    head = new characterNode(NULL);
    tail = head;

}


bool Queue::isEmpty()
{
    return head == NULL;
}


void Queue::addBack(Character* characterInput)
{
    if (head->character == NULL)                                  //  empty case
    {
        head->character = characterInput;
        tail = head;
    }
    else                                        // case for > 1 node
    {
        characterNode* newNode = head;
        while (newNode->next != NULL)
        {
            newNode = newNode->next;
        }
        newNode->next = new characterNode(characterInput, newNode);
        
        tail = newNode->next;
    }
}


Character* Queue::getFront()
{
    return this->head->character;
}


void Queue::removeFront()
{
    if (isEmpty())                      // empty check
    {
        return;
    }
    
    characterNode *deleteNode = head;
    head = deleteNode->next;
    if (isEmpty())
    {
        tail = head;
    }
    
    if (head)
    {
        head->prev = NULL;
        if (head == tail)
        {
            tail->next = NULL;
        }
    }
    delete deleteNode;
}

void Queue::FighterToBack()             // used for winning fighters
{
    if (!head)
        return;
    this->addBack(head->character);
    this->removeFront();
}

void Queue::reversePrint()              // used for printing losers
{
    characterNode* temp = tail;
    while (temp->prev != NULL)
    {
        std::cout << temp->character->getName() << " " << "(" << temp->character->getType() << ")" << endl;
        temp = temp->prev;
    }
    std::cout << temp->character->getName() << " " << "(" << temp->character->getType() << ")" << endl;

}

// Deconstructor
Queue::~Queue()
{
    while (!isEmpty())                      // iterate through and remove values until isEmpty
    {
        removeFront();
    }
}
