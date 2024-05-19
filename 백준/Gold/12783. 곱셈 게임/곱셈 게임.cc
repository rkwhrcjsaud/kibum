#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>

int T, N, M;
int bit;
int dp[1000001];
int cache[1000001];
const int INF = 1e9;

int solve(int num)
{
    int &ret = dp[num];
    if (ret != -1)
        return ret;
    ret = 0;
    if ((bit & cache[num]) == cache[num])
        return ret;
    ret = 1e9;
    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
            ret = std::min(ret, solve(i) + solve(num / i) + 1);
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    for (int i = 1; i <= 1000000; i++)
    {
        std::string str = std::to_string(i);
        for (int j = 0; j < str.size(); j++)
            cache[i] |= (1 << (str[j] - '0'));
    }
    std::cin >> T;
    while (T--)
    {
        std::cin >> N;
        memset(dp, -1, sizeof(dp));
        bit = 0;
        for (int i = 0; i < N; i++)
        {
            int num;
            std::cin >> num;
            bit |= (1 << num);
        }
        std::cin >> M;
        for (int i = 0; i < M; i++)
        {
            int num;
            std::cin >> num;
            int ans = solve(num);
            if (ans == 1e9)
                std::cout << "-1\n";
            else
                std::cout << ans << '\n';
        }
    }
}