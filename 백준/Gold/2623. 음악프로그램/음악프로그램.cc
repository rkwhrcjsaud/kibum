#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int N, M;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N >> M;
    vector<int> indegree(N + 1, 0);
    vector<vector<int> > v(N + 1);
    for (int i = 0; i < M; i++)
    {
        int K;
        cin >> K;
        vector<int> tmp(K);
        for (int j = 0; j < K; j++)
        {
            cin >> tmp[j];
            if (j > 0)
            {
                v[tmp[j - 1]].push_back(tmp[j]);
                indegree[tmp[j]]++;
            }
        }
    }
    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> ans;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        ans.push_back(cur);
        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i];
            indegree[next]--;
            if (indegree[next] == 0)
                q.push(next);
        }
    }
    if (ans.size() != N)
        cout << "0\n";
    else
    {
        for (int i = 0; i < N; i++)
            cout << ans[i] << '\n';
    }
}