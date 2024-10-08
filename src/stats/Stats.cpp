// #include "Stats.h"
// #include <Gemini.h>

// // Default constructor
// Stats::Stats() {
//     // Default stats can be empty or you can set up some basic placeholder stats if needed
// }

// // Constructor that initializes stats based on theme
// Stats::Stats(const string& theme) {
//     // Simulate getting a dynamic stat structure from Gemini API
//     // json statResponse = Gemini().genStatsForTheme(theme);
    
//     // Parse the JSON response and populate stats
//     for (const auto& stat : statResponse.items()) {
//         string statName = stat.key();     // e.g., "HP", "MP", "Strength"
//         int statValue = stat.value();     // e.g., 100, 50, 10
//         attributes[statName] = statValue;
//     }
// }

// // Set a specific stat
// void Stats::setStat(const string& statName, int value) {
//     attributes[statName] = value;
// }

// // Modify a specific stat by a delta
// void Stats::modifyStat(const string& statName, int delta) {
//     if (attributes.find(statName) != attributes.end()) {
//         attributes[statName] += delta;
//     } else {
//         cout << "Stat " << statName << " not found!" << endl;
//     }
// }

// // Get the value of a specific stat
// int Stats::getStat(const string& statName) const {
//     auto it = attributes.find(statName);
//     if (it != attributes.end()) {
//         return it->second;
//     }
//     cout << "Stat " << statName << " not found!" << endl;
//     return 0; // Default value if stat not found
// }

// // Check if a specific stat exists
// bool Stats::hasStat(const string& statName) const {
//     return attributes.find(statName) != attributes.end();
// }

// // Get all attributes
// unordered_map<string, int> Stats::getAllStats() const {
//     return attributes;
// }

// // Dynamically add a stat (if it was not created initially)
// void Stats::addStat(const string& statName, int initialValue) {
//     attributes[statName] = initialValue;
// }

// // Remove a stat
// void Stats::removeStat(const string& statName) {
//     attributes.erase(statName);
// }

// // Display all attributes
// void Stats::displayStats() const {
//     cout << "Player Stats:" << endl;
//     for (const auto& [statName, value] : attributes) {
//         cout << statName << ": " << value << endl;
//     }
// }

// // Check if a stat is below a certain threshold
// bool Stats::isStatBelow(const string& statName, int threshold) const {
//     if (attributes.find(statName) != attributes.end()) {
//         return attributes.at(statName) < threshold;
//     }
//     return false; // Return false if stat doesn't exist
// }

// // Check if a stat is above a certain threshold
// bool Stats::isStatAbove(const string& statName, int threshold) const {
//     if (attributes.find(statName) != attributes.end()) {
//         return attributes.at(statName) > threshold;
//     }
//     return false; // Return false if stat doesn't exist
// }
