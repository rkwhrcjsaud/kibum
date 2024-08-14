#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> v[100001];
int dp[100001][2]; // j = 0 > off, j = 1 > on
// dp[root][0] = dp[child][1] sum, dp[root][1] = min(dp[child][0], dp[child][1]) sum + 1

int sol(int node, int prev, bool prevLight)
{
    int &ret = dp[node][prevLight];
    if (ret != -1)
        return ret;
    if (prevLight)
        ret = 1;
    else
        ret = 0;
    for (int i = 0; i < v[node].size(); i++)
    {
        int next = v[node][i];
        if (next == prev)
            continue;
        if (prevLight)
            ret += min(sol(next, node, 1), sol(next, node, 0));
        else
            ret += sol(next, node, 1);
    }
    return ret;
}

int solution(int n, vector<vector<int>> lighthouse) {
    int answer = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int a = lighthouse[i][0];
        int b = lighthouse[i][1];
        v[a].push_back(b);
        v[b].push_back(a);
        dp[i + 1][0] = -1;
        dp[i + 1][1] = -1;
    }
    dp[n][0] = -1;
    dp[n][1] = -1;
    answer = min(sol(1, 0, 1), sol(1, 0, 0));
    return answer;
}