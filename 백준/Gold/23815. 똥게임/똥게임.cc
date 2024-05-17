#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>

int N;
std::vector< std::pair<int, int> > v[2];
int dp[100001][2][2];
char arr[4] = {'+', '-', '*', '/'};

int trans(int num, std::pair<int, int> p)
{
    switch (p.first)
    {
    case 0:
        return num + p.second;
    case 1:
        return num - p.second;
    case 2:
        return num * p.second;
    case 3:
        return num / p.second;
    }
    return -1;
}

std::pair<int ,int> save(std::string str)
{
    char op;
    int num;
    std::stringstream ss(str);
    ss >> op >> num;
    for (int j = 0; j < 4; j++)
    {
        if (op == arr[j])
            return std::make_pair(j, num);
    }
    return std::make_pair(-1, -1);
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::string str1, str2;
        std::cin >> str1 >> str2;
        std::pair<int, int> p1 = save(str1);
        std::pair<int, int> p2 = save(str2);
        v[0].push_back(p1);
        v[1].push_back(p2);
    }
    dp[0][0][1] = trans(1, v[0][0]);
    dp[0][1][1] = trans(1, v[1][0]);
    dp[0][0][0] = 1;
    dp[0][1][0] = 1;
    for (int i = 1; i < N; i++)
    {
        if (dp[i - 1][0][0] > 0)
        {
            dp[i][0][0] = std::max(dp[i][0][0], trans(dp[i - 1][0][0], v[0][i]));
            dp[i][1][0] = std::max(dp[i][1][0], trans(dp[i - 1][0][0], v[1][i]));
        }
        if (dp[i - 1][1][0] > 0)
        {
            dp[i][0][0] = std::max(dp[i][0][0], trans(dp[i - 1][1][0], v[0][i]));
            dp[i][1][0] = std::max(dp[i][1][0], trans(dp[i - 1][1][0], v[1][i]));
        }
        if (dp[i - 1][0][1] > 0)
        {
            dp[i][0][1] = std::max(dp[i][0][1], trans(dp[i - 1][0][1], v[0][i]));
            dp[i][1][1] = std::max(dp[i][1][1], trans(dp[i - 1][0][1], v[1][i]));
            dp[i][0][0] = std::max(dp[i][0][0], dp[i - 1][0][1]);
            dp[i][1][0] = std::max(dp[i][1][0], dp[i - 1][0][1]);
        }
        if (dp[i - 1][1][1] > 0)
        {
            dp[i][0][1] = std::max(dp[i][0][1], trans(dp[i - 1][1][1], v[0][i]));
            dp[i][1][1] = std::max(dp[i][1][1], trans(dp[i - 1][1][1], v[1][i]));
            dp[i][0][0] = std::max(dp[i][0][0], dp[i - 1][1][1]);
            dp[i][1][0] = std::max(dp[i][1][0], dp[i - 1][1][1]);
        }
    }
    int ans = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            ans = std::max(ans, dp[N - 1][i][j]);
        }
    }
    if (ans <= 0)
    {
        std::cout << "ddong game\n";
        return 0;
    }
    std::cout << ans << '\n';
}