/*********************************************************************
 ** Program name: Project4
 ** Author: James Scanlon
 ** Date: March 3, 2019
 ** Description: Implementation for the Game class.  Runs the entire game.  Allows user to pick 2 characters for 2 players and print out the results of their fights.
 *********************************************************************/


#include "Game.hpp"
#include "Character.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "Menu.hpp"
#include "Queue.hpp"
#include "Validation.hpp"

Game::Game(){
    roundCount = 0;
}

void Game::characterSelect()
{
    
    int p1Choice;
    int p2Choice;
    
    vector<string> menu1{"Vampire", "Barbarian", "Blue Men", "Medusa", "Harry Potter"};         // choose character type
    Menu p1Select("Select character type for player 1: ", menu1);
    p1Choice = p1Select.showMenu();
    switch(p1Choice){
        case 1:
            currentPlayer1 = new Vampire;
            break;
        case 2:
            currentPlayer1 = new Barbarian;
            break;
        case 3:
            currentPlayer1 = new BlueMen;
            break;
        case 4:
            currentPlayer1 = new Medusa;
            break;
        case 5:
            currentPlayer1 = new HarryPotter;
            break;
    }
    string player1Name = getString("Please enter a name for the fighter:");
    currentPlayer1->setName(player1Name);
    p1Queue->addBack(currentPlayer1);
    
    Menu p2Select("Select character type for player 2: ", menu1);
    p2Choice = p2Select.showMenu();
    switch(p2Choice){
        case 1:
            currentPlayer2 = new Vampire;
            break;
        case 2:
            currentPlayer2 = new Barbarian;
            break;
        case 3:
            currentPlayer2 = new BlueMen;
            break;
        case 4:
            currentPlayer2 = new Medusa;
            break;
        case 5:
            currentPlayer2 = new HarryPotter;
            break;
    }
    string player2Name = getString("Please enter a name for the fighter:");
    currentPlayer2->setName(player2Name);
    p2Queue->addBack(currentPlayer2);
}

void Game::playAgain()                                          // playAgain menu
{
    vector<string> menu1{"Play again.", "Exit game."};
    Menu endGame(menu1);
    endGame.showMenu();
}

void Game::run()
{
    int userChoice;
    int player1Score = 0;
    int player2Score = 0;
    int showLosers;
    vector<string> introMenu{"Play.", "Exit."};
    Menu firstMenu("Hello, welcome to James Scanlon's fantasy tournament!", introMenu);
    userChoice = firstMenu.showMenu();
    
    //int userChoice = 1;
    while (userChoice == 1)                         // run game until user selects 2 on playAgain screen
    {
        p1Queue = new Queue();
        p2Queue = new Queue();
        loserQueue = new Queue();
        numberOfCharacters = getIntegerMin("How many fighters would you like on each team?", 0);
        for (int i = 0; i< numberOfCharacters; i++)
        {
            characterSelect();
        }
        //int count = 0;
        while (!p1Queue->isEmpty() && !p2Queue->isEmpty()){                 // continue playing until a player dies

            
            /*cout << "#### Round " << count << " ####" << endl; */

            p1attacksFirst = (rand() % 2);          // resets who attacks first at the end of each round

            if (p1attacksFirst)
            {
                p1Attack();
                
                if (!p2isDead)
                {
                    p2Attack();                 // currentPlayer2 can't attack back if currentPlayer2 is dead
                }
            }
            
            else
            {
                p2Attack();
                if (!p1isDead)
                    p1Attack();                 // player 1 can't attack back if currentPlayer1 is dead
            }
            if (p1isDead or p2isDead)
            {
                roundCount += 1;
                cout << "Round " << roundCount << ":" << endl;
                cout << "Team A " << p1Queue->getFront()->getName() << " (" << p1Queue->getFront()->getType() << ") vs. " << "Team B " << p2Queue->getFront()->getName() << " (" << p2Queue->getFront()->getType() << "), ";
                if (p1isDead)                                                       // death check
                {
                    cout << p2Queue->getFront()->getName() << " has won." << endl;          // win message
                    loserQueue->addBack((p1Queue->getFront()));                             // move around characters
                    p1Queue->removeFront();
                    p2Queue->getFront()->recovery();
                    p2Queue->FighterToBack();
                    p1isDead = false;
                    player2Score += 1;
                }
                else if (p2isDead)
                {
                    cout << p1Queue->getFront()->getName() << " has won." << endl;      // win message
                    loserQueue->addBack(p2Queue->getFront());                           // move around characters
                    p2Queue->removeFront();
                    p1Queue->getFront()->recovery();
                    p1Queue->FighterToBack();
                    p2isDead = false;
                    player1Score += 1;
                }
            }

        }
        if (p1Queue->isEmpty())
        {
            cout << "Team B has won the tournament!" << endl;
        }
        else
        {
            cout << "Team A has won the tournament!" << endl;
        }
        cout << "Final Points: " << endl;
        cout << "Team A: " << player1Score << endl;
        cout << "Team B: " << player2Score << endl;
        p1Queue->~Queue();              // reset values for "play again" case
        p2Queue->~Queue();
        roundCount = 0;
        player1Score = 0;
        player2Score = 0;
        // display loser pile menu
        vector<string> menuLoser{"Show losers.", "Move on"};
        Menu menuQuestion{"Please select an option to continue", menuLoser};
        showLosers = menuQuestion.showMenu();
        if (showLosers == 1)                    // option to print losers
        {
            loserQueue->reversePrint();         // prints losers from last to first 
        }
        loserQueue->~Queue();
        vector<string> menu1{"Play again.", "Exit game."};
        Menu endGame("Thank you for playing! Please select an option:", menu1);
        p1isDead = false;           // reset isDead values
        p2isDead = false;
        userChoice = endGame.showMenu();
    }
    cout << "Goodbye! -James" << endl;          // terminating message
}


void Game::p1Attack(){                              // displays attack for currentPlayer1

    p1Damage = p1Queue->getFront()->attack();

    p2Queue->getFront()->defense(p1Damage);

    if(!(p2Queue->getFront()->getStrength()))   // death check
    {
        p2isDead = true;
    }
}

void Game::p2Attack()                                           // displays attack for player2
{

    p2Damage = p2Queue->getFront()->attack();
    p1Queue->getFront()->defense(p2Damage);
    
    if (!(p1Queue->getFront()->getStrength()))          // death check
        p1isDead = true;
}

Game::~Game(){                  // destructor
    delete currentPlayer1;
    delete currentPlayer2;
}
