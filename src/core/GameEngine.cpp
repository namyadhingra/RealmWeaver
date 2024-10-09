#include <external.h>
#include <GameEngine.h>

// Initialize the constant `theme` variable
const std::string theme = []() {
    std::string input;
    std::cout << "Enter a theme: ";
    getline(std::cin, input);
    return input;
}();

int main()
{
    cout<<"MAIN FILE RUNNING\n\n";

    string locName,locDesc;
    int rank;

    do
    {

        cout << "Enter the locName: ";
        getline(cin, locName);
        
        cout << "Enter the locDesc: ";
        getline(cin, locDesc);
        cout << "Enter the Rank: ";
        cin>>rank;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer

        Location loc(rank,locName,locDesc);
        NPC npc(rank,loc);

    } while (rank!=-1);
    
    
    return 0;
}

#include <string>

string GameEngine::getRankName(int rank) {
    switch (rank) {
        case 1: return "Inferior";
        case 2: return "Basic";
        case 3: return "Common";
        case 4: return "Uncommon";
        case 5: return "Rare";
        case 6: return "Unique";
        case 7: return "Epic";
        case 8: return "Legendary";
        case 9: return "Mythic";
        case 10: return "Divine";
        default: return "Unknown Rank";  // For invalid rank numbers
    }
}
