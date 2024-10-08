// add commands like /map, /travel ,/quit, /status(to see status of self and others)that will control the game
#pragma once
#include <external.h>

class Game
{
        #define Inferior    1
        #define Basic       2
        #define Common      3
        #define Uncommon    4
        #define Rare        5
        #define Unique      6
        #define Epic        7
        #define Legendary   8
        #define Mythic      9
        #define Divine      10

        const int NPCsInLocBasedOnRank=3;
        string theme;

        void displayMap();

};
