#include <iostream>
#include <string>
#include <string.h>
using namespace std;

bool dp[2501][2501];

int solution(string s)
{
    int answer=1;
    int n = s.size();
    memset(dp, false, sizeof(dp));
    for (int i = 0; i < n; i++)
        dp[i][i] = true;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            dp[i][i + 1] = true;
            answer = 2;
        }
    }
    for (int k = 2; k < n; k++)
    {
        for (int i = 0; i < n - k; i++)
        {
            if (s[i] == s[i + k] && dp[i + 1][i + k - 1])
            {
                dp[i][i + k] = true;
                answer = k + 1;
            }
        }
    }
    return answer;
}