#include <iostream>
#include <queue>

int T;
int d[5] = {60, 10, -10, 1, -1};
std::string dp[70];
std::queue<int> q;

bool compare(const std::string &a, const std::string &b)
{
    int alen = 0, blen = 0;
    for (int i = 0; i < 5; i++)
    {
        alen += a[i] - '0';
        blen += b[i] - '0';
    }
    if (alen != blen)
        return alen < blen;
    return a < b;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    for (int i = 0; i <= 60; i++)
        dp[i] = "99999";
    dp[0] = "00000";
    q.push(0);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 4; i >= 0; i--)
        {
            int next = cur + d[i];
            if (next < 0 || next > 60)
                continue ;
            std::string tmp = dp[cur];
            tmp[i]++;
            if (compare(tmp, dp[next]))
            {
                dp[next] = tmp;
                q.push(next);
            }
        }
    }
    std::cin >> T;
    while (T--)
    {
        int N;
        std::cin >> N;
        int ans[5] = {0, };
        ans[0] += N / 60;
        N %= 60;
        for (int i = 0; i < 5; i++)
        {
            ans[i] += dp[N][i] - '0';
            std::cout << ans[i] << ' ';
        }
        std::cout << '\n';
    }
}
