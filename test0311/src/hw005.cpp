#include "../head/hw005.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

hw005::hw005(){}

hw005::~hw005(){}

int hw005::Calculation() 
{
	auto CalcAllCoordinates = [=](const string& oriStr)->vector<pair<string, string>>
	{
		vector<pair<string, string>> res;
		string curStr;
		bool flag = false;
		for (int i = 0; i < oriStr.size(); i++)
		{
			if (oriStr[i] == '(')
			{
				flag = true;
				continue;
			}
			if (oriStr[i] == ')')
				flag = false;
			if (flag)
				curStr.push_back(oriStr[i]);
			if (!flag && !curStr.empty())
			{
				string str0, str1;
				bool flag_sub = false;
				for (int j = 0; j < curStr.size(); j++)
				{
					if (!flag_sub)
					{
						if (curStr[j] == ',')
						{
							flag_sub = true;
							continue;
						}
						str0.push_back(curStr[j]);
					}

					if (flag_sub)
						str1.push_back(curStr[j]);
				}
				pair<string, string> curPair = std::make_pair(str0, str1);
				res.emplace_back(curPair);
				curStr.clear();
			}
		}
		return res;
	};
	auto CalcPow = [=](int n)->int
	{
		int res = 1;
		while (n>0)
		{
			res *= 10;
			--n;
		}
		return res;
	};

	auto isValid = [&](const string& oriStr, int & numVal)->bool
	{
		if (oriStr.front() == '0')
		{
			numVal = 0;
			return false;
		}

		int res = 0;
		for (int i = 0; i < oriStr.size(); i++)
			res += CalcPow(oriStr.size() - 1 - i) * (oriStr[i] - '0');
		numVal = res;
		return true;
	};

	string strInput;
	while (cin >> strInput)
	{
		const auto coordinatePairs = CalcAllCoordinates(strInput);

		bool find_one = false;
		int maxDis = 0;
		pair<int, int> resCoordinate;

		for (const auto& curPair : coordinatePairs)
		{
			int num0, num1;
			if (!isValid(curPair.first, num0) || !isValid(curPair.second, num1))
				continue;
			find_one = true;
			const int curDis = num0 * num0 + num1 * num1;
			if (curDis < maxDis) continue;
			maxDis = curDis;
			resCoordinate = std::make_pair(num0, num1);
		}

		if (find_one)
			cout << "(" << resCoordinate.first << "," << resCoordinate.second << ")" << endl;
		else
			cout << "(0,0)" << endl;
	}
  

	return 0;
}
