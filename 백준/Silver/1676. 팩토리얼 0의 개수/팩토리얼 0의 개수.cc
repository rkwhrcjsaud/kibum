#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int dp[501];
int arr[501];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= N; i++)
    {
        if (i % 5 == 0)
            dp[i] = dp[i / 5] + 1;
        arr[i] = arr[i - 1] + dp[i];
    }
    cout << arr[N] << '\n';
}