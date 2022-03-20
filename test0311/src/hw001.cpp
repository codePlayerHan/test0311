#include "../head/hw001.h"

#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

hw001::hw001()
{
}

hw001::~hw001()
{
}

int hw001::Calculation() 
{
	map<int, int> s2num;
	for (int i = 0; i <= 'z' - 'a'; i++)
		s2num[i] = 0;
	for (int i = 0; i <= 'Z' - 'A'; i++)
		s2num[i + 26] = 0;


	auto resetMap = [=](map<int, int>& _curMap)->void
	{
		for (auto& item : _curMap)
			item.second = 0;
	};
	auto num2String = [=](const int& curInt)->char
	{
		if (curInt < 26)
			return 'a' + curInt;
		return 'A' + curInt - 26;
	};

	string inputS;

	while (cin >> inputS)
	{
		resetMap(s2num);
		string num;
		pair<bool, int> preCurString = std::make_pair(false, -1);
		bool flag_minnus = false;
		for (int i = 0; i < inputS.size(); i++)
		{
			auto curChar = inputS[i];
			string curString;
			curString.insert(0, &curChar);
			//curString.assign(&curChar[0], &curChar[strlen(curChar)]);
			if (isdigit(curChar))
				num.push_back(curChar);
			else if (islower(curChar))
			{
				preCurString.first = true;
				preCurString.second = curChar - 'a';
			}
			else if (isupper(curChar))
			{
				preCurString.first = true;
				preCurString.second = curChar - 'A' + 26;
			}

			if (curChar == ',' || i == inputS.size() - 1 || curChar == '@')
			{
				auto curNum = stoi(num, nullptr, 10);
				num.clear();
				s2num.at(preCurString.second) = !flag_minnus ? curNum : s2num.at(preCurString.second) - curNum;
				preCurString.first = false;

				if (curChar == '@')
					flag_minnus = true;
			}

		}
		vector<pair<int, int>> res;
		for (const auto& item : s2num)
		{
			if (item.second == 0) continue;
			res.emplace_back(item);
			//cout << num2String(item.first) << ":" << item.second;
		}

		for (int i = 0; i < res.size(); i++)
		{
			cout << num2String(res[i].first) << ":" << res[i].second;
			if (i != res.size() - 1)
				cout << ',';
		}

		if (!flag_minnus)
			cout << "@";
		cout << endl;
	}
	return 0;
}
