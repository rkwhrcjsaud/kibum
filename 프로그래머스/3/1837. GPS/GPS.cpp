#include <vector>
#include <string.h>
#include <iostream>
using namespace std;
vector<int> v[201];
int dp[201][101];
const int INF = 1000;

int sol(int node, int k, vector<int> &gps_log)
{
    if (k + 1 == gps_log.size())
    {
        if (gps_log[k] == node)
            return 0;
        return INF;
    }
    int &ret = dp[node][k];
    if (dp[node][k] != -1)
        return dp[node][k];
    ret = INF;
    ret = min(ret, sol(node, k + 1, gps_log) + (gps_log[k + 1] == node ? 0 : 1));
    for (int i = 0; i < v[node].size(); i++)
    {
        int next = v[node][i];
        ret = min(ret, sol(next, k + 1, gps_log) + (gps_log[k + 1] == next ? 0 : 1));
    }
    return ret;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = INF;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i <= n; i++)
        v[i].clear();
    for (int i = 0; i < m; i++)
    {
        v[edge_list[i][0]].push_back(edge_list[i][1]);
        v[edge_list[i][1]].push_back(edge_list[i][0]);
    }
    answer = sol(gps_log[0], 0, gps_log);
    if (answer >= INF)
        return -1;
    return answer;
}