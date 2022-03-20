#include "../head/hw004.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

hw004::hw004(){}

hw004::~hw004(){}

int hw004::Calculation() 
{
    auto calcPow = [=](int n)->int
    {
        int res = 1;
        while (n > 0)
        {
            res *= 2;
            --n;
        }
        return res;
    };
    auto strToNum = [&](string s)->int
    {
        int num = 0;

        for (int i = 0; i < s.size(); i++)
            num += calcPow(s.size() - 1 - i)*(s[i] - '0');

        return num;
    };



    int N;
    cin >> N;
    vector<string> strvec(N);
    for (int i = 0; i < N; i++)
        cin >> strvec[i];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < strvec[i].size(); j++)
        {
            if (strvec[i][j] == ',')
                strvec[i].replace(j, 1, "");
        }
    }
    int res = 0;
    for (int i = 0; i < N; i++)
    {
        int mmax = 0;
        string temp = strvec[i];
        for (int j = 0; j < temp.size(); j++)
        {
            mmax = max(mmax, strToNum(temp));
            temp = temp.substr(1) + temp.substr(0, 1);
        }
        res += mmax;
    }
    cout << res;

	return 0;
}
