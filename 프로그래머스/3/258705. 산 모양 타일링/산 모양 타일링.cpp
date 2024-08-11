#include <string>
#include <vector>

using namespace std;
const int MOD = 10007;
int dp[100001][4];
// j = 0 -> 모든 타일이 삼각형
// j = 1 -> 왼쪽타일이 마름모
// j = 2 -> 위 타일이 마름로
// j = 3 -> 오른쪽타일이 마름모

int solution(int n, vector<int> tops) {
    int answer = 0;
    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[0][2] = tops[0];
    dp[0][3] = 1;
    for (int i = 1; i < tops.size(); i++)
    {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
        dp[i][2] = tops[i] ? dp[i][0] : 0;
        dp[i][3] = dp[i][0];
        dp[i][0] %= MOD;
        dp[i][1] %= MOD;
        dp[i][2] %= MOD;
        dp[i][3] %= MOD;
    }
    for (int i = 0; i < 4; i++)
    {
        answer += dp[tops.size() - 1][i];
        answer %= MOD;
    }
    return answer;
}