// #include "NPC.h"
// #include <Quest.h>
// #include "Stats.h"


// // Constructor that generates NPC dynamically from Gemini
// NPC::NPC(int rank) : rank(rank) {
//     // Generate name and backstory via Gemini API
//     json response = Gemini::genNPCName(rank);
//     this->name= response["name"];

//     json response = Gemini::genNPCBackStory(rank);
//     this->backStory = response["backStory"];

//     // Generate dynamic stats based on rank or theme
//     this->stats = new Stats("theme_from_game");

//     // Generate NPC quests
//     generateQuests();
// }

// // Constructor with manually assigned values
// NPC::NPC(int rank, const std::string& name, const std::string& backStory)
//     : rank(rank), name(name), backStory(backStory) {
//     // Generate dynamic stats for NPC manually based on rank or theme
//     this->stats = new Stats("theme_from_game");
// }

// // Generate initial quests for NPC (from Gemini API or DB)
// void NPC::generateQuests() {
//     // Simulate generating quests from Gemini API
//     int numQuests = 3; // For example, Gemini generates 3 quests
//     for (int i = 0; i < numQuests; ++i) {
//         Quest* newQuest = new Quest();
//         addQuest(newQuest);
//     }
// }

// // Get the NPC's rank
// int NPC::getRank() const {
//     return rank;
// }

// // Get the NPC's name
// std::string NPC::getName() const {
//     return name;
// }

// // Get the NPC's backstory
// std::string NPC::getBackStory() const {
//     return backStory;
// }

// // Get the NPC's stats
// Stats* NPC::getStats() const {
//     return stats;
// }

// // Add a quest to the NPC's quest queue
// void NPC::addQuest(Quest* quest) {
//     quests.push(quest);
// }

// // Remove the first quest from the queue (when completed)
// void NPC::removeQuest() {
//     if (!quests.empty()) {
//         quests.pop();
//     }
// }

// // Get the current quest offered by NPC
// Quest* NPC::getCurrentQuest() const {
//     if (!quests.empty()) {
//         return quests.front();
//     }
//     return nullptr;
// }

// // Check if NPC has any quests available
// bool NPC::hasQuests() const {
//     return !quests.empty();
// }

// // Display NPC's basic info
// void NPC::displayNPCInfo() const {
//     cout << "NPC Name: " << name << endl;
//     cout << "NPC Rank: " << rank << endl;
//     cout << "NPC Backstory: " << backStory << endl;
// }

// // Display all available quests
// void NPC::displayQuests() const {
//     if (!quests.empty()) {
//         cout << "NPC has " << quests.size() << " quests available." << endl;
//     } else {
//         cout << "No quests available for this NPC." << endl;
//     }
// }

// // Interaction logic for talking to the NPC
// void NPC::interact() {
//     cout << "Interacting with NPC: " << name << endl;
//     // Display available quests
//     displayQuests();
//     // You can add dialogue options or more interactions here
// }
