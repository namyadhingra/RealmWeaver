#pragma once

#include <external.h>
#include<Stats.h>

class Item 
{
private:
    int id;                 // Unique identifier for the item
    string name;      // Name of the item
    string description; // Description of the item
    int rank;              // Rank of the item
    Stats stats;
    bool isEquipped;
    // You can add more attributes as needed (e.g., type, effects, etc.)

public:
    // Constructor
    Item();                                                                 //Fetched from db
    Item(const string& name, const string& description, int rank);  //Newly generated fron the gemini

    // Getters
    int getId() const;
    const string& getName() const;
    const string& getDescription() const;
    int getRank() const;

    // Display method for item details
    void display() const;

    void equip();
};
