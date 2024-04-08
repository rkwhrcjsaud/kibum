#include <iostream>
#include <vector>

std::string str;
const int MOD = 1000000;
std::vector<int> dp;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> str;
    if (str[0] == '0')
    {
        std::cout << "0\n";
        return 0;
    }
    dp.resize(str.size() + 1);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= str.size(); i++)
    {
        if (str[i - 1] > '0')
            dp[i] = dp[i - 1] % MOD;
        int num = (str[i - 2] - '0') * 10 + (str[i - 1] - '0');
        if (num >= 10 && num <= 26)
            dp[i] = (dp[i] + dp[i - 2]) % MOD;
    }
    std::cout << dp[str.size()] << '\n';
}