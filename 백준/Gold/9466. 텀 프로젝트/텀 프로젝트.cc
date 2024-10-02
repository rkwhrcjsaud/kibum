#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int T, N;

int dfs(int cur, vector<int> &v, vector<bool> &visited, vector<bool> &finished)
{
    visited[cur] = true;
    int next = v[cur];
    int ret = 0;
    if (!visited[next])
        ret = dfs(next, v, visited, finished);
    else if (!finished[next])
    {
        ret = 1;
        for (int i = next; i != cur; i = v[i])
            ret++;
    }
    finished[cur] = true;
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> T;
    while (T--)
    {
        cin >> N;
        vector<int> v(N + 1);
        for (int i = 1; i <= N; i++)
            cin >> v[i];
        vector<bool> visited(N + 1, false);
        vector<bool> finished(N + 1, false);
        int ans = 0;
        for (int i = 1; i <= N; i++)
        {
            if (!visited[i])
                ans += dfs(i, v, visited, finished);
        }
        cout << N - ans << '\n';
    }
}