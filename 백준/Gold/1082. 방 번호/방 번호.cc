#include <iostream>

int N, M;
int arr[10];
std::string dp[60];

std::string compare(const std::string &a, const std::string &b)
{
    if (a.size() < b.size())
        return b;
    else if (a.size() > b.size())
        return a;
    else
    {
        if (a < b)
            return b;
        else
            return a;
    }

}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> arr[i];
    std::cin >> M;
    for (int i = 0; i < N; i++)
        dp[arr[i]] = std::to_string(i);
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (dp[j] == "0")
                dp[i] = compare(dp[i], dp[i - j]);
            else
                dp[i] = compare(dp[i], dp[j] + dp[i - j]);
        }
    }
    std::cout << dp[M] << '\n';
}