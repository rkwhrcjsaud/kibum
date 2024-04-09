#include <iostream>
#include <queue>
#include <vector>

int S;
int dp[1050][1050];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> S;
    for (int i = 0; i <= S; i++)
    {
        for (int j = 0; j <= S; j++)
        {
            dp[i][j] = 1000000;
        }
    }
    dp[1][0] = 0;
    dp[1][1] = 1;
    std::queue<std::pair<int, int> > q;
    q.push(std::make_pair(1, 1));
    while (!q.empty())
    {
        int cur = q.front().first;
        int clip = q.front().second;
        q.pop();
        if (cur == S)
        {
            std::cout << dp[cur][clip] << '\n';
            return 0;
        }
        if (cur > 0 && cur < 1050)
        {
            if (dp[cur][cur] > dp[cur][clip] + 1)
            {
                dp[cur][cur] = dp[cur][clip] + 1;
                q.push(std::make_pair(cur, cur));
            }
            if (clip > 0 && cur + clip < 1050)
            {
                if (dp[cur + clip][clip] > dp[cur][clip] + 1)
                {
                    dp[cur + clip][clip] = dp[cur][clip] + 1;
                    q.push(std::make_pair(cur + clip, clip));
                }
            }
        }
        if (cur > 0)
        {
            if (dp[cur - 1][clip] > dp[cur][clip] + 1)
            {
                dp[cur - 1][clip] = dp[cur][clip] + 1;
                q.push(std::make_pair(cur - 1, clip));
            }
        }
    }
}