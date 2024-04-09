#include <iostream>
#include <vector>

int N;
int arr[201];
int dp[201];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> arr[i];
    for (int i = 0; i < N; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
                dp[i] = std::max(dp[i], dp[j] + 1);
        }
    }
    int max = 0;
    for (int i = 0; i < N; i++)
        max = std::max(max, dp[i]);
    std::cout << N - max << '\n';
}