// #include <Item.h>

// // Constructor
// Item::Item()
// {
//     //get item from db or from gemini
// }

// Item::Item(const string& name, const string& description, int rank)
//     : name(name), description(description), rank(rank) ,isEquipped(0)
// {
//     // get id from db and add here.
// }

// // Getters
// int Item::getId() const {
//     return id;
// }

// const string& Item::getName() const {
//     return name;
// }

// const string& Item::getDescription() const {
//     return description;
// }

// int Item::getRank() const {
//     return rank;
// }

// // Display method for item details
// void Item::display() const {
//     cout << "Item ID: " << id << endl;
//     cout << "Name: " << name << endl;
//     cout << "Description: " << description << endl;
//     cout << "Rank: " << rank << endl;
//     stats.displayStats();
//     cout << "Equipped Status: "<<isEquipped<< endl;
// }

// void Item::equip()
// {
//     isEquipped=1;
//     cout << "Equipped "<< getName()<< endl;

// }