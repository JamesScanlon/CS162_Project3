/*********************************************************************
 ** Program name: Project4
 ** Author: James Scanlon
 ** Date: March 3, 2019
 ** Description: Implementation of the Validation Class.
 ********************************************************************/


#include "Validation.hpp"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;


int getInteger(string prompt)
{
    int num;                                        // holds the user input
    
    
    cout << prompt << endl;                            // prompts user for input
    cin >> num;                                        // takes user input
    
    // While the input entered is not an integer, prompt the user to enter an integer.
    while (!cin) {
        cout << "That's not a valid integer. Please try again." << endl;
        cin.clear();
        cin.ignore(4000,'\n');
        cin >> num;
    }
    return num;
}

int getIntegerMin(string prompt, int minVal)
{
    // Variable to store the number entered by the user.
    int num = getInteger(prompt);
    string newPrompt = "Please enter a valid integer.";
    while (num < minVal) {
        num = getInteger(newPrompt);
    }
    return num;
}

int getIntegerMinMax(string prompt, int minVal, int maxVal)
{
    // Variable to store the number entered by the user.
    int num = getInteger(prompt);
    string newPrompt = "Please enter a valid integer.";
    while (num < minVal || num > maxVal) {
        num = getInteger(newPrompt);
    }
    return num;
}

string getString(string prompt)
{
    cin.clear();
    cin.ignore();
    string input;
    input.empty();
    cout << prompt << endl;
    getline(cin, input);
    return input;
}
