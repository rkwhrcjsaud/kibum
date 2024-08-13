#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;
ll dp[100001];
ll dp2[100001];
const int MOD = 1e9 + 7;

int solution(int n) {
    int answer = 0;
    for (int i = 0; i <= n; i++)
    {
        dp[i] = 0;
        dp2[i] = 0;
    }
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 10;
    for (int i = 4; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] * 2 + dp[i - 3] * 5;
        dp[i] %= MOD;
        dp2[i] = dp2[i - 3] + dp[i - 4] * 2;
        if (i > 4)
            dp2[i] += dp[i - 5] * 2;
        if (i > 5)
            dp2[i] += dp[i - 6] * 4;
        dp2[i] %= MOD;
        dp[i] += dp2[i];
        dp[i] %= MOD;
    }
    answer = dp[n];
    return answer;
}