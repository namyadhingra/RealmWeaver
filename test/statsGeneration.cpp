// int main()
// {
//     cout<<"MAIN FILE RUNNING\n\n";

//     string prompt;

//     do
//     {
//         cout<<"Enter the prompt : ";
//         getline(cin, prompt);

//         future<json> futureJson = Gemini().genStatsForTheme(prompt);

//         try 
//         {
//             json stats = futureJson.get(); // Block until the result is ready
//             std::cout << "JSON data: " << stats.dump(4) << std::endl; // Print formatted JSON
//         } 
//         catch (const std::exception& e) 
//         {
//             std::cerr << "Error: " << e.what() << std::endl; // Handle exceptions
//         }

//     } while (prompt!="\\quit");
    
    
//     return 0;
// }
