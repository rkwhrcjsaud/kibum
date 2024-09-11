#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;
vector<int> v[102];
vector<pair<int, int> > targetLim;
vector<int> cnt;
int mod[102];
vector<int> order;

int isTarget(vector<int> &target)
{
    for (int i = 1; i <= target.size(); i++)
    {
        int minLim = (target[i - 1] - 1) / 3 + 1;
        if (target[i - 1] == 0) minLim = 0;
        if (cnt[i] < minLim)
            return 0;
    }
    return 1;
}

int dfs(int node)
{
    if (v[node].empty())
        return node;
    int ret = dfs(v[node][mod[node]]);
    mod[node]++;
    mod[node] %= v[node].size();
    return ret;
}

int calcMinLim(int num, int m)
{
    if (num - m == 0)
        return 0;
    return (num - 1 - m) / 3 + 1;
}

vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    vector<int> answer;
    for (int i = 0; i < edges.size(); i++)
        v[edges[i][0]].push_back(edges[i][1]);
    for (int i = 1; i <= target.size(); i++)
        sort(v[i].begin(), v[i].end());
    memset(mod, 0, sizeof(mod));
    cnt.resize(target.size() + 1, 0);
    while (1)
    {
        int leef = dfs(1);
        cnt[leef]++;
        order.push_back(leef);
        if (cnt[leef] > target[leef - 1])
            return vector<int>(1, -1);
        if (isTarget(target))
            break ;
    }
    for (int i = 0; i < order.size(); i++)
    {
        if (calcMinLim(target[order[i] - 1], 1) <= cnt[order[i]] - 1 && cnt[order[i]] - 1 <= target[order[i] - 1] - 1)
        {
            answer.push_back(1);
            cnt[order[i]]--;
            target[order[i] - 1]--;
        }
        else if (calcMinLim(target[order[i] - 1], 2) <= cnt[order[i]] - 1 && cnt[order[i]] - 1 <= target[order[i] - 1] - 2)
        {
            answer.push_back(2);
            cnt[order[i]]--;
            target[order[i] - 1] -= 2;
        }
        else if (calcMinLim(target[order[i] - 1], 3) <= cnt[order[i]] - 1 && cnt[order[i]] - 1 <= target[order[i] - 1] - 3)
        {
            answer.push_back(3);
            cnt[order[i]]--;
            target[order[i] - 1] -= 3;
        }
    }
    return answer;
}