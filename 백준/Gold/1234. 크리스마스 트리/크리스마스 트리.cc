#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

typedef long long ll;
int N, R, G, B;
ll dp[11][56][56][56];
int fact[11];

int get_fact(int n)
{
    if (n == 0)
        return 1;
    if (fact[n] != 0)
        return fact[n];
    return fact[n] = n * get_fact(n - 1);
}

int num_case(int facto, int r, int g, int b)
{
    return facto / (get_fact(r) * get_fact(g) * get_fact(b));
}

ll dfs(int level, int r, int g, int b)
{
    if (level > N)
        return 1;
    ll &ret = dp[level][r][g][b];
    if (ret != -1)
        return ret;
    ret = 0;
    if (R - r >= level)
        ret += dfs(level + 1, r + level, g, b);
    if (G - g >= level)
        ret += dfs(level + 1, r, g + level, b);
    if (B - b >= level)
        ret += dfs(level + 1, r, g, b + level);
    if (level % 2 == 0)
    {
        int half = level / 2;
        if (R - r >= half && G - g >= half)
            ret += (num_case(get_fact(level), half, half, 0) * dfs(level + 1, r + half, g + half, b));
        if (R - r >= half && B - b >= half)
            ret += (num_case(get_fact(level), half, 0, half) * dfs(level + 1, r + half, g, b + half));
        if (G - g >= half && B - b >= half)
            ret += (num_case(get_fact(level), 0, half, half) * dfs(level + 1, r, g + half, b + half));
    }
    if (level % 3 == 0)
    {
        int third = level / 3;
        if (R - r >= third && G - g >= third && B - b >= third)
            ret += (num_case(get_fact(level), third, third, third) * dfs(level + 1, r + third, g + third, b + third));
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> R >> G >> B;
    memset(dp, -1, sizeof(dp));
    std::cout << dfs(1, 0, 0, 0) << '\n';
}