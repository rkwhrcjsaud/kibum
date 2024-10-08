#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int N;
vector<pair<int, int> > v;

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++)
        cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    vector<int> lis;
    vector<int> idx;
    lis.push_back(v[0].second);
    idx.push_back(0);
    for (int i = 1; i < v.size(); i++)
    {
        int next = v[i].second;
        if (lis.back() < next)
        {
            lis.push_back(next);
            idx.push_back(lis.size() - 1);
        }
        else
        {
            vector<int>::iterator it = lower_bound(lis.begin(), lis.end(), next);
            *it = next;
            idx.push_back(it - lis.begin());
        }
    }
    cout << N - lis.size() << '\n';
    int now = lis.size() - 1;
    vector<int> ans;
    for (int i = idx.size() - 1; i >= 0; i--)
    {
        if (idx[i] == now)
        {
            now--;
            continue ;
        }
        ans.push_back(v[i].first);
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << '\n';
}