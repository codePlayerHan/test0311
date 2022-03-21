#include "../head/hw007.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;

hw007::hw007(){}

hw007::~hw007(){}


void hw007::Calculation()
{
	auto IsValidStr = [=](const string & oriStr, int& strLen)->bool
	{
		stack<char> curStr;

		for (int i = 0; i < oriStr.size(); i++)
		{
			const auto& curChar = oriStr[i];
			if (!(islower(curChar) || isupper(curChar)))
				return false;

			if (!curStr.empty() && curStr.top() == curChar)
				curStr.pop();
			else
				curStr.push(curChar);
		}
		strLen = curStr.size();
		return true;
	};

    string inputStr;
	while (cin >> inputStr)
	{
		int finalLen = 0;
		if (IsValidStr(inputStr, finalLen))
			cout << finalLen << endl;
		else
			cout << 0 << endl;
		inputStr.clear();

	}
    
}

