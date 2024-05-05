#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int T, N;
std::string dp[1001];

std::string compare(std::string a, std::string b)
{
    if (a == "0")
        return b;
    if (a.length() != b.length())
        return a.length() < b.length() ? a : b;
    return a < b ? a : b;
}

void solve()
{
    dp[1] = "12";
    dp[2] = "34";
    dp[3] = "56";
    for (int i = 4; i <= 1000; i++)
    {
        dp[i] = "0";
        if (i % 2 == 0)
            dp[i] = compare(dp[i], "1" + dp[i / 2] + "2");
        if (i % 3 == 0)
            dp[i] = compare(dp[i], "3" + dp[i / 3] + "4");
        if (i % 5 == 0)
            dp[i] = compare(dp[i], "5" + dp[i / 5] + "6");
        for (int j = 1; j < i; j++)
            dp[i] = compare(dp[i], dp[j] + dp[i - j]);
    }
}

void print(std::string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
            std::cout << '(';
        else if (s[i] == '2')
            std::cout << ')';
        else if (s[i] == '3')
            std::cout << '{';
        else if (s[i] == '4')
            std::cout << '}';
        else if (s[i] == '5')
            std::cout << '[';
        else if (s[i] == '6')
            std::cout << ']';
        else
            std::cout << s[i];
    }
    std::cout << '\n';
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    solve();
    while (T--)
    {
        std::cin >> N;
        print(dp[N]);
    }
}
