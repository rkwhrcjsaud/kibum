#include <string>
#include <vector>

using namespace std;
vector<int> v[18];
int parent[18];
bool visited[1 << 17];
int ans = 0;
int N;

void sol(int bit, int sheep, int wolf, vector<int> &info)
{
    visited[bit] = true;
    ans = max(ans, sheep);
    for (int i = 0; i < N; i++)
    {
        if (!(bit & (1 << i)))
            continue ;
        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j] == parent[i])
                continue ;
            if (bit & (1 << v[i][j]))
                continue ;
            int next = bit | (1 << v[i][j]);
            if (visited[next])
                continue ;
            if (sheep + !info[v[i][j]] <= wolf + info[v[i][j]])
                continue ;
            sol(next, sheep + !info[v[i][j]], wolf + info[v[i][j]], info);
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    parent[0] = -1;
    N = info.size();
    for (int i = 0; i < edges.size(); i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];
        v[a].push_back(b);
        v[b].push_back(a);
        parent[b] = a;
    }
    sol(1, 1, 0, info);
    return ans;
}