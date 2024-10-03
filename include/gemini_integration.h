#include "external.h"

string getApiKey() {
    ifstream configFile(".env");
    string line;
    string apiKey;

    if (!configFile.is_open()) {
        cerr << "Could not open the configuration file!" << endl;
        return ""; // Return an empty string if the file cannot be opened
    }

    while (getline(configFile, line)) {
        if (line.find("GEMINI_API_KEY=") == 0) {
            apiKey = line.substr(15); // Get the value after "GEMINI_API_KEY="
            break;
        }
    }

    if (apiKey.empty()) {
        cerr << "API Key not found in configuration file!" << endl;
    }

    return apiKey;
}

size_t WriteCallBack(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((string*)userp)->append((char*)contents, size*nmemb);
    return size*nmemb;
}

json sendGeminiReq(const string &prompt)
{
    CURL* curl;
    CURLcode res;
    string readBuffer;

    curl= curl_easy_init();
    if(curl)
    {
        string api=getApiKey();
        struct curl_slist* headers = nullptr;
        headers=curl_slist_append(headers,"Content-Type: application/json");
        // headers=curl_slist_append(headers,"Authorization: Bearer ${api}");

        string url = "https://generativelanguage.googleapis.com/v1beta/models/gemini-1.5-flash-latest:generateContent?key=" + api;

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
