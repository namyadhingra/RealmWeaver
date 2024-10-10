<<<<<<< HEAD
=======
#include "external.h"
>>>>>>> refs/remotes/origin/main
#include "NPC.h"

// Constructor that generates NPC dynamically from Gemini
NPC::NPC(int rank,Location &loc) : rank(rank),loc(&loc) {
    // Generate name and backstory via Gemini API
    future<json> futureResp = Gemini().genNPC(rank,loc.getName(),loc.getDesc());
    
    try
    {
        json resp = futureResp.get();
        std::cout << "NPC JSON data: " << resp.dump(4) << std::endl; // Print formatted JSON

<<<<<<< HEAD
        this->name = resp["npc"]["name"];
        this->backStory = resp["npc"]["backstory"];
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl; // Handle exceptions
    }

    // Generate dynamic stats based on rank or theme
    this->stats = new Stats(rank,name,backStory);
    // Generate NPC quests
    // generateQuests();
}

// Constructor with manually assigned values
NPC::NPC(int rank, const std::string& name, const std::string& backStory, Location* loc)
    : rank(rank), name(name), backStory(backStory), loc(loc){
    // Generate dynamic stats for NPC manually based on rank or theme
    this->stats = new Stats(rank,name,backStory);
}

// // Generate initial quests for NPC (from Gemini API or DB)
// void NPC::generateQuests() {
//     // Simulate generating quests from Gemini API
//     int numQuests = 3; // For example, Gemini generates 3 quests
//     for (int i = 0; i < numQuests; ++i) {
//         Quest* newQuest = new Quest(); // Replace this with the actual quest generation logic
//         addQuest(newQuest);
//     }
// }
=======
// Constructor that generates NPC dynamically from Gemini
NPC::NPC(int rank) : rank(rank) {
    // Generate name and backstory via Gemini API
    json response_name = Gemini().genNPCName(rank).get();
    this->name= response_name["name"];

    json response_back_story = Gemini().genNPCBackStory(rank).get();
    this->backStory = response_back_story["backStory"];

    // Generate dynamic stats based on rank or theme
    this->stats = new Stats();

    // Generate NPC quests
    generateQuests();
}

// Constructor with manually assigned values
NPC::NPC(int rank, const std::string& name, const std::string& backStory)
    : rank(rank), name(name), backStory(backStory) {
    // Generate dynamic stats for NPC manually based on rank or theme
    this->stats = new Stats();
}

// Generate initial quests for NPC (from Gemini API or DB)
void NPC::generateQuests() {
    // Simulate generating quests from Gemini API
    int numQuests = 3; // For example, Gemini generates 3 quests
    for (int i = 0; i < numQuests; ++i) {
        Quest* newQuest = new Quest();
        addQuest(newQuest);
    }
}
>>>>>>> refs/remotes/origin/main

// Get the NPC's rank
int NPC::getRank() const {
    return rank;
}

// Get the NPC's name
std::string NPC::getName() const {
    return name;
}

// Get the NPC's backstory
std::string NPC::getBackStory() const {
    return backStory;
}

// Get the NPC's stats
Stats* NPC::getStats() const {
    return stats;
}

// Add a quest to the NPC's quest queue
void NPC::addQuest(Quest* quest) {
    quests.push(quest);
}

// Remove the first quest from the queue (when completed)
void NPC::removeQuest() {
    if (!quests.empty()) {
        quests.pop();
    }
}

// Get the current quest offered by NPC
Quest* NPC::getCurrentQuest() const {
    if (!quests.empty()) {
        return quests.front();
    }
    return nullptr;
}

// Check if NPC has any quests available
bool NPC::hasQuests() const {
    return !quests.empty();
}

// Display NPC's basic info
void NPC::displayNPCInfo() const {
<<<<<<< HEAD
    std::cout << "NPC Name: " << name << std::endl;
    std::cout << "NPC Rank: " << rank << std::endl;
    std::cout << "NPC Backstory: " << backStory << std::endl;
=======
    cout << "NPC Name: " << name << endl;
    cout << "NPC Rank: " << rank << endl;
    cout << "NPC Backstory: " << backStory << endl;
>>>>>>> refs/remotes/origin/main
}

// Display all available quests
void NPC::displayQuests() const {
    if (!quests.empty()) {
<<<<<<< HEAD
        std::cout << "NPC has " << quests.size() << " quests available." << std::endl;
    } else {
        std::cout << "No quests available for this NPC." << std::endl;
=======
        cout << "NPC has " << quests.size() << " quests available." << endl;
    } else {
        cout << "No quests available for this NPC." << endl;
>>>>>>> refs/remotes/origin/main
    }
}

// Interaction logic for talking to the NPC
void NPC::interact() {
<<<<<<< HEAD
    std::cout << "Interacting with NPC: " << name << std::endl;
=======
    cout << "Interacting with NPC: " << name << endl;
>>>>>>> refs/remotes/origin/main
    // Display available quests
    displayQuests();
    // You can add dialogue options or more interactions here
}
