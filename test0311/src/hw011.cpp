#include "../head/hw011.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

hw011::hw011() {}
hw011::~hw011() {}

void hw011::Calculation()
{
	auto CalculateColorNums = [=](const vector<int>& nums)->int
	{
		map<int, bool> index2flag;
		for (int i = 0; i < nums.size(); i++)
			index2flag[i] = false;
		int colorNum = 0;

		for (int i = 0; i < nums.size(); i++)
		{			
			const int& num0 = nums[i];
			if (!index2flag.at(i))
			{
				colorNum++;
				index2flag.at(i) = true;
			}
			else
				i++;

			for (int j = i + 1; j < nums.size(); j++)
			{
				if (i == j) continue;
				if (index2flag.at(j)) continue;

				const int& num1 = nums[j];

				if (num1 % num0 == 0)
					index2flag[j] = true;
			}
		}
		return colorNum;
	};

	int num_n;
	while (cin >> num_n)
	{
		vector<int> inputNums;
		inputNums.resize(num_n);
		for (int i = 0; i < num_n; i++)
			cin >> inputNums[i];

		sort(inputNums.begin(), inputNums.end());

		const auto resNum = CalculateColorNums(inputNums);
		cout << resNum << endl;
	}
}