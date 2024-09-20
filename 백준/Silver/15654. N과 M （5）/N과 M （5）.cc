#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

void dfs(int bit, int cnt, vector<int> &v, vector<int> ret)
{
    if (cnt == M)
    {
        for (int i = 0; i < ret.size(); i++)
            cout << ret[i] << ' ';
        cout << '\n';
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
}