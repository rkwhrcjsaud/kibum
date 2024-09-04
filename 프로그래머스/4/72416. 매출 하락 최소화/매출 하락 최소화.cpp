#include <string>
#include <vector>
#include <string.h>
#include <iostream>

using namespace std;
bool visited[300001];
int dp[300001][2];
vector<int> v[300001];
int sale[300001];
const int INF = 2147483647;

int dfs(int node, int prev)
{
    int &ret = dp[node][prev];
    if (ret != -1)
        return ret;
    if (v[node].empty())
        return ret = (prev ? sale[node] : 0);
    ret = prev ? sale[node] : 0;
    int tmp = INF;
    for (int i = 0; i < v[node].size(); i++)
    {
        int next = v[node][i];
        if (prev) // 현재 node가 참여한 경우
            ret += min(dfs(next, 0), dfs(next, 1));
        else // 현재 node가 참여하지 않은 경우
        {
            ret += min(dfs(next, 0), dfs(next, 1));
            tmp = min(tmp, dfs(next, 1) - dfs(next, 0));
        }
    }
    if (!prev && tmp > 0)
        return ret += tmp;
    return ret;
}

int solution(vector<int> sales, vector<vector<int>> links) {
    int answer = 0;
    for (int i = 0; i < sales.size(); i++)
        sale[i + 1] = sales[i];
    memset(visited, false, sizeof(visited));
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < links.size(); i++)
        v[links[i][0]].push_back(links[i][1]);
    answer = min(dfs(1, 0), dfs(1, 1));
    return answer;
}