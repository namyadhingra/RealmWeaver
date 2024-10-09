// int main() {
//     string theme, locName, locDesc;

//     // Prompt for theme, locName, and locDesc only once
//     cout << "Enter the theme: ";
//     getline(cin, theme);

//     if (theme == "\\quit") return 0; // Check for the quit command immediately

//     cout << "Enter the locName: ";
//     getline(cin, locName);
    
//     cout << "Enter the locDesc: ";
//     getline(cin, locDesc);
    
//     int rank; // Declare rank outside the loop

//     do {
//         cout << "Rank (or type \\quit to exit): ";
//         cin >> rank;

//         // Check for the quit command
//         if (rank == -1) break; // You may want to handle this differently

//         cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer

//         future<json> futureJson = Gemini().genNPC(theme, rank, locName, locDesc);

//         try {
//             json stats = futureJson.get(); // Block until the result is ready
//             std::cout << "JSON data: " << stats.dump(4) << std::endl; // Print formatted JSON
//         } catch (const std::exception& e) {
//             std::cerr << "Error: " << e.what() << std::endl; // Handle exceptions
//         }

//     } while (true); // Continue until we break out of the loop

//     return 0;
// }
