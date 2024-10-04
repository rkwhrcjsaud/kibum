#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int N;
vector<int> v;
int T;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N;
    v.resize(N);
    vector<vector<bool> > dp(N, vector<bool>(N, false));
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
        dp[i][i] = true;
    }
    for (int i = 0; i < N - 1; i++)
    {
        if (v[i] == v[i + 1])
            dp[i][i + 1] = true;
    }
    for (int i = 2; i < N; i++)
    {
        for (int j = 0; j < N - i; j++)
        {
            if (v[j] == v[j + i] && dp[j + 1][j + i - 1])
                dp[j][j + i] = true;
        }
    }
    cin >> T;
    while (T--)
    {
        int a, b;
        cin >> a >> b;
        cout << dp[a - 1][b - 1] << '\n';
    }
}