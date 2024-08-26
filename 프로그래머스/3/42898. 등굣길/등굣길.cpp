#include <string>
#include <vector>

using namespace std;
int dp[101][101] = {0, };
bool pud[101][101] = {false, };
const int MOD = 1e9 + 7;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    dp[1][1] = 1;
    for (int i = 0; i < puddles.size(); i++)
        pud[puddles[i][1]][puddles[i][0]] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1)
                continue ;
            if (pud[i - 1][j] && pud[i][j - 1])
                continue ;
            else if (pud[i - 1][j])
                dp[i][j] = dp[i][j - 1];
            else if (pud[i][j - 1])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            dp[i][j] %= MOD;
        }
    }
    return answer = dp[n][m];
}