#include "../head/hw010.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

hw010::hw010() {}
hw010::~hw010() {}

void hw010::Calculation()
{
	auto SplitStr = [=](string oriStr)->vector<int>
	{
		oriStr += ',';
		vector<int> nums;
		bool flag = true;
		string curStr;
		for (const auto& curChar : oriStr)
		{
			if (curChar == ',')
			{
				nums.emplace_back(stoi(curStr));
				curStr.clear();
				continue;
			}

			if (isdigit(curChar))
				curStr.push_back(curChar);
		}
		return nums;
	};

	auto SortNums = [=](vector<int>& oriNums)->vector<int>
	{
		map<int, int> num2count;
		vector<int> proNums;
		for (const auto& curNum : oriNums)
		{
			if (num2count.count(curNum) == 0)
			{
				num2count[curNum] = 1;
				proNums.emplace_back(curNum);
			}
			else
				num2count.at(curNum) += 1;
		}

		stable_sort(proNums.begin(), proNums.end(), [&](const int& num0, const int& num1)
			{return num2count.at(num0) > num2count.at(num1); });
		return proNums;
	};

	string inputStr;
	while (getline(cin, inputStr))
	{
		auto vecNums = SplitStr(inputStr);
		const auto res = SortNums(vecNums);

		for (int i = 0; i < res.size(); i++)
		{
			cout << res[i];
			if (i < res.size() - 1)
				cout << ',';
		}
		cout << endl;
	}
}

void hw010::test()
{
	vector<vector<int>> vec(5, vector<int>(5, 1));
	const int a = 99;
}