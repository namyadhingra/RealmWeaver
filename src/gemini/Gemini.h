#pragma once

#include <external.h>

class Gemini
{
    private:
        string apiKey;
        mutex apiMutex;

        void getApiKey();
        static int WriteCallBack(void* contents, int size, int nmemb, void* userp);
        json sendGeminiReq(const string &prompt);
        json sendGeminiReq(const string &promptFilePath, const string &prompt);
        json sendBatchGeminiReq(const vector<string>& prompts);
        json isJsonCorrect(const json& resp, const json& def);

    public:
        Gemini();

        future<json> genStatsForTheme(const string &theme);
        future<json> genNPCName(int rank);
        future<json> genNPCBackStory(int rank);
        future<json> genLocationByGemini(int rank);
        future<json> genLocationByGemini(int rank,const string &name);
        future<json> genQuests(int rank,const string &name,const string &backStory);

        future<json> genItem(int rank);

        static future<vector<json>> genMutlipleLocations(const vector<int>& rank);
};
