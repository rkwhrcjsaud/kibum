#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;
set<int> dp[9];

int append(int n, int cnt)
{
    int ret = n;
    while (cnt--)
        ret = ret * 10 + n;
    return ret;
}

int solution(int N, int number) {
    int answer = 0;
    for (int i = 1; i < 9; i++)
    {
        dp[i].insert(append(N, i - 1));
        for (int j = 1; j < i; j++)
        {
            int k = i - j;
            for (set<int>::iterator it = dp[j].begin(); it != dp[j].end(); it++)
            {
                for (set<int>::iterator itt = dp[k].begin(); itt != dp[k].end(); itt++)
                {
                    dp[i].insert(*it + *itt);
                    dp[i].insert(*it - *itt);
                    dp[i].insert(*it * *itt);
                    if (*itt != 0)
                        dp[i].insert(*it / *itt);
                }
            }
        }
        if (find(dp[i].begin(), dp[i].end(), number) != dp[i].end())
            return i;
    }
    return -1;
}