#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

vector<int> v[1001];
bool visited[1001] = {false, };

void dfs(int node)
{
    visited[node] = true;
    for (int i = 0; i < v[node].size(); i++)
    {
        if (!visited[v[node][i]])
            dfs(v[node][i]);
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt << '\n';
}