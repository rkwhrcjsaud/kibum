#include <iostream>
#include <vector>
#include <algorithm>

int N, K;
std::vector<std::pair<int, int> > v;
std::vector<std::pair<int, int> > fs;
std::vector<int> s;
int dp[1 << 12][3000];

bool solve(int mask, int t)
{
    if (mask == (1 << K) - 1)
        return true;
    int a, b;
    for (int i = 0; i < v.size(); i++)
    {
        a = v[i].first;
        b = v[i].second;
        if (a <= t && t < b)
            t = b;
        else if (t < a)
            break ;
    }
    if (dp[mask][t] != -1)
        return dp[mask][t];
    for (int i = 0; i < K; i++)
    {
        if (mask & (1 << i))
            continue;
        int tmp = t;
        for (int j = 0; j < fs.size(); j++)
        {
            a = fs[j].first;
            b = fs[j].second;
            if (a <= tmp && tmp + s[i] <= b)
            {
                if (solve(mask | (1 << i), tmp + s[i]))
                    return dp[mask][t] = 1;
            }
            else if (tmp <= b)
            {
                if (j + 1 < fs.size())
                    tmp = fs[j + 1].first;
            }
        }
    }
    dp[mask][t] = 0;
    return false;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::fill(&dp[0][0], &dp[(1 << 12) - 1][3000], -1);
    std::cin >> N >> K;
    int tmp = 0;
    for (int i = 0; i < N; i++)
    {
        int s, e;
        std::cin >> s >> e;
        v.push_back(std::make_pair(s, e));
        if (s - tmp)
            fs.push_back(std::make_pair(tmp, s));
        tmp = e;
    }
    if (tmp < 1440)
        fs.push_back(std::make_pair(tmp, 1440));
    for (int i = 0; i < K; i++)
    {
        std::cin >> tmp;
        s.push_back(tmp);
    }
    std::cout << (solve(0, 0) ? "GOOD" : "BAD") << '\n';
}