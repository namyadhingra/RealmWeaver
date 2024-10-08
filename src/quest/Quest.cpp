// #include "Quest.h"

// Reward::Reward(Stats stats, int exp, Item item) 
//     : stats(stats), exp(exp), item(item) {}

// Stats Reward::getStats() const {
//     return stats;
// }

// int Reward::getExp() const {
//     return exp;
// }

// Item Reward::getItem() const {
//     return item;
// }

// void Reward::displayReward() const {
//     cout << "Reward Stats: " << endl;
//     stats.displayStats(); // Assuming Stats class has a display method
//     cout << "Experience: " << exp << endl;
//     cout << "Item: " << item.getName() << endl; // Assuming Item has a getName() method
// }

// // Quest class methods

// Quest::Quest() : id(0), rank(1), status("ongoing"), reward(Reward(Stats(), 0, Item())) {}

// Quest::Quest(int id, const string& description, int rank, const vector<int>& objectives, Reward reward)
//     : id(id), description(description), rank(rank), objectives(objectives), reward(reward), status("ongoing") {}

// int Quest::getId() const {
//     return id;
// }

// const string& Quest::getDescription() const {
//     return description;
// }

// const string& Quest::getStatus() const {
//     return status;
// }

// const Reward& Quest::getReward() const {
//     return reward;
// }

// int Quest::getRank() const {
//     return rank;
// }

// const vector<int>& Quest::getObjectives() const {
//     return objectives;
// }

// const vector<string>& Quest::getObjectiveDesc() const {
//     return objectiveDesc;
// }

// void Quest::setStatus(const string& newStatus) {
//     status = newStatus;
// }

// void Quest::addObjective(int objectiveId, const string& objectiveDesc) {
//     objectives.push_back(objectiveId);
//     this->objectiveDesc.push_back(objectiveDesc);
// }

// void Quest::markObjectiveComplete(int objectiveId) {
//     // Logic to mark objective as completed (for now we assume objective completion will be handled elsewhere)
// }

// bool Quest::isQuestComplete() const {
//     // Return true if all objectives are marked as complete
//     // You might want to integrate a way to track which objectives are completed (e.g., flags or status per objective)
//     return objectives.empty();
// }

// void Quest::display() const {
//     cout << "Quest ID: " << id << endl;
//     cout << "Description: " << description << endl;
//     cout << "Status: " << status << endl;
//     cout << "Rank: " << rank << endl;
//     cout << "Objectives:" << endl;
//     for (int i = 0; i < objectives.size(); ++i) {
//         cout << "- " << objectiveDesc[i] << " (ID: " << objectives[i] << ")" << endl;
//     }
//     cout << "Reward:" << endl;
//     reward.displayReward();
// }
