#include<Gemini.h>

Gemini::Gemini()
{
    getApiKey();
}

void Gemini::getApiKey() 
{
    ifstream configFile("../.env");
    string line;

    if (!configFile.is_open()) {
        cerr << "Could not open the configuration file!" << endl;
        return ; // Return an empty string if the file cannot be opened
    }

    while (getline(configFile, line)) {
        if (line.find("GEMINI_API_KEY=") == 0) 
        {
            apiKey = line.substr(15); // Get the value after "GEMINI_API_KEY="
            break;
        }
    }

    if (apiKey.empty()) {
        cerr << "API Key not found in configuration file!" << endl;
    }
}

int Gemini::WriteCallBack(void* contents, int size, int nmemb, void* userp)
{
    ((string*)userp)->append((char*)contents, size*nmemb);
    return size*nmemb;
}

json Gemini::sendGeminiReq(const string &prompt)
{
    CURL* curl;
    CURLcode res;
    string readBuffer;

    curl= curl_easy_init();
    if(curl)
    {
        struct curl_slist* headers = nullptr;
        headers=curl_slist_append(headers,"Content-Type: application/json");
        // headers=curl_slist_append(headers,"Authorization: Bearer ${api}");

        string url = "https://generativelanguage.googleapis.com/v1beta/models/gemini-1.5-flash-latest:generateContent?key=" + apiKey;

        curl_easy_setopt(curl,CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl,CURLOPT_HTTPHEADER, headers);

        json jsonPayload = {
            {"contents", {{{"parts", {{{"text", prompt}}}}}}}
        };

        string jsonString =jsonPayload.dump();

        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonString.c_str());

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallBack);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res=curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }

        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    }

    json jsonResp = json::parse(readBuffer);
    return jsonResp;
}

json Gemini::sendBatchGeminiReq(const vector<string> &prompts)
{
    CURL* curl;
    CURLcode res;
    string readBuffer;

    curl= curl_easy_init();
    if(curl)
    {
        struct curl_slist* headers = nullptr;
        headers=curl_slist_append(headers,"Content-Type: application/json");
        // headers=curl_slist_append(headers,"Authorization: Bearer ${api}");

        string url = "https://generativelanguage.googleapis.com/v1beta/models/gemini-1.5-flash-latest:generateContent?key=" + apiKey;

        curl_easy_setopt(curl,CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl,CURLOPT_HTTPHEADER, headers);

        json jsonPayload = 
        {
            {"contents",{}}
        };
        
        
        for(const auto& prompt: prompts)
        {
            jsonPayload["contents"].push_back({{"parts",{{{"text",prompt}}}}});   
        }

        string jsonString =jsonPayload.dump();

        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonString.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallBack);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res=curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }

        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    }

    json jsonResp = json::parse(readBuffer);
    return jsonResp;
}

json Gemini::sendGeminiReq(const string &promptFilePath, const string &prompt)
{
    json jsonPayload;
    ifstream file(promptFilePath);

    if(!file.is_open())
    {
        throw runtime_error("Could not open the file : "+promptFilePath);
    }

    file >> jsonPayload;

    file.close();
    
    json jsonPrompt=
    {
        {"role","user"},
        {"parts", {
            {
                {"text",prompt}
            }
        }}

    };

    jsonPayload["contents"].push_back(jsonPrompt);

    CURL* curl;
    CURLcode res;
    string readBuffer;


    curl= curl_easy_init();
    if(curl)
    {
        struct curl_slist* headers = nullptr;
        headers=curl_slist_append(headers,"Content-Type: application/json");
        // headers=curl_slist_append(headers,"Authorization: Bearer ${api}");

        string url = "https://generativelanguage.googleapis.com/v1beta/models/gemini-1.5-flash-latest:generateContent?key=AIzaSyBNRAo4aMQvwIhYbcNI_Bzp4Sicbxj49Ls";

        curl_easy_setopt(curl,CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl,CURLOPT_HTTPHEADER, headers);

        string jsonString =jsonPayload.dump();

        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonString.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallBack);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        // cout<<apiKey<<endl;
        string jsonString1 = jsonPayload.dump(4); // 4 spaces for indentation
        cout << "Formatted Payload: " << jsonString1 << std::endl;        
        res=curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }

        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    }

    json jsonResp = json::parse(readBuffer);
    return jsonResp;
}

// json should not be empty -- for any null value send a defualt json
future<json> Gemini::genStatsForTheme(const string &theme)
{
    return async(launch::async, [this, theme]()
    {
        json defaultJson ={
            { "attributes", {
                {{ "health", 100 }}, 
                {{ "strength", 5 }}, 
                {{ "agility", 5 }}, 
                {{ "willpower", 5 }}, 
                {{ "defence", 5 } }
            } }
        };
        // cout<<defaultJson;
        string prompt = "Based on the provided JSON structure, can you return the attributes for an "+theme+"-themed game?";
        json jsonResp=this->sendGeminiReq("../json/stats.json",prompt);

        cout<<jsonResp;

        if (jsonResp.contains("candidates") && 
            jsonResp["candidates"].is_array() &&
            !jsonResp["candidates"].empty() &&
            jsonResp["candidates"][0].contains("content") &&
            jsonResp["candidates"][0]["content"].contains("parts") &&
            jsonResp["candidates"][0]["content"]["parts"].is_array() &&
            !jsonResp["candidates"][0]["content"]["parts"].empty() &&
            jsonResp["candidates"][0]["content"]["parts"][0].contains("text")) 
        {

            try 
            {
                json parsedJson = json::parse(jsonResp["candidates"][0]["content"]["parts"][0]["text"].get<std::string>());
                cout<<parsedJson;
                return parsedJson; // Return the parsed JSON object
            }
            catch (const json::parse_error& e) 
            {
                return defaultJson; // Return an empty JSON object on parse error
            }
        }

        return defaultJson;
    });
}
