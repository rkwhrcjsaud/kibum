#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

int N;
int dp[1001][3][3][2];
// dp[i][j][k][p] = i번째 노드에서 이전노드의 선인장 높이가 j이고, 
// 그 이전노드의 선인장 높이가 k일 때 가능한 맵의 개수
// p는 지나온 노드 중 높이가 2인 선인장의 유무
const int MOD = 1e9 + 7;

int solve(int idx, int prev1, int prev2, bool flag)
{
    if (idx == N)
        return flag;
    int &ret = dp[idx][prev1][prev2][flag];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int i = 0; i < 3; i++)
    {
        if ((prev1 && prev2 && i) || (prev1 + i >= 4))
            continue;
        ret += solve(idx + 1, i, prev1, flag || i == 2);
        ret %= MOD;
    }
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    memset(dp, -1, sizeof(dp));
    std::cout << solve(1, 0, 0, false) << '\n';
}
