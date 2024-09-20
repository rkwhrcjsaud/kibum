#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int> > ans;

void dfs(int bit, int cnt, vector<int> &v, vector<int> ret)
{
    if (cnt == M)
    {
        ans.push_back(ret);
        return ;
    }
    for (int i = 0; i < N; i++)
    {
        if (bit & (1 << i))
            continue ;
        ret.push_back(v[i]);
        dfs(bit | (1 << i), cnt + 1, v, ret);
        ret.pop_back();
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    std::vector<int> v(N, 0);
    for (int i = 0; i < N; i++)
        std::cin >> v[i];
    sort(v.begin(), v.end());
    dfs(0, 0, v, vector<int>());
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << ' ';
        cout << '\n';
    }
}