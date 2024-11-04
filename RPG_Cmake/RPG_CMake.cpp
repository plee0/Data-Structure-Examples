﻿// RPG_Cmake.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <string>
#include "GameDecisionTree.h"
#include "RPG_CMake.h"

using namespace std;

int main() {
    GameDecisionTree<Story> myGame;

    string filename = "story.txt";  // Specify the input file
    char delimiter = '|';            //  '|' is the delimiter, change this to ',' if you choose

    // Load the story data from the file
    myGame.loadStoryFromFile(filename, delimiter);

    // Start the game
    myGame.playGame();

    return 0;
}