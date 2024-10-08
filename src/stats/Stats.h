#pragma once

#include "external.h"
#include "Gemini.h"

class Stats
{
    private :

        unordered_map<string, int> attributes;
        // Gemini gemini;
    
    public:
    // Constructors
    Stats();  // Default constructor
    Stats(const string& theme); // Constructor that initializes stats based on a theme using Gemini API

    // Setters
    void setStat(const string& statName, int value);    // Set a specific stat
    void modifyStat(const string& statName, int delta); // Modify a specific stat by a delta (positive or negative)

    // Getters
    int getStat(const string& statName) const;           // Get the value of a specific stat
    bool hasStat(const string& statName) const;          // Check if a specific stat exists
    unordered_map<string, int> getAllStats() const;      // Get a map of all stats

    // Dynamic stat management
    void addStat(const string& statName, int initialValue); // Dynamically add a stat (if not generated initially)
    void removeStat(const string& statName);                // Remove a stat


    // Stat display
    void displayStats() const;                              // Display all stats in a readable format

    // Stat logic
    bool isStatBelow(const string& statName, int threshold) const; // Check if a stat is below a certain threshold
    bool isStatAbove(const string& statName, int threshold) const; // Check if a stat is above a certain threshold

};