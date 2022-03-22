#include "../head/hw009.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

hw009::hw009() {}
hw009::~hw009() {}

void hw009::Calculation()
{
	auto IsValid = [=](const string& curStr)->bool
	{
		if (curStr.front() == '0')
			return false;
		for (const auto& curChar : curStr)
		{
			if (curChar < '0' || curChar > '9')
				return false;
		}
		return true;
	};

	auto SplitStr = [=](
		const string& oriStr
		, const string& patten)->vector<string>
	{
		vector<string> res;
		size_t pos;
		string inStr = oriStr + patten;
		for (int i = 0; i < inStr.size(); i++)
		{
			pos = inStr.find(patten, i);
			if (pos < inStr.size())
			{
				string curStr = inStr.substr(i, pos - i);
				if ((curStr != " ") && (!curStr.empty()))
					res.emplace_back(curStr);
				i = pos + patten.size() - 1;
			}
		}
		return res;
	};

	auto CalcTime = [=](const vector<int>& nums, const int& speed)->int
	{
		int time = 0;
		for (const auto& curNum : nums)
			time += curNum / speed + (curNum % speed != 0 ? 1 : 0);
		return time;
	};

	auto CalcMinSpeek = [&](const vector<int>& nums, const int& time)->int
	{
		int speedMin = 1;
		int speedMax = *max_element(nums.begin(), nums.end());
		if (speedMin >= speedMax)
			return 1;

		while (speedMin < speedMax)
		{
			int speedMid = (speedMax + speedMin) / 2;
			const int curTime = CalcTime(nums, speedMid);
			if (curTime <= time)
				speedMax = speedMid;
			else

				speedMin = speedMid + 1;
		}
		return speedMin;
	};

	///main part ...
	string inputStr;
	while (getline(cin, inputStr))
	{
		vector<string> numbers = SplitStr(inputStr, " ");
		vector<int> intNums;
		bool flag = true;
		for (const auto& curStr : numbers)
		{
			if (!IsValid(curStr))
			{
				flag = false;
				cout << -1 << endl;
				break;
			}
			intNums.emplace_back(stoi(curStr));
		}

		if (!flag)
		{
			cout << -1 << endl;
		}

		if (flag)
		{
			vector<int> nums(intNums.begin(), intNums.end() - 1);
			const auto minSpeed = CalcMinSpeek(nums, intNums.back());
			cout << minSpeed << endl;
		}
		inputStr.clear();
	}
}

void hw009::test()
{
	vector<vector<int>> vec(5, vector<int>(5, 1));
	const int a = 99;
}


