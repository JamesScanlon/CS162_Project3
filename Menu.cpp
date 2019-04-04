/*********************************************************************
 ** Program name: Project4
 ** Author: James Scanlon
 ** Date:  March 3, 2019
 ** Description: The menu class is used primarily to display options to the user, validate that the choice is within the range, and then return the user's choice if it is valid.
 *********************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include "Menu.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;


Menu::Menu(vector<string> choices)
{
    setMenuChoices(choices);
    // Set prompt text to null if it doesn't exist
    setPromptText("");
}

Menu::Menu(string text, vector<string> choices)
{
    setMenuChoices(choices);
    setPromptText(text);
}

void Menu::setMenuChoices(vector<string> choices)
{
    // Clear the menu before creating a new array
    menuChoices.clear();
    for (string i : choices) {
        menuChoices.push_back(i);                   // Flip has trouble with just taking a vector string as an arg, so I'm using .push_back
    }
}

void Menu::setPromptText(string text)
{
    promptText = text;
}

string Menu::getPromptText()
{
    return promptText;
}


int Menu::showMenu()
{
    // Create a variable to hold the user's menu choice
    int choice = 0;
    
    // Show the prompt, if there is one
    if (getPromptText() != "") {
        cout << "\n" << getPromptText() << "\n";
    }
    
    // Show the user the menu
    for (int i = 0; i < menuChoices.size(); i++) {
        // Show the menu item
        cout << i + 1 << ". " << menuChoices[i] << "\n";
    }
    // Get input from the user
    cin >> choice;
    
    while (cin.fail()|| (choice < 1 || choice > menuChoices.size()))            // ensure that user choice is within range
    {
        cin.clear();
        cin.ignore(4000,'\n');              // prevent strings from outputting multiple errors
        cout << "Invalid choice; please input a valid number between 1 and " << menuChoices.size() << "." << endl;
        cin >> choice;                                                          // take in another input
    }
    return choice;
}


Menu::~Menu(){
    
}
