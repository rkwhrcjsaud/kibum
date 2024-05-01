#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

int N;
int arr[3001];
int pos[1000001];
long long dp[3001][3001];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    std::fill(pos, pos + 1000001, -1);
    for (int i = 0; i < N; i++)
    {
        int tmp;
        std::cin >> tmp;
        arr[i] = tmp;
        pos[tmp] = i;
    }
    long long ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int next = 2 * arr[i] - arr[j];
            if (next > 0 && pos[next] != -1)
            {
                dp[i][j] = dp[pos[next]][i] + arr[j];
                ans = std::max(ans, dp[i][j]);
            }
            else
                dp[i][j] = arr[i] + arr[j];
        }
    }
    std::cout << ans << '\n';
}
