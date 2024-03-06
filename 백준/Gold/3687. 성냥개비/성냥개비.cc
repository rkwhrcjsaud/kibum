#include <iostream>
#include <vector>

int T;
std::string dp[101];

std::string compare(const std::string &a, const std::string &b)
{
    if (a.size() < b.size())
        return a;
    else if (a.size() > b.size())
        return b;
    else
    {
        if (a < b)
            return a;
        else
            return b;
    }

}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    dp[2] = "1";
    dp[3] = "7";
    dp[4] = "4";
    dp[5] = "2";
    dp[6] = "6";
    dp[7] = "8";
    for (int i = 8; i <= 100; i++)
    {
        dp[i] = dp[i - 2] + dp[2];
        for (int j = 2; j < 8; j++)
        {
            if (i - j < 2)
                continue ;
            dp[i] = compare(dp[i], dp[i - j] + dp[j]);
            if (j == 6)
                dp[i] = compare(dp[i], dp[i - j] + "0");
        }
    }
    while (T--)
    {
        int N;
        std::cin >> N;
        std::cout << dp[N] << ' ';
        std::vector<int> v;
        if (N % 2 == 1)
        {
            std::cout << 7;
            N -= 3;
        }
        while (N > 0)
        {
            std::cout << 1;
            N -= 2;
        }
        std::cout << '\n';
    }
}