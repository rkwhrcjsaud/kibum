#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;
vector<int> v;
vector<vector<int> > ans;

void sol(int idx, int cnt, vector<int> &ret)
{
    if (cnt == M)
    {
        ans.push_back(ret);
        return;
    }
    for (int i = idx; i < v.size(); i++)
    {
        ret.push_back(v[i]);
        sol(i, cnt + 1, ret);
        ret.pop_back();
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N >> M;
    v.resize(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    vector<int> ret;
    sol(0, 0, ret);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << ' ';
        cout << '\n';
    }
}