/*********************************************************************
 ** Program name: Project4
 ** Author: James Scanlon
 ** Date: March 3, 2019
 ** Description: Interface of the Validation Class.
 ********************************************************************/


#ifndef Validation_hpp
#define Validation_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using std::string;

int getInteger(string promptText);

int getIntegerMin(string promptText, int minVal);

int getIntegerMinMax(string promptText, int minVal, int maxVal);

string getString(string promptText);

#endif /* Validation_hpp */
