#include <string>
#include <vector>
#include <iostream>
#include <string.h>

using namespace std;
const int MOD = 1e7 + 19;
int comb[301][301];
typedef long long ll;

int solution(vector<vector<int>> a) {
    int answer = -1;
    int col = a[0].size();
    int row = a.size();
    memset(comb, 0, sizeof(comb));
    comb[0][0] = 1;
    for (int i = 1; i <= row; i++)
    {
        comb[i][0] = 1;
        for (int j = 1; j <= row; j++)
        {
            comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
            comb[i][j] %= MOD;
        }
    }
    vector<int> cnt(col + 1, 0);
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (a[i][j])
                cnt[j]++;
    vector<vector<int>> dp(col + 2, vector<int>(row + 1, 0));
    dp[1][row - cnt[0]] = comb[row][row - cnt[0]];
    for (int i = 1; i < col; i++)
    {
        int currCnt = cnt[i];
        for (int j = 0; j <= row; j++)
        {
            if (dp[i][j] == 0) continue ;
            for (int k = 0; k <= currCnt; k++)
            {
                if (j < k) continue ;
                int tmp = j + currCnt - 2 * k;
                if (tmp > row) continue ;
                ll ret = ((ll)comb[j][k] * (ll)comb[row - j][currCnt - k]) % MOD;
                dp[i + 1][tmp] += ((ll)dp[i][j] * ret) % MOD;
                dp[i + 1][tmp] %= MOD;
            }
        }
    }
    answer = dp[col][row];
    return answer;
}