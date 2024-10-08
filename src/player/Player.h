#pragma once

#include<external.h>
#include<Location.h>
#include<Item.h>
#include<Stats.h>
#include<Quest.h>

class Quest;

class Player
{
    private :
        int rank;
        string name;
        int exp;            
        int lvl;
        vector<Item> inventory;
        unordered_map<int,Quest> ongoingQuests;
        Location *currentLocation;
        Stats *stats;

        void rankUp();
        void lvlUp();
        void addExp(int points);

    public :
        Player(string name,int stLvl=1);

        // Getters
        string getName() const;
        int getLevel() const;
        int getExperiencePoints() const;
        int getRank() const;
        Location* getCurrentLocation() const;
        vector<Item> getInventory() const;

        // Setters
        void setCurrentLocation(Location* loc);

        // Inventory management
        void addItem(const Item& item);
        void removeItem(const Item& item);
        void displayInventory() const;
        void equipItem(Item& item);

        // Quest management
        void addQuest(const Quest& quest);
        void completeQuest(int questId);
        void displayOngoingQuests() const;

        // Player actions
        void travel(Location* destination);  
        void gainExperience(int points);    
        void interact(const NPC* npc);
        void displayStats();
};