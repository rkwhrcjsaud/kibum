#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

int N, M;
std::string dp[1000001];
int arr[3] = {3, 5, 8};

std::string cmp(const std::string &a, const std::string &b)
{
    if (b[0] == '-')
        return a;
    if (a == "-1")
        return b;
    if (a.length() != b.length())
        return a.length() < b.length() ? a : b;
    return a < b ? a : b;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    dp[0] = "";
    for (int i = 1; i <= 20; i++)
    {
        dp[i] = "-1";
        for (int j = 0; j < 3; j++)
        {
            if (i < arr[j])
                continue;
            dp[i] = cmp(dp[i], dp[i - arr[j]] + std::string(1, '0' + arr[j]));
        }
    }
    while (N--)
    {
        std::cin >> M;
        int cnt = 0;
        while (M > 20)
        {
            M -= 8;
            cnt++;
        }
        std::cout << dp[M] << std::string(cnt, '8') << '\n';
    }
}