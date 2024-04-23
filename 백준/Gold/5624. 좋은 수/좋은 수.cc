#include <iostream>
#include <queue>
#include <vector>

int N;
int arr[5001];
int dp[400001];
const int mid = 200000;
int result = 0;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for (int i = 1; i <= N; i++)
        std::cin >> arr[i];
    for (int i = 1; i <= N; i++)
    {
        int cur = arr[i];
        for (int j = 1; j < i; j++)
        {
            if (dp[mid + cur - arr[j]])
            {
                result++;
                break ;
            }
        }
        for (int j = 1; j <= i; j++)
            dp[mid + cur + arr[j]] = 1;
    }
    std::cout << result << '\n';
}