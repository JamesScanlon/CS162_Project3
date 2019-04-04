/*********************************************************************
 ** Program name: Project4
 ** Author: James Scanlon
 ** Date: March 3, 2019
 ** Description: The interface for the menu class.
 *********************************************************************/

#ifndef menu_hpp
#define menu_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;

class Menu {
    
private:
    vector<string> menuChoices;
    string promptText;
    
public:
    Menu(vector<string> menuChoices);
    Menu(string promptText, vector<string> menuChoices);
    int showMenu();
    void setPromptText(string text);
    string getPromptText();
    void setMenuChoices(vector<string> menuChoices);
    ~Menu();
};
#endif /* menu_hpp */
