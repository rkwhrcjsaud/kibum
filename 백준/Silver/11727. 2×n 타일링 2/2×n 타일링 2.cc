#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int N;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N;
    vector<int> dp(N + 1, 0);
    dp[1] = 1;
    dp[2] = 3;
    for (int i = 3; i <= N; i++)
        dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
    cout << dp[N] << '\n';
}