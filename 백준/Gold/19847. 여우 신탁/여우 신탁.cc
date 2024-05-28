#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

int N, max;
int dp[1000001];
int total;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int tmp;
        std::cin >> tmp;
        if (i == 1)
        {
            max = tmp;
            total = tmp;
            for (int j = 0; j < max; j++)
                dp[j] = 1;
        }
        else
        {
            if (tmp < max)
            {
                for (int j = tmp; j < max; j++)
                {
                    dp[j % tmp] += dp[j];
                    dp[j] = 0;
                }
                max = tmp;
            }
        }
    }
    double ans = 0;
    for (int i = 0; i < max; i++)
        ans += i * dp[i] / (double)total;
    std::cout.precision(10);
    std::cout << ans << '\n';
}