#include "../head/hw003.h"

#include <string>
#include <vector>
#include <iostream>
using namespace std;

hw003::hw003(){}

hw003::~hw003(){}

int hw003::Calculation() 
{
    string inputStr;
    while (cin >> inputStr)
    {
        int  maxLen   = 0;
        int  curLen   = 0;
        char lastChar = 'a';
        for (int i = 0; i < inputStr.size(); i++)
        {
            const auto& curChar = inputStr[i];
            if (isdigit(curChar))
            {
                if (curLen == 0)
                    curLen++;
                else if (curChar >= lastChar)
                    curLen++;
                else
                {
                    maxLen = curLen > maxLen ? curLen : maxLen;
                    curLen = 1;
                }
                lastChar = curChar;
            }
            else
            {
                maxLen   = curLen > maxLen ? curLen : maxLen;
                curLen   = 0;
                lastChar = 'a';
            }
        }
        maxLen = curLen > maxLen ? curLen : maxLen;
        cout << maxLen << endl;
    }

	return 0;
}
