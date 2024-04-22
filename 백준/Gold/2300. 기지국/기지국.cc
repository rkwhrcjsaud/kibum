#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::pair< int, int > arr[10001];
int dp[10001];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 1; i <= N; i++)
        std::cin >> arr[i].first >> arr[i].second;
    std::sort(arr + 1, arr + N + 1);
    for (int i = 1; i <= N; i++)
    {
        int maxHeight = 0;
        dp[i] = 1e9;
        for (int j = i; j >= 1; j--)
        {
            maxHeight = std::max(maxHeight, std::abs(arr[j].second));
            dp[i] = std::min(dp[i], dp[j - 1] + std::max(2 * maxHeight, arr[i].first - arr[j].first));
        }
    }
    std::cout << dp[N] << '\n';
}