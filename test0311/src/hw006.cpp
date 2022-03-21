#include "../head/hw006.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;

hw006::hw006(){}

hw006::~hw006(){}
/*
int hw006::Calculation() 
{
	unordered_map<char, char> pairMap = {
			{')', '('},
			{']', '['},
			{'}', '{'}
	};
    auto ValidMaxDepth = [&](string s, int& depth)->bool
    {
        int n = (int)s.size();
        if (n % 2 == 1) {
            return false;
        }
        stack<char> stk;
        for (char ch : s) {
            if (pairMap.count(ch)) {
                if (stk.empty() || stk.top() != pairMap[ch]) {
                    return false;
                }
                depth = max(depth, (int)stk.size());
                stk.pop();
            }
            else {
                stk.push(ch);
            }
        }
        return stk.empty();
    };
  
    string input_string;
    while (getline(cin, input_string)) {
        int depth = 0;
        bool flag = ValidMaxDepth(input_string, depth);
        if (flag) {
            cout << depth << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
    return 0;
}
*/

int hw006::Calculation()
{
    unordered_map<char, char> pairMap = {
        {')','('}
        ,{']','['}
        ,{'}','{'}
    };

    auto IsValid = [&](const string& oriStr, int& maxDepth)->bool
    {
        const int size_str = oriStr.size();
        if (size_str % 2 == 1)
            return false;
        stack<char> stackChar;
        maxDepth = 0;
        for (int i = 0; i < size_str; i++)
        {
            const auto& curChar = oriStr[i];
            if (pairMap.count(curChar) > 0)
            {
                if (stackChar.empty() || stackChar.top() != pairMap.at(curChar))
                    return false;
                maxDepth = (int)stackChar.size() > maxDepth ? (int)stackChar.size() : maxDepth;
                stackChar.pop();
            }
            else
            {
                stackChar.push(curChar);
            }
        }

        return stackChar.empty();
    };

    string inputStr;
    while (cin >> inputStr)
    {
        int maxDepth = 0;
        const auto flag = IsValid(inputStr, maxDepth);
        if (flag)
            cout << maxDepth << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}