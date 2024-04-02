#include <iostream>
#include <queue>
#include <vector>

int N;
int light;
int dp[1 << 20];
std::queue< int > q;
std::vector<int> v;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    std::fill(&dp[0], &dp[(1 << 20)], -1);
    for (int i = 0; i < N; i++)
    {
        int tmp;
        std::cin >> tmp;
        if (tmp)
            light |= (1 << i);
    }
    for (int i = 0; i < N; i++)
    {
        int n, switchs = 0;
        std::cin >> n;
        for (int j = 0; j < n; j++)
        {
            int tmp;
            std::cin >> tmp;
            switchs |= (1 << (tmp - 1));
        }
        switchs |= (1 << i);
        v.push_back(switchs);
    }
    dp[light] = 0;
    q.push(light);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (cur == (1 << N) - 1)
            break ;
        for (int i = 0; i < N; i++)
        {
            if (cur & (1 << i))
                continue ;
            int next = cur ^ v[i];
            if (dp[next] != -1)
                continue ;
            dp[next] = dp[cur] + 1;
            q.push(next);
        }
    }
    std::cout << dp[(1 << N) - 1] << '\n';
}