#include "../include/pch.h"

int main()
{
    cout<<"MAIN FILE RUNNING\n\n";

    string prompt;
    cout<<"Enter the prompt : ";
    getline(cin, prompt);

    json jsonResp = sendGeminiReq(prompt);

    cout<<"Gemini Resp : "<<(string)jsonResp["candidates"][0]["content"]["parts"][0]["text"]<<endl;

    return 0;
}