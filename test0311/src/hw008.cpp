#include "../head/hw008.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;

hw008::hw008(){}

hw008::~hw008(){}


void hw008::Calculation()
{
	int numPerson;
	while (cin >> numPerson)
	{
		std::vector<int> personAttribute(numPerson);
		for (int i = 0; i < numPerson; i++)
			cin >> personAttribute[i];
		int baseAttribute;
		cin >> baseAttribute;

		sort(personAttribute.begin(), personAttribute.end());
		int indexBase = 0;
		auto lowerPtr = lower_bound(personAttribute.begin(), personAttribute.end(), baseAttribute);
		if (lowerPtr != personAttribute.end())
			indexBase = lowerPtr - personAttribute.begin();
		int groupNum = numPerson - indexBase;

		if (groupNum == numPerson)
		{
			cout << groupNum << endl;
			return;
		}

		int left = 0;
		int right = indexBase - 1;
		while (left < right)
		{
			if (personAttribute[left] + personAttribute[right] >= baseAttribute)
			{
				groupNum++;
				left++;
				right--;
			}
			else
				left++;
		}
		cout << groupNum << endl;
	}	   	  
}

