// add commands like /map, /travel ,/quit, /status(to see status of self and others)that will control the game
#pragma once
#include <external.h>
#include<Location.h>
#include<NPC.h>
#include<Gemini.h>

class GameEngine
{
        public:
                string getRankName(int rank);

                const int NPCsInLocBasedOnRank=3;
                void displayMap();

};
