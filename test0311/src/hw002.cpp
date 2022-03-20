#include "../head/hw002.h"
#include <iostream>
#include <set>

hw002::hw002()
{
}

hw002::~hw002()
{
}

void hw002::init()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<string> hw002::getstrings(const string& str, char ch)
{
    vector<string> strVec;
    string curStr;
    const size_t strSize = str.size();
    for (size_t i = 0; i < strSize; i++)
    {
        if (islower(str[i]))
            curStr.push_back(str[i]);
        
        if (str[i] == ch || i == str.size() - 1)
        {
            strVec.push_back(curStr);
            curStr.clear();
        }
    }
    return strVec;
}


int hw002::Calculation()
{
    init();
    string str;
    while (cin >> str)
    {
        const auto strings = getstrings(str, ',');
        int res = 0;
        for (int i = 0; i < strings.size() - 1; i++) {
            for (int j = i + 1; j < strings.size(); j++) {
                const auto& str0 = strings[i];
                const auto& str1 = strings[j];
                set<char> totalChars;
                for (const auto& curChar : str0 + str1)
                    totalChars.insert(curChar);

                const auto n0 = str0.size();
                const auto n1 = str1.size();
                if (totalChars.size() < n0 + n1)
                    continue;
                res = n0 * n1 > res ? n0 * n1 : res;
            }
        }
        cout << res;
        str.clear();
    }
    return 0;
}
