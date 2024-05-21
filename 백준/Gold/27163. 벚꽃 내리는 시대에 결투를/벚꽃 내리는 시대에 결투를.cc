#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <sstream>
#include <map>

int N, A, L;
int lifeAtk[5001];
int auraAtk[5001];
typedef long long ll;
ll dp[5001][5001];
char prev[5001][5001];
std::string ans;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> A >> L;
    for (int i = 0; i < N; i++)
        std::cin >> auraAtk[i] >> lifeAtk[i];
    memset(dp, -1, sizeof(dp));
    dp[0][L] = A;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= L; j++)
        {
            if (dp[i][j] == -1)
                continue;
            if (auraAtk[i] != -1 && lifeAtk[i] != -1)
            {
                if (dp[i][j] >= auraAtk[i] && dp[i + 1][j] < dp[i][j] - auraAtk[i])
                {
                    dp[i + 1][j] = dp[i][j] - auraAtk[i];
                    prev[i + 1][j] = 'A';
                }
                if (j > lifeAtk[i] && dp[i + 1][j - lifeAtk[i]] < dp[i][j])
                {
                    dp[i + 1][j - lifeAtk[i]] = dp[i][j];
                    prev[i + 1][j - lifeAtk[i]] = 'L';
                }
            }
            else if (auraAtk[i] != -1)
            {
                int tmp = std::max(0ll, dp[i][j] - auraAtk[i]);
                if (dp[i + 1][j] < tmp)
                {
                    dp[i + 1][j] = tmp;
                    prev[i + 1][j] = 'A';
                }
            }
            else if (lifeAtk[i] != -1)
            {
                if (j > lifeAtk[i] && dp[i + 1][j - lifeAtk[i]] < dp[i][j])
                {
                    dp[i + 1][j - lifeAtk[i]] = dp[i][j];
                    prev[i + 1][j - lifeAtk[i]] = 'L';
                }
            }
        }
    }
    for (int i = 1; i <= L; i++)
    {
        if (dp[N][i] != -1)
        {
            std::cout << "YES\n";
            int life = i;
            for (int j = N; j > 0; j--)
            {
                if (prev[j][life] == 'A')
                    ans += 'A';
                else
                {
                    ans += 'L';
                    life += lifeAtk[j - 1];
                }
            }
            std::reverse(ans.begin(), ans.end());
            std::cout << ans << '\n';
            return 0;
        }
    }
    std::cout << "NO\n";
}